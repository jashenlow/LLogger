cmake_minimum_required(VERSION 3.15)
project(LLogger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  message(WARNING "CMAKE_BUILD_TYPE not specified. Setting to Release.")
endif()

# Set compiler flags
if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -march=native -std=c++17")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -march=native -Wno-deprecated")
  if(${CMAKE_BUILD_TYPE} MATCHES Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -funroll-loops")
  endif()
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
  if(MSVC)
    # add_compile_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP /std:c++17")
    if(${CMAKE_BUILD_TYPE} MATCHES Release)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GL /Ot")
    endif()
  elseif(MINGW)
    add_definitions(-DHAVE_GCC_DESTRUCTOR)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -march=native -Wno-deprecated -std=c++17")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -march=native -Wno-deprecated")
    if(${CMAKE_BUILD_TYPE} MATCHES Release)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto -funroll-loops")
    endif()
  endif()
endif()

# Set default library type
if(NOT LIBRARY_TYPE)
  set(LIBRARY_TYPE Static)
  message(WARNING "LIBRARY_TYPE not specified. Setting to Static.")
endif()

# Add library
if(LIBRARY_TYPE MATCHES Static)
  message(STATUS "Building ${PROJECT_NAME} as a static library.")
  add_library(llogger STATIC ${PROJECT_SOURCE_DIR}/src/llogger.cpp)
elseif(LIBRARY_TYPE MATCHES Shared)
  message(STATUS "Building ${PROJECT_NAME} as a shared library.")
  add_library(llogger SHARED ${PROJECT_SOURCE_DIR}/src/llogger.cpp)
endif()

# export library
set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(TARGETS llogger FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake)
export(PACKAGE llogger)

# Unit tests
if(BUILD_TESTING)
  find_package(GTest QUIET)

  if(NOT GTest_FOUND)
    message(STATUS "GoogleTest not found on the system. Fetching using 'FetchContent'")
    include(FetchContent)
    # set(BENCHMARK_ENABLE_TESTING OFF)

    FetchContent_Declare(googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG main)
  # FetchContent_Declare(googlebenchmark
  #   GIT_REPOSITORY https://github.com/google/benchmark.git
  #   GIT_TAG main)

    if(MSVC)
      # Prevent GoogleTest from overriding our compiler/linker options
      # when building with Visual Studio
      set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif()
    
    FetchContent_MakeAvailable(googletest)
  # FetchContent_MakeAvailable(googletest googlebenchmark)
  endif()

  include_directories(${PROJECT_SOURCE_DIR}/src)

  enable_testing()
  add_executable(llogger_test ${PROJECT_SOURCE_DIR}/test/test.cpp)
  target_link_libraries(llogger_test llogger GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(llogger_test)
endif()