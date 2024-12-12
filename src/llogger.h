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

#pragma once

#include "llogger_definitions.h"

#include <mutex>

namespace llogger {
class LLogger {
 public:
  LLogger();
  ~LLogger();

  std::string_view get_log_file_path();

  bool set_log_file_path(std::string_view path);

  bool set_log_file_path(const char* path);

  LogType get_log_type();

  bool set_log_type(const LogType& set_type);

  ColorTextType get_log_level_color(const LogLevel& level);

  bool set_log_level_color(
    const LogLevel& level,
    const ColorIndex& fg_color,
    const ColorIndex& bg_color,
    bool fg_bold,
    bool bg_bold);

  bool log_line(const LogLevel& level, const char* format, ...);

  bool log_line_colors(
    const LogLevel& level,
    const std::initializer_list<const char*>& text_list,
    const std::initializer_list<ColorTextType>& color_list);

 private:
  LLogger(const LLogger &) = delete;
  LLogger& operator=(const LLogger&) = delete;

  std::array<ColorTextType, 6> log_level_colors{};
  std::string log_file_path;
  LogType log_type;
  std::mutex log_mutex;
#ifdef _MSVC
  uint16_t console_attr_original;
#endif

  bool set_color_code(const LogLevel& level, char** buff = nullptr);

  bool reset_color(char** buff = nullptr);

  bool write_date_time(char** buff);

  bool write_log_level(const LogLevel& level, char** buff);

  bool write_formatted_text(char** buff, const char* format, va_list args);

  bool write_to_file(char* start, char* end);

  bool print_multi_color(
    const std::initializer_list<const char*>& text_list,
    const std::initializer_list<ColorTextType>& color_list);
};
}  // namespace llogger
