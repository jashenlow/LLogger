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

#include <cstring>
#include <cstdint>
#include <type_traits>
#include <array>

// User-customizable defines
#ifndef LLOGGER_LOG_FILE_PATH
#define LLOGGER_LOG_FILE_PATH "log.txt"
#endif  // LLOGGER_LOG_FILE_PATH
#ifndef LLOGGER_MAX_STR_LEN
#define LLOGGER_MAX_STR_LEN 256
#endif  // LLOGGER_MAX_STR_LEN

// Defines for compilers
#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
#define _GNU
#endif

#ifdef _MSC_VER
#define _MSVC
#endif

namespace llogger {
// Verify the data types of preprocessors.
static_assert(true, LLOGGER_LOG_FILE_PATH);
static_assert(std::is_integral<decltype(LLOGGER_MAX_STR_LEN)>::value,
"Error: LLOGGER_MAX_STR_LEN is not an integer type.");
static_assert(LLOGGER_MAX_STR_LEN > 0,
"Error: LLOGGER_MAX_STR_LEN does not contain a positive value.");

// Enums ---------------------------------------------
enum LogType : uint8_t {
  LOG_CONSOLE = 0,
  LOG_FILE = 1,
  LOG_CONSOLE_FILE = 2
};

enum LogLevel : uint8_t {
  LOG_OFF = 0,
  LOG_FATAL = 1,
  LOG_ERROR = 2,
  LOG_WARN = 3,
  LOG_INFO = 4,
  LOG_DEBUG = 5
};

#ifdef _GNU
enum ColorIndex : char {
  BLACK = '0',
  RED = '1',
  GREEN = '2',
  YELLOW = '3',
  BLUE = '4',
  MAGENTA = '5',
  CYAN = '6',
  WHITE = '7'
};
#elif defined(_MSVC)
enum ColorIndex : uint16_t {
  BLACK = 0x0000,
  RED = 0x0004,
  GREEN = 0x0002,
  YELLOW = RED | GREEN,
  BLUE = 0x0001,
  MAGENTA = RED | BLUE,
  CYAN = BLUE | GREEN,
  WHITE = RED | GREEN | BLUE
};
#endif
// ---------------------------------------------

// Constants ---------------------------------------------
static constexpr std::size_t LOG_LEVEL_PREFIX_MAX_LEN = 7;
static constexpr std::size_t DATETIME_STR_LEN = 23;
static constexpr std::array<const char*, 3> LOG_TYPE_STR = {
  "LOG_CONSOLE",
  "LOG_FILE",
  "LOG_CONSOLE_AND_FILE"
};
static constexpr std::array<const char*, 6> LOG_LEVEL_STR = {
  "LOG_OFF",
  "LOG_FATAL",
  "LOG_ERROR",
  "LOG_WARN",
  "LOG_INFO",
  "LOG_DEBUG"
};
static constexpr std::array<const char*, 6> LOG_LEVEL_PREFIX = {
  "[OFF]",
  "[FATAL]",
  "[ERROR]",
  "[WARN]",
  "[INFO]",
  "[DEBUG]"
};
#ifdef _GNU
static constexpr std::size_t COLOR_CODE_MAX_LEN = 9;
static constexpr std::size_t COLOR_RESET_LEN = 4;
static constexpr char COLOR_RESET[] = "\033[0m";
#endif
// ---------------------------------------------

#ifdef _GNU
/*
We reserve bytes for the following in multiples of 8
for better caching:
  - Color Code (Actual = 9, reserve = 8 * 2)
  - DateTime (Actual = 23, reserve = 8 * 3)
  - Log Level (Actual = 7, reserve = 8 * 1)
  - Color Reset (Actual = 4, reserve = 8 * 1)
*/
using LogBufferType = std::array<char, 16 + 24 + 8 + 8 + LLOGGER_MAX_STR_LEN>;
#elif defined(_MSVC)
/*
We reserve bytes for the following in multiples of 8
for better caching:
  - DateTime (Actual = 23, reserve = 8 * 3)
  - Log Level (Actual = 7, reserve = 8 * 1)
*/
using LogBufferType = std::array<char, 24 + 8 + LLOGGER_MAX_STR_LEN>;
#endif

// Text color generation---------------------------------------------
#ifdef _GNU
using ColorTextType = std::array<char, 16>;
#define COLOR_TEXT_TYPE_INIT ColorTextType {'\0'}
#elif defined(_MSVC)
using ColorTextType = uint16_t;
#define COLOR_TEXT_TYPE_INIT (uint16_t)0
#endif

constexpr ColorTextType gen_color_code(
ColorIndex fg_color, ColorIndex bg_color,
bool fg_bold = true, bool bg_bold = false) {
#ifdef _GNU
  /*
  NOTES for ANSI color codes:
    - Prefix characters = "\033[".
    - Foreground(Normal) = '3'.
    - Foreground(Bold) = '9'.
    - Background(Normal) = '4'.
    - Background(Bold) = '10'.
    - Closing character = "m".
    - Format: "\033[<fg_boldness><fg_color>;<bg_boldness><bg_color>m".
  */
  ColorTextType color_code = COLOR_TEXT_TYPE_INIT;
  std::size_t index = 0;

  // Append prefix
  color_code[index++] = '\033';
  color_code[index++] = '[';
  // Append foreground boldness
  color_code[index++] = (fg_bold) ? '9' : '3';
  // Append foreground color
  color_code[index++] = fg_color;
  // Append separator character
  color_code[index++] = ';';
  // Append background boldness
  if (bg_bold) {
    color_code[index++] = '1';
    color_code[index++] = '0';
  } else {
    color_code[index++] = '4';
  }
  // Append background color
  color_code[index++] = bg_color;
  // Append closing character
  color_code[index++] = 'm';

  color_code[index++] = '\0';

  return color_code;
#elif defined(_MSVC)
  /*
  NOTES for MSVC color codes:
    - Foreground color = ColorIndex
    - Background color = (ColorIndex << 4).
    - Foreground(Bold) = 0x0008.
    - Background(Bold) = (Foreground(Bold) << 4).
    - Format: <background_color> | <background_boldness> | <foreground_color> | <foreground_boldness>.
  */
  uint16_t bg_boldness = (bg_bold) ? 0x0008 << 4 : 0x0000;
  uint16_t fg_boldness = (fg_bold) ? 0x0008 : 0x0000;

  return (bg_color << 4) | bg_boldness | fg_color | fg_boldness;
#endif
}
// ---------------------------------------------

// Default color codes---------------------------------------------
static constexpr std::array<ColorTextType, 6> DEFAULT_COLORS = {
  COLOR_TEXT_TYPE_INIT,  // OFF
  gen_color_code(ColorIndex::WHITE, ColorIndex::RED, true, true),  // FATAL
  gen_color_code(ColorIndex::RED, ColorIndex::BLACK, true, false),  // ERROR
  gen_color_code(ColorIndex::YELLOW, ColorIndex::BLACK, true, false),  // WARN
  gen_color_code(ColorIndex::CYAN, ColorIndex::BLACK, true, false),  // INFO
  gen_color_code(ColorIndex::GREEN, ColorIndex::BLACK, true, false)  // DEBUG
};
// ---------------------------------------------
}  // namespace llogger
