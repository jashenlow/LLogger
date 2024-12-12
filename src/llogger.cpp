// MIT License
//
// Copyright(c) 2024 Jashen Low
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "llogger.h"

#ifdef _GNU
#include <sys/param.h>
#elif defined(_MSVC)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define ConsoleHandle GetStdHandle(STD_OUTPUT_HANDLE)
#endif

#include <cstdio>
#include <cstdarg>
#include <fstream>
#include <utility>

namespace llogger {
LLogger::LLogger() {
  // Set defaults
  log_file_path = LLOGGER_LOG_FILE_PATH;
  log_type = LogType::LOG_CONSOLE;
  log_level_colors = DEFAULT_COLORS;

#ifdef _MSVC
  // Store current console attributes
  CONSOLE_SCREEN_BUFFER_INFO console_buffer_info;
  GetConsoleScreenBufferInfo(ConsoleHandle, &console_buffer_info);
  console_attr_original = console_buffer_info.wAttributes;
#endif
}

LLogger::~LLogger() {}

std::string_view LLogger::get_log_file_path() {
  return log_file_path;
}

bool LLogger::set_log_file_path(std::string_view path) {
  if (path.empty()) {
    return false;
  }

  log_file_path = path;
  return true;
}

bool LLogger::set_log_file_path(const char *path) {
  if (path == nullptr) {
    return false;
  }

  log_file_path = path;
  return true;
}

LogType LLogger::get_log_type() {
  return log_type;
}

bool LLogger::set_log_type(const LogType& set_type) {
  if (set_type > LogType::LOG_CONSOLE_FILE) {
    return false;
  }

  log_type = set_type;
  return true;
}

ColorTextType LLogger::get_log_level_color(const LogLevel& level) {
  if (level > LogLevel::LOG_DEBUG) {
    return COLOR_TEXT_TYPE_INIT;
  }

  return log_level_colors[level];
}

bool LLogger::set_log_level_color(
const LogLevel& level,
const ColorIndex& fg_color,
const ColorIndex& bg_color,
bool fg_bold,
bool bg_bold) {
#ifdef _GNU
  if (fg_color < ColorIndex::BLACK ||
    bg_color < ColorIndex::BLACK) {
    return false;
  }
#endif
  if (level > LogLevel::LOG_DEBUG ||
    fg_color > ColorIndex::WHITE ||
    bg_color > ColorIndex::WHITE) {
    return false;
  }

  log_level_colors[level] =
    gen_color_code(fg_color, bg_color, fg_bold, bg_bold);

  return true;
}

bool LLogger::log_line(
const LogLevel& level, const char* format, ...) {
  if (level == LogLevel::LOG_OFF ||
    level > LogLevel::LOG_DEBUG ||
    format == nullptr) {
    return false;
  }

  LogBufferType log_buffer = {'\0'};
  char* buffer_ptr = log_buffer.data();

  // Append the color code to the buffer.
  if (log_type == LogType::LOG_CONSOLE ||
    log_type == LogType::LOG_CONSOLE_FILE) {
    if (!set_color_code(level, &buffer_ptr)) {
      return false;
    }
  }

  char* log_file_start_ptr = buffer_ptr;
  // Append the date and time to the buffer.
  if (!write_date_time(&buffer_ptr)) {
    return false;
  }

  // Append the log level to the buffer.
  if (!write_log_level(level, &buffer_ptr)) {
    return false;
  }

  // Append a space before the main text.
  *buffer_ptr++ = ' ';

  // Append formatted text to the buffer.
  va_list args;
  va_start(args, format);
  if (!write_formatted_text(&buffer_ptr, format, args)) {
    return false;
  }
  va_end(args);

  char* log_file_end_ptr = buffer_ptr;
#ifdef _GNU
  // Reset color at the end of the line.
  if (!reset_color(&buffer_ptr)) {
    return false;
  }

  *buffer_ptr++ = '\n';
  *buffer_ptr++ = '\0';
#endif

  // Lock since we are doing I/O operations.
  std::scoped_lock io_lock(log_mutex);

  if (log_type == LogType::LOG_CONSOLE ||
    log_type == LogType::LOG_CONSOLE_FILE) {
    // Write buffer to console.
#ifdef _GNU
    fputs(log_buffer.data(), stdout);
#elif defined(_MSVC)
    set_color_code(level);
    fputs(log_buffer.data(), stdout);
    reset_color();
    fputs("\n", stdout);
#endif

    // Write buffer to file.
    if (log_type == LogType::LOG_CONSOLE_FILE) {
      if (!write_to_file(log_file_start_ptr, log_file_end_ptr)) {
          return false;
        }
    }
  } else if (log_type == LogType::LOG_FILE) {
    // Write buffer to file.
    if (!write_to_file(log_file_start_ptr, log_file_end_ptr)) {
      return false;
    }
  }

  return true;
}

bool llogger::LLogger::log_line_colors(
const LogLevel& level,
const std::initializer_list<const char*>& text_list,
const std::initializer_list<ColorTextType>& color_list) {
  if (level == LogLevel::LOG_OFF || level > LogLevel::LOG_DEBUG) {
    return false;
  }

  std::ofstream log_file;
  std::array<char, 64> prefix_buffer = {'\0'};
  char* buffer_ptr = prefix_buffer.data();

  // Open log file if required.
  if (log_type == LogType::LOG_FILE ||
    log_type == LogType::LOG_CONSOLE_FILE) {
    log_file.open(log_file_path.c_str(), std::ios::app);

    if (!log_file.is_open()) {
      printf(
        "%s: Unable to open log file %s.\n",
        __FUNCTION__,
        log_file_path.c_str());
    }
  }

  // Append the color code based on log level to the buffer.
  if (log_type == LogType::LOG_CONSOLE ||
    log_type == LogType::LOG_CONSOLE_FILE) {
    if (!set_color_code(level, &buffer_ptr)) {
      return false;
    }
  }

  char* log_file_start_ptr = buffer_ptr;
  // Append the date and time to the buffer.
  if (!write_date_time(&buffer_ptr)) {
    return false;
  }

  // Append the log level to the buffer.
  if (!write_log_level(level, &buffer_ptr)) {
    return false;
  }

  // Append a space before the main text.
  *buffer_ptr++ = ' ';

  char* log_file_end_ptr = buffer_ptr;

  // Lock since we are doing I/O operations.
  std::scoped_lock io_lock(log_mutex);

  if (log_type == LogType::LOG_CONSOLE ||
    log_type == LogType::LOG_CONSOLE_FILE) {
    // Print prefix contents first.
#ifdef _GNU
    if (!reset_color(&buffer_ptr)) {
      return false;
    }

    *buffer_ptr++ = '\0';
    fputs(prefix_buffer.data(), stdout);
#elif defined(_MSVC)
    *buffer_ptr++ = '\0';
    fputs(prefix_buffer.data(), stdout);

    if (!reset_color(&buffer_ptr)) {
      return false;
    }
#endif
    if (log_type == LogType::LOG_CONSOLE_FILE && log_file.is_open()) {
      log_file.write(log_file_start_ptr, log_file_end_ptr - log_file_start_ptr);
    }

  } else if (log_type == LogType::LOG_FILE) {
    if (log_file.is_open()) {
      log_file.write(log_file_start_ptr, log_file_end_ptr - log_file_start_ptr);
    }
  }

  if (log_type == LogType::LOG_CONSOLE ||
    log_type == LogType::LOG_CONSOLE_FILE) {
    print_multi_color(text_list, color_list);

    if (log_type == LogType::LOG_CONSOLE_FILE && log_file.is_open()) {
      for (const char* text : text_list) {
        log_file << text;
      }

      log_file << "\n";
      log_file.close();
    }
  } else if (log_type == LogType::LOG_FILE && log_file.is_open()) {
    for (const char* text : text_list) {
      log_file << text;
    }

    log_file << "\n";
    log_file.close();
  }

  return true;
}

bool LLogger::set_color_code(const LogLevel& level, char** buff) {
  if (level == LogLevel::LOG_OFF || level > LogLevel::LOG_DEBUG) {
    return false;
  }

#ifdef _GNU
  if (buff == nullptr) {
    return false;
  }

  const std::size_t len = strlen(log_level_colors[level].data());
  memcpy(*buff, log_level_colors[level].data(), len);
  *buff += len;
#elif defined(_MSVC)
  SetConsoleTextAttribute(ConsoleHandle, log_level_colors[level]);
#endif

   return true;
}

bool LLogger::reset_color(char** buff) {
#ifdef _GNU
  if (buff == nullptr) {
    return false;
  }

  const std::size_t len = strlen(COLOR_RESET);
  memcpy(*buff, COLOR_RESET, len);
  *buff += len;
#elif defined(_MSVC)
  SetConsoleTextAttribute(ConsoleHandle, console_attr_original);
#endif

  return true;
}

bool LLogger::write_date_time(char** buff) {
  if (buff == nullptr) {
    return false;
  }

  std::time_t timenow = std::time(nullptr);
  std::size_t len = std::strftime(
    *buff, DATETIME_STR_LEN, "[%d-%m-%Y][%H:%M:%S]", std::localtime(&timenow));
  *buff += len;

  return true;
}

bool LLogger::write_log_level(const LogLevel& level, char** buff) {
  if (buff == nullptr ||
    level == LogLevel::LOG_OFF ||
    level > LogLevel::LOG_DEBUG) {
    return false;
  }

  const std::size_t len = strlen(LOG_LEVEL_PREFIX[level]);
  memcpy(*buff, LOG_LEVEL_PREFIX[level], len);
  *buff += len;

  return true;
}

bool LLogger::write_formatted_text(
char** buff, const char* format, va_list args) {
  if (buff == nullptr || format == nullptr) {
    return false;
  }

  // Get the length of the formatted string first.
  va_list buff_args;
  va_copy(buff_args, args);
  std::size_t str_len = (std::size_t)vsnprintf(nullptr, 0, format, args);
  /*
  If formatted string is > LLOGGER_MAX_STR_LEN,
  limit length to LLOGGER_MAX_STR_LEN.
  */
  if (str_len > LLOGGER_MAX_STR_LEN) {
    str_len = LLOGGER_MAX_STR_LEN;
  }
  // Process the formatted string into the buffer.
  vsnprintf(*buff, str_len + 1, format, buff_args);
  *buff += str_len;

  return true;
}

bool LLogger::write_to_file(char* start, char* end) {
  if (start == nullptr || end == nullptr) {
    return false;
  }

  std::ofstream log_file;
  log_file.open(log_file_path.c_str(), std::ios::app);

  if (!log_file.is_open()) {
    printf(
      "%s: Unable to open log file %s.\n",
      __FUNCTION__,
      log_file_path.c_str());

    return false;
  }
  log_file.write(start, end - start);
  log_file << "\n";
  log_file.close();

  return true;
}

bool LLogger::print_multi_color(
const std::initializer_list<const char *>& text_list,
const std::initializer_list<ColorTextType>& color_list) {
  // Iterate through words in the list and print them directly.
  auto color_list_iter = color_list.begin();

  for (const char* text : text_list) {
#ifdef _GNU
    // Print color code text for ANSI codes.
    fputs(
    (color_list_iter != color_list.end()) ?
      reinterpret_cast<const char*>(color_list_iter->data()) :
      COLOR_RESET,
    stdout);
#elif defined(_MSVC)
    // Set console text atrtributes to the desired color.
    SetConsoleTextAttribute(
      ConsoleHandle,
      (color_list_iter != color_list.end()) ?
        *color_list_iter :
        console_attr_original);
#endif
    if (color_list_iter != color_list.end()) {
      color_list_iter++;
    }

    fputs(text, stdout);
  }

#ifdef _GNU
  fputs(COLOR_RESET, stdout);
#elif defined(_MSVC)
  reset_color();
#endif
  fputs("\n", stdout);

  return true;
}
}  // namespace llogger
