#include <gtest/gtest.h>

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

#include "llogger.h"

#ifdef _MSVC
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define ConsoleHandle GetStdHandle(STD_OUTPUT_HANDLE)
#endif

using namespace llogger;

class LLoggerTest : public testing::Test {
 public:
  LLoggerTest() {}

  std::array<char, DATETIME_STR_LEN + 1> gen_datetime_str() {
    std::array<char, DATETIME_STR_LEN + 1> test_datetime = {'\0'};

    std::time_t test_timenow = std::time(nullptr);
    std::size_t test_time_len = std::strftime(
      test_datetime.data(),
      DATETIME_STR_LEN,
      "[%d-%m-%Y][%H:%M:%S]",
      std::localtime(&test_timenow));

    return test_datetime;
  }

  LLogger logger;

#ifdef _MSVC
  uint16_t console_attr_original = 0;

  int redirect_stdout_to_file(FILE** file) {
    int original_stdout = _dup(fileno(stdout));
    *file = freopen("output.out", "w", stdout);

    return original_stdout;
  }

  void restore_stdout_and_read_redirected_file(
    int original_stdout, std::string& output_line) {
    std::fflush(stdout);
    _dup2(original_stdout, fileno(stdout));
    _close(original_stdout);
    
    std::ifstream console_output_file("output.out");
    std::getline(console_output_file, output_line);
  
    if (console_output_file.is_open()) {
      console_output_file.close();
      std::remove("output.out");
    }
  }
#endif
};

// ---------------------------------------------

TEST_F(LLoggerTest, gen_color_code) {
#ifdef _GNU
  // Test color generation
  ColorTextType test_color = {'\0'};
  constexpr char test_fg_normal[] = "3";
  constexpr char test_fg_bold[] = "9";
  constexpr char test_bg_normal[] = "4";
  constexpr char test_bg_bold[] = "10";
  ColorTextType generated_color;

  for (char c_fg = ColorIndex::BLACK; c_fg <= ColorIndex::WHITE; c_fg++) {
    for (char c_bg = ColorIndex::BLACK; c_bg <= ColorIndex::WHITE; c_bg++) {
      // Foreground Normal, Background Normal
      snprintf(test_color.data(), test_color.size(), "\033[%s%c;%s%cm",
        test_fg_normal,
        c_fg,
        test_bg_normal,
        c_bg);

      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, false, false);

      printf("%sTEST_COLOR_FG(N)_BG(N)%s\t%sGEN_COLOR_FG(N)_BG(N)%s\n",
        test_color.data(),
        COLOR_RESET,
        generated_color.data(),
        COLOR_RESET);
      EXPECT_STREQ(test_color.data(), generated_color.data());

      // Foreground Normal, Background Bold
      snprintf(test_color.data(), test_color.size(), "\033[%s%c;%s%cm",
        test_fg_normal,
        c_fg,
        test_bg_bold,
        c_bg);

      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, false, true);

      printf("%sTEST_COLOR_FG(N)_BG(B)%s\t%sGEN_COLOR_FG(N)_BG(B)%s\n",
        test_color.data(),
        COLOR_RESET,
        generated_color.data(),
        COLOR_RESET);
      EXPECT_STREQ(test_color.data(), generated_color.data());

      // Foreground Bold, Background Normal
      snprintf(test_color.data(), test_color.size(), "\033[%s%c;%s%cm",
        test_fg_bold,
        c_fg,
        test_bg_normal,
        c_bg);

      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, true, false);

      printf("%sTEST_COLOR_FG(B)_BG(N)%s\t%sGEN_COLOR_FG(B)_BG(N)%s\n",
        test_color.data(),
        COLOR_RESET,
        generated_color.data(),
        COLOR_RESET);
      EXPECT_STREQ(test_color.data(), generated_color.data());

      // Foreground Bold, Background Bold
      snprintf(test_color.data(), test_color.size(), "\033[%s%c;%s%cm",
        test_fg_bold,
        c_fg,
        test_bg_bold,
        c_bg);

      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, true, true);

      printf("%sTEST_COLOR_FG(B)_BG(B)%s\t%sGEN_COLOR_FG(B)_BG(B)%s\n",
        test_color.data(),
        COLOR_RESET,
        generated_color.data(),
        COLOR_RESET);
      EXPECT_STREQ(test_color.data(), generated_color.data());
    }
  }
#elif defined(_MSVC)
  // Test color generation
  ColorTextType test_color = 0;
  constexpr uint16_t test_fg_bold = 0x0008;
  constexpr uint16_t test_bg_bold = test_fg_bold << 4;
  ColorTextType generated_color;

  // Store current console attributes
  CONSOLE_SCREEN_BUFFER_INFO console_buffer_info;
  GetConsoleScreenBufferInfo(ConsoleHandle, &console_buffer_info);
  console_attr_original = console_buffer_info.wAttributes;

  for (uint16_t c_fg = ColorIndex::BLACK; c_fg <= ColorIndex::WHITE; c_fg++) {
    for (uint16_t c_bg = ColorIndex::BLACK; c_bg <= ColorIndex::WHITE; c_bg++) {
      // Foreground Normal, Background Normal
      test_color = (c_bg << 4) | 0x0000 | c_fg | 0x0000;
      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, false, false);
      
      SetConsoleTextAttribute(ConsoleHandle, test_color);
      printf("TEST_COLOR_FG(N)_BG(N)\t");
      SetConsoleTextAttribute(ConsoleHandle, generated_color);
      printf("GEN_COLOR_FG(N)_BG(N)\n");
      SetConsoleTextAttribute(ConsoleHandle, console_attr_original);

      EXPECT_EQ(test_color, generated_color);

      // Foreground Normal, Background Bold
      test_color = (c_bg << 4) | test_bg_bold | c_fg | 0x0000;
      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, false, true);
      
      SetConsoleTextAttribute(ConsoleHandle, test_color);
      printf("TEST_COLOR_FG(N)_BG(B)\t");
      SetConsoleTextAttribute(ConsoleHandle, generated_color);
      printf("GEN_COLOR_FG(N)_BG(B)\n");
      SetConsoleTextAttribute(ConsoleHandle, console_attr_original);

      EXPECT_EQ(test_color, generated_color);

      // Foreground Bold, Background Normal
      test_color = (c_bg << 4) | 0x0000 | c_fg | test_fg_bold;
      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, true, false);
      
      SetConsoleTextAttribute(ConsoleHandle, test_color);
      printf("TEST_COLOR_FG(B)_BG(N)\t");
      SetConsoleTextAttribute(ConsoleHandle, generated_color);
      printf("GEN_COLOR_FG(B)_BG(N)\n");
      SetConsoleTextAttribute(ConsoleHandle, console_attr_original);

      EXPECT_EQ(test_color, generated_color);

      // Foreground Bold, Background Bold
      test_color = (c_bg << 4) | test_bg_bold | c_fg | test_fg_bold;
      generated_color =
        gen_color_code((ColorIndex)c_fg, (ColorIndex)c_bg, true, true);
      
      SetConsoleTextAttribute(ConsoleHandle, test_color);
      printf("TEST_COLOR_FG(B)_BG(B)\t");
      SetConsoleTextAttribute(ConsoleHandle, generated_color);
      printf("GEN_COLOR_FG(B)_BG(B)\n");
      SetConsoleTextAttribute(ConsoleHandle, console_attr_original);

      EXPECT_EQ(test_color, generated_color);
    }
  }
#endif
}

TEST_F(LLoggerTest, get_set_log_type) {
  // Normal inputs
  for (uint8_t t = LogType::LOG_CONSOLE; t <= LogType::LOG_CONSOLE_FILE; t++) {
    EXPECT_TRUE(logger.set_log_type((LogType)t));
    EXPECT_EQ(logger.get_log_type(), t);
  }

  // Out-of-bounds handling
  EXPECT_TRUE(logger.set_log_type(LogType::LOG_CONSOLE_FILE));
  EXPECT_FALSE(logger.set_log_type((LogType)(LogType::LOG_CONSOLE_FILE + 5)));
  EXPECT_EQ(logger.get_log_type(), LogType::LOG_CONSOLE_FILE);
}

TEST_F(LLoggerTest, get_set_log_level_color) {
  ColorTextType test_color =
    gen_color_code(ColorIndex::MAGENTA, ColorIndex::WHITE, true, false);

  for (uint8_t l = 0; l <= LogLevel::LOG_DEBUG; l++) {
    EXPECT_TRUE(
      logger.set_log_level_color(
        (LogLevel)l, ColorIndex::MAGENTA, ColorIndex::WHITE, true, false));

    ColorTextType color = logger.get_log_level_color((LogLevel)l);
    EXPECT_EQ(test_color, color);
  }

  // Out-of-bounds handling
  EXPECT_EQ(
    COLOR_TEXT_TYPE_INIT,
    logger.get_log_level_color((LogLevel)(LogLevel::LOG_DEBUG + 5)));

  EXPECT_FALSE(
    logger.set_log_level_color(
      (LogLevel)(LogLevel::LOG_DEBUG + 5),
      ColorIndex::GREEN,
      ColorIndex::BLACK,
      false,
      false));
#ifdef _GNU
  EXPECT_FALSE(
    logger.set_log_level_color(
      LogLevel::LOG_INFO, (ColorIndex)-20, ColorIndex::BLACK, false, false));
  EXPECT_FALSE(
    logger.set_log_level_color(
      LogLevel::LOG_INFO, ColorIndex::RED, (ColorIndex)-20, false, false));
#endif
  EXPECT_FALSE(
    logger.set_log_level_color(
      LogLevel::LOG_INFO, (ColorIndex)20, ColorIndex::BLACK, false, false));
  EXPECT_FALSE(
    logger.set_log_level_color(
      LogLevel::LOG_INFO, ColorIndex::RED, (ColorIndex)20, false, false));
}

TEST_F(LLoggerTest, log_line_console) {
  LogLevel test_log_level = LogLevel::LOG_WARN;
  LogBufferType test_log_buffer = {'\0'};

  logger.set_log_type(LogType::LOG_CONSOLE);

  std::array<char, DATETIME_STR_LEN + 1> test_datetime = gen_datetime_str();

  // Redirect stdout to a buffer first.
#ifdef _GNU
  char* print_buffer = nullptr;
  std::size_t s = 0;
  FILE* mem_stream = open_memstream(&print_buffer, &s);
  FILE* original_stdout = stdout;
  stdout = mem_stream;
#elif defined(_MSVC)
  FILE* file_ptr = nullptr;
  int original_stdout_fd = redirect_stdout_to_file(&file_ptr);
#endif

// Populate a formatted string to do a direct comparison.
#ifdef _GNU
  snprintf(test_log_buffer.data(),
    test_log_buffer.size(),
    "%s%s%s Test console output for LogType::%s.%s\n",
    logger.get_log_level_color(test_log_level).data(),
    test_datetime.data(),
    LOG_LEVEL_PREFIX[test_log_level],
    LOG_TYPE_STR[logger.get_log_type()],
    COLOR_RESET);
#elif defined(_MSVC)
  // Test console output only, since color is set separately.
  snprintf(test_log_buffer.data(),
    test_log_buffer.size(),
    "%s%s Test console output for LogType::%s.",
    test_datetime.data(),
    LOG_LEVEL_PREFIX[test_log_level],
    LOG_TYPE_STR[logger.get_log_type()]);
#endif

  // Call LLogger::log_line to capture its output.
  EXPECT_TRUE(
    logger.log_line(
      test_log_level,
      "Test console output for LogType::%s.",
      LOG_TYPE_STR[logger.get_log_type()]));

  // Restore stdout back to normal.
#ifdef _GNU
  fclose(mem_stream);
  stdout = original_stdout;
  std::string print_buffer_str(print_buffer, s);
  free(print_buffer);
#elif defined(_MSVC)
  std::string print_buffer_str;
  restore_stdout_and_read_redirected_file(
    original_stdout_fd, print_buffer_str);
#endif

  EXPECT_STREQ(test_log_buffer.data(), print_buffer_str.c_str());

  // Verify that no log file was created.
  std::ifstream test_log_file(LLOGGER_LOG_FILE_PATH);
  EXPECT_FALSE(test_log_file.is_open());
}

TEST_F(LLoggerTest, log_line_console_file) {
  LogLevel test_log_level = LogLevel::LOG_WARN;
  LogBufferType test_log_buffer = {'\0'};

  logger.set_log_type(LogType::LOG_CONSOLE_FILE);

  std::array<char, DATETIME_STR_LEN + 1> test_datetime = gen_datetime_str();

  // Redirect stdout to a buffer first.
#ifdef _GNU
  char* print_buffer = nullptr;
  std::size_t s = 0;
  FILE* mem_stream = open_memstream(&print_buffer, &s);
  FILE* original_stdout = stdout;
  stdout = mem_stream;
#elif defined(_MSVC)
  FILE* file_ptr = nullptr;
  int original_stdout_fd = redirect_stdout_to_file(&file_ptr);
#endif

// Populate a formatted string to do a direct comparison.
#ifdef _GNU
  snprintf(test_log_buffer.data(),
    test_log_buffer.size(),
    "%s%s%s Test console output for LogType::%s.%s\n",
    logger.get_log_level_color(test_log_level).data(),
    test_datetime.data(),
    LOG_LEVEL_PREFIX[test_log_level],
    LOG_TYPE_STR[logger.get_log_type()],
    COLOR_RESET);
#elif defined(_MSVC)
  // Test console output only, since color is set separately.
  snprintf(test_log_buffer.data(),
    test_log_buffer.size(),
    "%s%s Test console output for LogType::%s.",
    test_datetime.data(),
    LOG_LEVEL_PREFIX[test_log_level],
    LOG_TYPE_STR[logger.get_log_type()]);
#endif

  // Call LLogger::log_line to capture its output.
  EXPECT_TRUE(
    logger.log_line(
      test_log_level,
      "Test console output for LogType::%s.",
      LOG_TYPE_STR[logger.get_log_type()]));

  // Restore stdout back to normal.
#ifdef _GNU
  fclose(mem_stream);
  stdout = original_stdout;
  std::string print_buffer_str(print_buffer, s);
  free(print_buffer);
#elif defined(_MSVC)
  std::string print_buffer_str;
  restore_stdout_and_read_redirected_file(
    original_stdout_fd, print_buffer_str);
#endif

  EXPECT_STREQ(test_log_buffer.data(), print_buffer_str.c_str());

  // Open log file and verify its contents.
  std::ifstream test_log_file(LLOGGER_LOG_FILE_PATH);
  EXPECT_TRUE(test_log_file.is_open());

  // Populate a formatted string to do a direct comparison.
  test_log_buffer.fill('\0');
  snprintf(test_log_buffer.data(),
    test_log_buffer.size(),
    "%s%s Test console output for LogType::%s.",
    test_datetime.data(),
    LOG_LEVEL_PREFIX[test_log_level],
    LOG_TYPE_STR[logger.get_log_type()]);

  // Compare the file's contents and delete the file after.
  std::string line;
  while (std::getline(test_log_file, line)) {
    EXPECT_STREQ(test_log_buffer.data(), line.c_str());
  }

  if (test_log_file.is_open()) {
    test_log_file.close();
    EXPECT_EQ(std::remove(LLOGGER_LOG_FILE_PATH), 0);
  }
}

TEST_F(LLoggerTest, log_line_file) {
  LogLevel test_log_level = LogLevel::LOG_WARN;
  LogBufferType test_log_buffer = {'\0'};

  logger.set_log_type(LogType::LOG_FILE);

  std::array<char, DATETIME_STR_LEN + 1> test_datetime = gen_datetime_str();
  
  // Populate a formatted string to do a direct comparison.
  snprintf(test_log_buffer.data(),
    test_log_buffer.size(),
    "%s%s Test console output for LogType::%s.",
    test_datetime.data(),
    LOG_LEVEL_PREFIX[test_log_level],
    LOG_TYPE_STR[logger.get_log_type()]);

  // Redirect stdout to a buffer. (To ensure no console output is written.)
#ifdef _GNU
  char* print_buffer = nullptr;
  std::size_t s = 0;
  FILE* mem_stream = open_memstream(&print_buffer, &s);
  FILE* original_stdout = stdout;
  stdout = mem_stream;
#elif defined(_MSVC)
  FILE* file_ptr = nullptr;
  int original_stdout_fd = redirect_stdout_to_file(&file_ptr);
#endif

  // Call LLogger::log_line to capture its output.
  EXPECT_TRUE(
    logger.log_line(
      test_log_level,
      "Test console output for LogType::%s.",
      LOG_TYPE_STR[logger.get_log_type()]));

  // Open log file and verify its contents.
  std::ifstream test_log_file(LLOGGER_LOG_FILE_PATH);
  EXPECT_TRUE(test_log_file.is_open());

  // Compare the file's contents and delete the file after.
  std::string line;
  while (std::getline(test_log_file, line)) {
    EXPECT_STREQ(test_log_buffer.data(), line.c_str());
  }

  if (test_log_file.is_open()) {
    test_log_file.close();
    EXPECT_EQ(std::remove(LLOGGER_LOG_FILE_PATH), 0);
  }

  // Verify that no console output was written.
#ifdef _GNU
  fclose(mem_stream);
  stdout = original_stdout;
  std::string print_buffer_str(print_buffer, s);
  free(print_buffer);
#elif defined(_MSVC)
  std::string print_buffer_str;
  restore_stdout_and_read_redirected_file(
    original_stdout_fd, print_buffer_str);
#endif

  EXPECT_TRUE(print_buffer_str.empty());
}

TEST_F(LLoggerTest, log_line_input_handling) {
  EXPECT_FALSE(
    logger.log_line(
      LogLevel::LOG_OFF,
      "test_log_off %d",
      1));

  EXPECT_FALSE(
    logger.log_line(
      (LogLevel)20,
      "test_out_of_bounds %d",
      1));
}

TEST_F(LLoggerTest, log_line_colors_console) {
  constexpr std::array<ColorTextType, 6> test_multi_colors = {
    gen_color_code(ColorIndex::WHITE, ColorIndex::RED, true, true),  // FATAL
    gen_color_code(ColorIndex::RED, ColorIndex::BLACK, true, false),  // ERROR
    gen_color_code(ColorIndex::YELLOW, ColorIndex::BLACK, true, false),  // WARN
    gen_color_code(ColorIndex::CYAN, ColorIndex::BLACK, true, false),  // INFO
    gen_color_code(ColorIndex::GREEN, ColorIndex::BLACK, true, false)  // DEBUG
  };

  // TODO(Jashen): write tests for multi-color.
}
