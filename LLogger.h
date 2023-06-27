//MIT License
//
//Copyright(c) 2022 Jashen Low
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this softwareand associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright noticeand this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

#pragma once
#ifndef _LLOGGER_H_
#define _LLOGGER_H_

#include <ctime>
#include <fstream>
#include <array>
#include <vector>
#include <mutex>
#include <stdarg.h>

#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#ifndef IS_MSVC
#define IS_MSVC
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <wincon.h>

enum LLogColor : uint8_t
{
	//Foreground only
	FOREGROUND_WHITE			= (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN),
	FOREGROUND_YELLOW			= (FOREGROUND_RED | FOREGROUND_GREEN),
	FOREGROUND_CYAN				= (FOREGROUND_BLUE | FOREGROUND_GREEN),
	FOREGROUND_MAGENTA			= (FOREGROUND_RED | FOREGROUND_BLUE),
	FOREGROUND_BLACK			= 0x0000,
	FOREGROUND_BOLD_RED		= (FOREGROUND_RED | FOREGROUND_INTENSITY),
	FOREGROUND_BOLD_GREEN	= (FOREGROUND_GREEN | FOREGROUND_INTENSITY),
	FOREGROUND_BOLD_BLUE		= (FOREGROUND_BLUE | FOREGROUND_INTENSITY),
	FOREGROUND_BOLD_WHITE	= (FOREGROUND_WHITE | FOREGROUND_INTENSITY),
	FOREGROUND_BOLD_YELLOW	= (FOREGROUND_YELLOW | FOREGROUND_INTENSITY),
	FOREGROUND_BOLD_CYAN		= (FOREGROUND_CYAN | FOREGROUND_INTENSITY),
	FOREGROUND_BOLD_MAGENTA	= (FOREGROUND_MAGENTA | FOREGROUND_INTENSITY),

	//Background only
	BACKGROUND_WHITE			= (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN),
	BACKGROUND_YELLOW			= (BACKGROUND_RED | BACKGROUND_GREEN),
	BACKGROUND_CYAN				= (BACKGROUND_BLUE | BACKGROUND_GREEN),
	BACKGROUND_MAGENTA			= (BACKGROUND_RED | BACKGROUND_BLUE),
	BACKGROUND_BLACK			= 0x0000,
	BACKGROUND_BOLD_RED		= (BACKGROUND_RED | BACKGROUND_INTENSITY),
	BACKGROUND_BOLD_GREEN	= (BACKGROUND_GREEN | BACKGROUND_INTENSITY),
	BACKGROUND_BOLD_BLUE		= (BACKGROUND_BLUE | BACKGROUND_INTENSITY),
	BACKGROUND_BOLD_WHITE	= (BACKGROUND_WHITE | BACKGROUND_INTENSITY),
	BACKGROUND_BOLD_YELLOW	= (BACKGROUND_YELLOW | BACKGROUND_INTENSITY),
	BACKGROUND_BOLD_CYAN		= (BACKGROUND_CYAN | BACKGROUND_INTENSITY),
	BACKGROUND_BOLD_MAGENTA	= (BACKGROUND_MAGENTA | BACKGROUND_INTENSITY),

	//Foreground and Background
	RED_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_RED),
	RED_ON_BLUE					= (BACKGROUND_BLUE | FOREGROUND_RED),
	RED_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_RED),
	RED_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_RED),
	RED_ON_CYAN					= (BACKGROUND_CYAN | FOREGROUND_RED),
	RED_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_RED),
	RED_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_RED),
	RED_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_RED),
	RED_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_RED),
	RED_ON_BOLD_BLUE			= (BACKGROUND_BOLD_BLUE | FOREGROUND_RED),
	RED_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_RED),
	RED_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_RED),
	RED_ON_BOLD_CYAN			= (BACKGROUND_BOLD_CYAN | FOREGROUND_RED),
	RED_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_RED),

	GREEN_ON_RED				= (BACKGROUND_RED | FOREGROUND_GREEN),
	GREEN_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_GREEN),
	GREEN_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_GREEN),
	GREEN_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_GREEN),
	GREEN_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_GREEN),
	GREEN_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_GREEN),
	GREEN_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_GREEN),
	GREEN_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_GREEN),
	GREEN_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_GREEN),
	GREEN_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_GREEN),
	GREEN_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_GREEN),
	GREEN_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_GREEN),
	GREEN_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_GREEN),
	GREEN_ON_BOLD_MAGENTA	= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_GREEN),

	BLUE_ON_RED					= (BACKGROUND_RED | FOREGROUND_BLUE),
	BLUE_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BLUE),
	BLUE_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BLUE),
	BLUE_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_BLUE),
	BLUE_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BLUE),
	BLUE_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_BLUE),
	BLUE_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BLUE),
	BLUE_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_BLUE),
	BLUE_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_BLUE),
	BLUE_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_BLUE),
	BLUE_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_BLUE),
	BLUE_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BLUE),
	BLUE_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_BLUE),
	BLUE_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BLUE),

	WHITE_ON_RED				= (BACKGROUND_RED | FOREGROUND_WHITE),
	WHITE_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_WHITE),
	WHITE_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_WHITE),
	WHITE_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_WHITE),
	WHITE_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_WHITE),
	WHITE_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_WHITE),
	WHITE_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_WHITE),
	WHITE_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_WHITE),
	WHITE_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_WHITE),
	WHITE_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_WHITE),
	WHITE_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_WHITE),
	WHITE_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_WHITE),
	WHITE_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_WHITE),
	WHITE_ON_BOLD_MAGENTA	= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_WHITE),

	YELLOW_ON_RED				= (BACKGROUND_RED | FOREGROUND_YELLOW),
	YELLOW_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_YELLOW),
	YELLOW_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_YELLOW),
	YELLOW_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_YELLOW),
	YELLOW_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_YELLOW),
	YELLOW_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_YELLOW),
	YELLOW_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_YELLOW	= (BACKGROUND_BOLD_YELLOW | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_YELLOW),
	YELLOW_ON_BOLD_MAGENTA	= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_YELLOW),

	CYAN_ON_RED					= (BACKGROUND_RED | FOREGROUND_CYAN),
	CYAN_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_CYAN),
	CYAN_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_CYAN),
	CYAN_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_CYAN),
	CYAN_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_CYAN),
	CYAN_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_CYAN),
	CYAN_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_CYAN),
	CYAN_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_CYAN),
	CYAN_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_CYAN),
	CYAN_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_CYAN),
	CYAN_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_CYAN),
	CYAN_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_CYAN),
	CYAN_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_CYAN),
	CYAN_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_CYAN),
	
	MAGENTA_ON_RED					= (BACKGROUND_RED | FOREGROUND_MAGENTA),
	MAGENTA_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_MAGENTA),
	MAGENTA_ON_BLUE					= (BACKGROUND_BLUE | FOREGROUND_MAGENTA),
	MAGENTA_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_MAGENTA),
	MAGENTA_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_MAGENTA),
	MAGENTA_ON_CYAN					= (BACKGROUND_CYAN | FOREGROUND_MAGENTA),
	MAGENTA_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_BLUE			= (BACKGROUND_BOLD_BLUE | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_CYAN			= (BACKGROUND_BOLD_CYAN | FOREGROUND_MAGENTA),
	MAGENTA_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_MAGENTA),

	BLACK_ON_RED					= (BACKGROUND_RED | FOREGROUND_BLACK),
	BLACK_ON_GREEN					= (BACKGROUND_GREEN | FOREGROUND_BLACK),
	BLACK_ON_BLUE					= (BACKGROUND_BLUE | FOREGROUND_BLACK),
	BLACK_ON_WHITE					= (BACKGROUND_WHITE | FOREGROUND_BLACK),
	BLACK_ON_YELLOW					= (BACKGROUND_YELLOW | FOREGROUND_BLACK),
	BLACK_ON_CYAN					= (BACKGROUND_CYAN | FOREGROUND_BLACK),
	BLACK_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_BLACK),
	BLACK_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_BLACK),
	BLACK_ON_BOLD_GREEN			= (BACKGROUND_BOLD_GREEN | FOREGROUND_BLACK),
	BLACK_ON_BOLD_BLUE			= (BACKGROUND_BOLD_BLUE | FOREGROUND_BLACK),
	BLACK_ON_BOLD_WHITE			= (BACKGROUND_BOLD_WHITE | FOREGROUND_BLACK),
	BLACK_ON_BOLD_YELLOW			= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BLACK),
	BLACK_ON_BOLD_CYAN			= (BACKGROUND_BOLD_CYAN | FOREGROUND_BLACK),
	BLACK_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BLACK),
	
	BOLD_RED_ON_RED					= (BACKGROUND_RED | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BLUE					= (BACKGROUND_BLUE | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_CYAN					= (BACKGROUND_CYAN | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BOLD_BLUE			= (BACKGROUND_BOLD_BLUE | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BOLD_CYAN			= (BACKGROUND_BOLD_CYAN | FOREGROUND_BOLD_RED),
	BOLD_RED_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BOLD_RED),

	BOLD_GREEN_ON_RED				= (BACKGROUND_RED | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_BOLD_GREEN),
	BOLD_GREEN_ON_BOLD_MAGENTA	= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BOLD_GREEN),

	BOLD_BLUE_ON_RED					= (BACKGROUND_RED | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_BOLD_BLUE),
	BOLD_BLUE_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BOLD_BLUE),

	BOLD_WHITE_ON_RED				= (BACKGROUND_RED | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_BOLD_WHITE),
	BOLD_WHITE_ON_BOLD_MAGENTA	= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BOLD_WHITE),
	
	BOLD_YELLOW_ON_RED				= (BACKGROUND_RED | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_YELLOW			= (BACKGROUND_YELLOW | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_BOLD_YELLOW),
	BOLD_YELLOW_ON_BOLD_MAGENTA	= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BOLD_YELLOW),

	BOLD_CYAN_ON_RED					= (BACKGROUND_RED | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_GREEN				= (BACKGROUND_GREEN | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_WHITE				= (BACKGROUND_WHITE | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_YELLOW				= (BACKGROUND_YELLOW | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_MAGENTA				= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BLACK				= (BACKGROUND_BLACK | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BOLD_RED			= (BACKGROUND_BOLD_RED | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BOLD_GREEN		= (BACKGROUND_BOLD_GREEN | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BOLD_WHITE		= (BACKGROUND_BOLD_WHITE | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BOLD_YELLOW		= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BOLD_CYAN),
	BOLD_CYAN_ON_BOLD_MAGENTA		= (BACKGROUND_BOLD_MAGENTA | FOREGROUND_BOLD_CYAN),

	BOLD_MAGENTA_ON_RED				= (BACKGROUND_RED | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_GREEN			= (BACKGROUND_GREEN | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BLUE				= (BACKGROUND_BLUE | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_WHITE			= (BACKGROUND_WHITE | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_YELLOW			= (BACKGROUND_YELLOW | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_CYAN				= (BACKGROUND_CYAN | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_MAGENTA			= (BACKGROUND_MAGENTA | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BLACK			= (BACKGROUND_BLACK | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BOLD_RED		= (BACKGROUND_BOLD_RED | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BOLD_GREEN	= (BACKGROUND_BOLD_GREEN | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BOLD_BLUE		= (BACKGROUND_BOLD_BLUE | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BOLD_WHITE	= (BACKGROUND_BOLD_WHITE | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BOLD_YELLOW	= (BACKGROUND_BOLD_YELLOW | FOREGROUND_BOLD_MAGENTA),
	BOLD_MAGENTA_ON_BOLD_CYAN		= (BACKGROUND_BOLD_CYAN | FOREGROUND_BOLD_MAGENTA)
};

#define ConsoleHandle GetStdHandle(STD_OUTPUT_HANDLE)

typedef uint8_t LLogColorCode;

#elif defined(__GNUC__)
#ifndef IS_GNU
#define IS_GNU
#endif

#include <string.h>
#include <sys/param.h>

namespace LLogColor
{
	//Foreground only
	constexpr char FOREGROUND_RED[]				= "\033[0;31m";
	constexpr char FOREGROUND_GREEN[]				= "\033[0;32m";
	constexpr char FOREGROUND_BLUE[]				= "\033[0;34m";
	constexpr char FOREGROUND_WHITE[]				= "\033[0;37m";
	constexpr char FOREGROUND_YELLOW[]				= "\033[0;33m";
	constexpr char FOREGROUND_CYAN[]				= "\033[0;36m";
	constexpr char FOREGROUND_MAGENTA[]			= "\033[0;35m";
	constexpr char FOREGROUND_BLACK[]				= "\033[0;30m";

	constexpr char FOREGROUND_BOLD_RED[]		= "\033[0;91m";
	constexpr char FOREGROUND_BOLD_GREEN[]	= "\033[0;92m";
	constexpr char FOREGROUND_BOLD_BLUE[]		= "\033[0;94m";
	constexpr char FOREGROUND_BOLD_WHITE[]		= "\033[0;97m";
	constexpr char FOREGROUND_BOLD_YELLOW[]		= "\033[0;93m";
	constexpr char FOREGROUND_BOLD_CYAN[]		= "\033[0;96m";
	constexpr char FOREGROUND_BOLD_MAGENTA[]	= "\033[0;95m";
	constexpr char FOREGROUND_BOLD_BLACK[]		= "\033[0;90m";

	//Background only
	constexpr char BACKGROUND_RED[]				= "\033[41m";
	constexpr char BACKGROUND_GREEN[]				= "\033[42m";
	constexpr char BACKGROUND_BLUE[]				= "\033[44m";
	constexpr char BACKGROUND_WHITE[]				= "\033[47m";
	constexpr char BACKGROUND_YELLOW[]				= "\033[43m";
	constexpr char BACKGROUND_CYAN[]				= "\033[46m";
	constexpr char BACKGROUND_MAGENTA[]			= "\033[45m";
	constexpr char BACKGROUND_BLACK[]				= "\033[40m";

	constexpr char BACKGROUND_BOLD_RED[]		= "\033[101m";
	constexpr char BACKGROUND_BOLD_GREEN[]		= "\033[102m";
	constexpr char BACKGROUND_BOLD_BLUE[]		= "\033[104m";
	constexpr char BACKGROUND_BOLD_WHITE[]		= "\033[107m";
	constexpr char BACKGROUND_BOLD_YELLOW[]		= "\033[103m";
	constexpr char BACKGROUND_BOLD_CYAN[]		= "\033[106m";
	constexpr char BACKGROUND_BOLD_MAGENTA[]	= "\033[105m";
	constexpr char BACKGROUND_BOLD_BLACK[]		= "\033[100m";

	//Foreground and Background
	constexpr char RED_ON_GREEN[]					= "\033[31;42m";
	constexpr char RED_ON_BLUE[]					= "\033[31;44m";
	constexpr char RED_ON_WHITE[]					= "\033[31;47m";
	constexpr char RED_ON_YELLOW[]					= "\033[31;43m";
	constexpr char RED_ON_CYAN[]					= "\033[31;46m";
	constexpr char RED_ON_MAGENTA[]				= "\033[31;45m";
	constexpr char RED_ON_BLACK[]					= "\033[31;40m";
	constexpr char RED_ON_BOLD_RED[]			= "\033[31;101m";
	constexpr char RED_ON_BOLD_GREEN[]			= "\033[31;102m";
	constexpr char RED_ON_BOLD_BLUE[]			= "\033[31;104m";
	constexpr char RED_ON_BOLD_WHITE[]			= "\033[31;107m";
	constexpr char RED_ON_BOLD_YELLOW[]			= "\033[31;103m";
	constexpr char RED_ON_BOLD_CYAN[]			= "\033[31;106m";
	constexpr char RED_ON_BOLD_MAGENTA[]		= "\033[31;105m";
	constexpr char RED_ON_BOLD_BLACK[]			= "\033[31;100m";

	constexpr char GREEN_ON_RED[]					= "\033[32;41m";
	constexpr char GREEN_ON_BLUE[]					= "\033[32;44m";
	constexpr char GREEN_ON_WHITE[]				= "\033[32;47m";
	constexpr char GREEN_ON_YELLOW[]				= "\033[32;43m";
	constexpr char GREEN_ON_CYAN[]					= "\033[32;46m";
	constexpr char GREEN_ON_MAGENTA[]			= "\033[32;45m";
	constexpr char GREEN_ON_BLACK[]				= "\033[32;40m";
	constexpr char GREEN_ON_BOLD_RED[]			= "\033[32;101m";
	constexpr char GREEN_ON_BOLD_GREEN[]		= "\033[32;102m";
	constexpr char GREEN_ON_BOLD_BLUE[]			= "\033[32;104m";
	constexpr char GREEN_ON_BOLD_WHITE[]		= "\033[32;107m";
	constexpr char GREEN_ON_BOLD_YELLOW[]		= "\033[32;103m";
	constexpr char GREEN_ON_BOLD_CYAN[]			= "\033[32;106m";
	constexpr char GREEN_ON_BOLD_MAGENTA[]		= "\033[32;105m";
	constexpr char GREEN_ON_BOLD_BLACK[]		= "\033[32;100m";

	constexpr char BLUE_ON_RED[]					= "\033[34;41m";
	constexpr char BLUE_ON_GREEN[]					= "\033[34;42m";
	constexpr char BLUE_ON_WHITE[]					= "\033[34;47m";
	constexpr char BLUE_ON_YELLOW[]				= "\033[34;43m";
	constexpr char BLUE_ON_CYAN[]				= "\033[34;46m";
	constexpr char BLUE_ON_MAGENTA[]				= "\033[34;45m";
	constexpr char BLUE_ON_BLACK[]					= "\033[34;40m";
	constexpr char BLUE_ON_BOLD_RED[]			= "\033[34;101m";
	constexpr char BLUE_ON_BOLD_GREEN[]			= "\033[34;102m";
	constexpr char BLUE_ON_BOLD_BLUE[]			= "\033[34;104m";
	constexpr char BLUE_ON_BOLD_WHITE[]			= "\033[34;107m";
	constexpr char BLUE_ON_BOLD_YELLOW[]		= "\033[34;103m";
	constexpr char BLUE_ON_BOLD_CYAN[]			= "\033[34;106m";
	constexpr char BLUE_ON_BOLD_MAGENTA[]		= "\033[34;105m";
	constexpr char BLUE_ON_BOLD_BLACK[]			= "\033[34;100m";

	constexpr char WHITE_ON_RED[]					= "\033[37;41m";
	constexpr char WHITE_ON_GREEN[]				= "\033[37;42m";
	constexpr char WHITE_ON_BLUE[]					= "\033[37;44m";
	constexpr char WHITE_ON_YELLOW[]				= "\033[37;43m";
	constexpr char WHITE_ON_CYAN[]					= "\033[37;46m";
	constexpr char WHITE_ON_MAGENTA[]				= "\033[37;45m";
	constexpr char WHITE_ON_BLACK[]				= "\033[37;40m";
	constexpr char WHITE_ON_BOLD_RED[]			= "\033[37;101m";
	constexpr char WHITE_ON_BOLD_GREEN[]		= "\033[37;102m";
	constexpr char WHITE_ON_BOLD_BLUE[]			= "\033[37;104m";
	constexpr char WHITE_ON_BOLD_WHITE[]		= "\033[37;107m";
	constexpr char WHITE_ON_BOLD_YELLOW[]		= "\033[37;103m";
	constexpr char WHITE_ON_BOLD_CYAN[]			= "\033[37;106m";
	constexpr char WHITE_ON_BOLD_MAGENTA[]		= "\033[37;105m";
	constexpr char WHITE_ON_BOLD_BLACK[]		= "\033[37;100m";
	
	constexpr char YELLOW_ON_RED[]					= "\033[33;41m";
	constexpr char YELLOW_ON_GREEN[]				= "\033[33;42m";
	constexpr char YELLOW_ON_BLUE[]				= "\033[33;44m";
	constexpr char YELLOW_ON_WHITE[]				= "\033[33;47m";
	constexpr char YELLOW_ON_CYAN[]				= "\033[33;46m";
	constexpr char YELLOW_ON_MAGENTA[]				= "\033[33;45m";
	constexpr char YELLOW_ON_BLACK[]				= "\033[33;40m";
	constexpr char YELLOW_ON_BOLD_RED[]			= "\033[33;101m";
	constexpr char YELLOW_ON_BOLD_GREEN[]		= "\033[33;102m";
	constexpr char YELLOW_ON_BOLD_BLUE[]		= "\033[33;104m";
	constexpr char YELLOW_ON_BOLD_WHITE[]		= "\033[33;107m";
	constexpr char YELLOW_ON_BOLD_YELLOW[]	= "\033[33;103m";
	constexpr char YELLOW_ON_BOLD_CYAN[]		= "\033[33;106m";
	constexpr char YELLOW_ON_BOLD_MAGENTA[]		= "\033[33;105m";
	constexpr char YELLOW_ON_BOLD_BLACK[]		= "\033[33;100m";

	constexpr char CYAN_ON_RED[]					= "\033[36;41m";
	constexpr char CYAN_ON_GREEN[]					= "\033[36;42m";
	constexpr char CYAN_ON_BLUE[]					= "\033[36;44m";
	constexpr char CYAN_ON_WHITE[]					= "\033[36;47m";
	constexpr char CYAN_ON_YELLOW[]				= "\033[36;43m";
	constexpr char CYAN_ON_MAGENTA[]				= "\033[36;45m";
	constexpr char CYAN_ON_BLACK[]					= "\033[36;40m";
	constexpr char CYAN_ON_BOLD_RED[]			= "\033[36;101m";
	constexpr char CYAN_ON_BOLD_GREEN[]			= "\033[36;102m";
	constexpr char CYAN_ON_BOLD_BLUE[]			= "\033[36;104m";
	constexpr char CYAN_ON_BOLD_WHITE[]			= "\033[36;107m";
	constexpr char CYAN_ON_BOLD_YELLOW[]		= "\033[36;103m";
	constexpr char CYAN_ON_BOLD_CYAN[]			= "\033[36;106m";
	constexpr char CYAN_ON_BOLD_MAGENTA[]		= "\033[36;105m";
	constexpr char CYAN_ON_BOLD_BLACK[]			= "\033[36;100m";

	constexpr char MAGENTA_ON_RED[]				= "\033[35;41m";
	constexpr char MAGENTA_ON_GREEN[]				= "\033[35;42m";
	constexpr char MAGENTA_ON_BLUE[]				= "\033[35;44m";
	constexpr char MAGENTA_ON_WHITE[]			= "\033[35;47m";
	constexpr char MAGENTA_ON_YELLOW[]				= "\033[35;43m";
	constexpr char MAGENTA_ON_CYAN[]				= "\033[35;46m";
	constexpr char MAGENTA_ON_BLACK[]				= "\033[35;40m";
	constexpr char MAGENTA_ON_BOLD_RED[]		= "\033[35;101m";
	constexpr char MAGENTA_ON_BOLD_GREEN[]		= "\033[35;102m";
	constexpr char MAGENTA_ON_BOLD_BLUE[]		= "\033[35;104m";
	constexpr char MAGENTA_ON_BOLD_WHITE[]		= "\033[35;107m";
	constexpr char MAGENTA_ON_BOLD_YELLOW[]		= "\033[35;103m";
	constexpr char MAGENTA_ON_BOLD_CYAN[]		= "\033[35;106m";
	constexpr char MAGENTA_ON_BOLD_MAGENTA[]	= "\033[35;105m";
	constexpr char MAGENTA_ON_BOLD_BLACK[]		= "\033[35;100m";

	constexpr char BLACK_ON_RED[]					= "\033[30;41m";
	constexpr char BLACK_ON_GREEN[]				= "\033[30;42m";
	constexpr char BLACK_ON_BLUE[]					= "\033[30;44m";
	constexpr char BLACK_ON_WHITE[]				= "\033[30;47m";
	constexpr char BLACK_ON_YELLOW[]				= "\033[30;43m";
	constexpr char BLACK_ON_CYAN[]					= "\033[30;46m";
	constexpr char BLACK_ON_MAGENTA[]				= "\033[30;45m";
	constexpr char BLACK_ON_BOLD_RED[]			= "\033[30;101m";
	constexpr char BLACK_ON_BOLD_GREEN[]		= "\033[30;102m";
	constexpr char BLACK_ON_BOLD_BLUE[]			= "\033[30;104m";
	constexpr char BLACK_ON_BOLD_WHITE[]		= "\033[30;107m";
	constexpr char BLACK_ON_BOLD_YELLOW[]		= "\033[30;103m";
	constexpr char BLACK_ON_BOLD_CYAN[]			= "\033[30;106m";
	constexpr char BLACK_ON_BOLD_MAGENTA[]		= "\033[30;105m";
	constexpr char BLACK_ON_BOLD_BLACK[]		= "\033[30;100m";

	constexpr char BOLD_RED_ON_RED[]				= "\033[91;41m";
	constexpr char BOLD_RED_ON_GREEN[]				= "\033[91;42m";
	constexpr char BOLD_RED_ON_BLUE[]				= "\033[91;44m";
	constexpr char BOLD_RED_ON_WHITE[]				= "\033[91;47m";
	constexpr char BOLD_RED_ON_YELLOW[]				= "\033[91;43m";
	constexpr char BOLD_RED_ON_CYAN[]				= "\033[91;46m";
	constexpr char BOLD_RED_ON_MAGENTA[]			= "\033[91;45m";
	constexpr char BOLD_RED_ON_BLACK[]				= "\033[91;40m";
	constexpr char BOLD_RED_ON_BOLD_GREEN[]		= "\033[91;102m";
	constexpr char BOLD_RED_ON_BOLD_BLUE[]		= "\033[91;104m";
	constexpr char BOLD_RED_ON_BOLD_WHITE[]		= "\033[91;107m";
	constexpr char BOLD_RED_ON_BOLD_YELLOW[]		= "\033[91;103m";
	constexpr char BOLD_RED_ON_BOLD_CYAN[]		= "\033[91;106m";
	constexpr char BOLD_RED_ON_BOLD_MAGENTA[]	= "\033[91;105m";
	constexpr char BOLD_RED_ON_BOLD_BLACK[]		= "\033[91;100m";

	constexpr char BOLD_GREEN_ON_RED[]				= "\033[92;41m";
	constexpr char BOLD_GREEN_ON_GREEN[]			= "\033[92;42m";
	constexpr char BOLD_GREEN_ON_BLUE[]				= "\033[92;44m";
	constexpr char BOLD_GREEN_ON_WHITE[]			= "\033[92;47m";
	constexpr char BOLD_GREEN_ON_YELLOW[]			= "\033[92;43m";
	constexpr char BOLD_GREEN_ON_CYAN[]				= "\033[92;46m";
	constexpr char BOLD_GREEN_ON_MAGENTA[]			= "\033[92;45m";
	constexpr char BOLD_GREEN_ON_BLACK[]			= "\033[92;40m";
	constexpr char BOLD_GREEN_ON_BOLD_RED[]		= "\033[92;101m";
	constexpr char BOLD_GREEN_ON_BOLD_BLUE[]		= "\033[92;104m";
	constexpr char BOLD_GREEN_ON_BOLD_WHITE[]	= "\033[92;107m";
	constexpr char BOLD_GREEN_ON_BOLD_YELLOW[]	= "\033[92;103m";
	constexpr char BOLD_GREEN_ON_BOLD_CYAN[]		= "\033[92;106m";
	constexpr char BOLD_GREEN_ON_BOLD_MAGENTA[]	= "\033[92;105m";
	constexpr char BOLD_GREEN_ON_BOLD_BLACK[]	= "\033[92;100m";

	constexpr char BOLD_BLUE_ON_RED[]				= "\033[94;41m";
	constexpr char BOLD_BLUE_ON_GREEN[]				= "\033[94;42m";
	constexpr char BOLD_BLUE_ON_BLUE[]				= "\033[94;44m";
	constexpr char BOLD_BLUE_ON_WHITE[]				= "\033[94;47m";
	constexpr char BOLD_BLUE_ON_YELLOW[]			= "\033[94;43m";
	constexpr char BOLD_BLUE_ON_CYAN[]				= "\033[94;46m";
	constexpr char BOLD_BLUE_ON_MAGENTA[]			= "\033[94;45m";
	constexpr char BOLD_BLUE_ON_BLACK[]				= "\033[94;40m";
	constexpr char BOLD_BLUE_ON_BOLD_RED[]		= "\033[94;101m";
	constexpr char BOLD_BLUE_ON_BOLD_GREEN[]		= "\033[94;102m";
	constexpr char BOLD_BLUE_ON_BOLD_WHITE[]		= "\033[94;107m";
	constexpr char BOLD_BLUE_ON_BOLD_YELLOW[]	= "\033[94;103m";
	constexpr char BOLD_BLUE_ON_BOLD_CYAN[]		= "\033[94;106m";
	constexpr char BOLD_BLUE_ON_BOLD_MAGENTA[]	= "\033[94;105m";
	constexpr char BOLD_BLUE_ON_BOLD_BLACK[]		= "\033[94;100m";

	constexpr char BOLD_WHITE_ON_RED[]				= "\033[97;41m";
	constexpr char BOLD_WHITE_ON_GREEN[]			= "\033[97;42m";
	constexpr char BOLD_WHITE_ON_BLUE[]				= "\033[97;44m";
	constexpr char BOLD_WHITE_ON_WHITE[]			= "\033[97;47m";
	constexpr char BOLD_WHITE_ON_YELLOW[]			= "\033[97;43m";
	constexpr char BOLD_WHITE_ON_CYAN[]				= "\033[97;46m";
	constexpr char BOLD_WHITE_ON_MAGENTA[]			= "\033[97;45m";
	constexpr char BOLD_WHITE_ON_BLACK[]			= "\033[97;40m";
	constexpr char BOLD_WHITE_ON_BOLD_RED[]		= "\033[97;101m";
	constexpr char BOLD_WHITE_ON_BOLD_GREEN[]	= "\033[97;102m";
	constexpr char BOLD_WHITE_ON_BOLD_BLUE[]		= "\033[97;104m";
	constexpr char BOLD_WHITE_ON_BOLD_YELLOW[]	= "\033[97;103m";
	constexpr char BOLD_WHITE_ON_BOLD_CYAN[]		= "\033[97;106m";
	constexpr char BOLD_WHITE_ON_BOLD_MAGENTA[]	= "\033[97;105m";
	constexpr char BOLD_WHITE_ON_BOLD_BLACK[]	= "\033[97;100m";

	constexpr char BOLD_YELLOW_ON_RED[]				= "\033[93;41m";
	constexpr char BOLD_YELLOW_ON_GREEN[]			= "\033[93;42m";
	constexpr char BOLD_YELLOW_ON_BLUE[]			= "\033[93;44m";
	constexpr char BOLD_YELLOW_ON_WHITE[]			= "\033[93;47m";
	constexpr char BOLD_YELLOW_ON_YELLOW[]			= "\033[93;43m";
	constexpr char BOLD_YELLOW_ON_CYAN[]			= "\033[93;46m";
	constexpr char BOLD_YELLOW_ON_MAGENTA[]			= "\033[93;45m";
	constexpr char BOLD_YELLOW_ON_BLACK[]			= "\033[93;40m";
	constexpr char BOLD_YELLOW_ON_BOLD_RED[]		= "\033[93;101m";
	constexpr char BOLD_YELLOW_ON_BOLD_GREEN[]	= "\033[93;102m";
	constexpr char BOLD_YELLOW_ON_BOLD_BLUE[]	= "\033[93;104m";
	constexpr char BOLD_YELLOW_ON_BOLD_WHITE[]	= "\033[93;107m";
	constexpr char BOLD_YELLOW_ON_BOLD_CYAN[]	= "\033[93;106m";
	constexpr char BOLD_YELLOW_ON_BOLD_MAGENTA[] = "\033[93;105m";
	constexpr char BOLD_YELLOW_ON_BOLD_BLACK[]	= "\033[93;100m";

	constexpr char BOLD_CYAN_ON_RED[]				= "\033[96;41m";
	constexpr char BOLD_CYAN_ON_GREEN[]				= "\033[96;42m";
	constexpr char BOLD_CYAN_ON_BLUE[]				= "\033[96;44m";
	constexpr char BOLD_CYAN_ON_WHITE[]				= "\033[96;47m";
	constexpr char BOLD_CYAN_ON_YELLOW[]			= "\033[96;43m";
	constexpr char BOLD_CYAN_ON_CYAN[]				= "\033[96;46m";
	constexpr char BOLD_CYAN_ON_MAGENTA[]			= "\033[96;45m";
	constexpr char BOLD_CYAN_ON_BLACK[]				= "\033[96;40m";
	constexpr char BOLD_CYAN_ON_BOLD_RED[]		= "\033[96;101m";
	constexpr char BOLD_CYAN_ON_BOLD_GREEN[]		= "\033[96;102m";
	constexpr char BOLD_CYAN_ON_BOLD_BLUE[]		= "\033[96;104m";
	constexpr char BOLD_CYAN_ON_BOLD_WHITE[]		= "\033[96;107m";
	constexpr char BOLD_CYAN_ON_BOLD_YELLOW[]	= "\033[96;103m";
	constexpr char BOLD_CYAN_ON_BOLD_MAGENTA[]	= "\033[96;105m";
	constexpr char BOLD_CYAN_ON_BOLD_BLACK[]		= "\033[96;100m";

	constexpr char BOLD_MAGENTA_ON_RED[]			= "\033[95;41m";
	constexpr char BOLD_MAGENTA_ON_GREEN[]			= "\033[95;42m";
	constexpr char BOLD_MAGENTA_ON_BLUE[]			= "\033[95;44m";
	constexpr char BOLD_MAGENTA_ON_WHITE[]			= "\033[95;47m";
	constexpr char BOLD_MAGENTA_ON_YELLOW[]			= "\033[95;43m";
	constexpr char BOLD_MAGENTA_ON_CYAN[]		= "\033[95;46m";
	constexpr char BOLD_MAGENTA_ON_MAGENTA[]		= "\033[95;45m";
	constexpr char BOLD_MAGENTA_ON_BLACK[]			= "\033[95;40m";
	constexpr char BOLD_MAGENTA_ON_BOLD_RED[]	= "\033[95;101m";
	constexpr char BOLD_MAGENTA_ON_BOLD_GREEN[]	= "\033[95;102m";
	constexpr char BOLD_MAGENTA_ON_BOLD_BLUE[]	= "\033[95;104m";
	constexpr char BOLD_MAGENTA_ON_BOLD_WHITE[]	= "\033[95;107m";
	constexpr char BOLD_MAGENTA_ON_BOLD_YELLOW[] = "\033[95;103m";
	constexpr char BOLD_MAGENTA_ON_BOLD_CYAN[]	= "\033[95;106m";
	constexpr char BOLD_MAGENTA_ON_BOLD_BLACK[]	= "\033[95;100m";

	constexpr char BOLD_BLACK_ON_RED[]				= "\033[90;41m";
	constexpr char BOLD_BLACK_ON_GREEN[]			= "\033[90;42m";
	constexpr char BOLD_BLACK_ON_BLUE[]				= "\033[90;44m";
	constexpr char BOLD_BLACK_ON_WHITE[]			= "\033[90;47m";
	constexpr char BOLD_BLACK_ON_YELLOW[]			= "\033[90;43m";
	constexpr char BOLD_BLACK_ON_CYAN[]				= "\033[90;46m";
	constexpr char BOLD_BLACK_ON_MAGENTA[]			= "\033[90;45m";
	constexpr char BOLD_BLACK_ON_BLACK[]			= "\033[90;40m";
	constexpr char BOLD_BLACK_ON_BOLD_RED[]		= "\033[90;101m";
	constexpr char BOLD_BLACK_ON_BOLD_GREEN[]	= "\033[90;102m";
	constexpr char BOLD_BLACK_ON_BOLD_BLUE[]		= "\033[90;104m";
	constexpr char BOLD_BLACK_ON_BOLD_WHITE[]	= "\033[90;107m";
	constexpr char BOLD_BLACK_ON_BOLD_YELLOW[]	= "\033[90;103m";
	constexpr char BOLD_BLACK_ON_BOLD_CYAN[]		= "\033[90;106m";
	constexpr char BOLD_BLACK_ON_BOLD_MAGENTA[]	= "\033[90;105m";

	constexpr char COLOR_RESET[]						= "\033[0m";
}

typedef const char* LLogColorCode;
#endif

constexpr char LLOGGER_DEFAULT_FILE_PATH[]      = "./log.txt";
constexpr size_t LLOGGER_MAX_BUFFER_SIZE        = 1073741824;  //1GB
constexpr size_t LLOGGER_ERR_BUFFER_SIZE        = 128;
constexpr size_t LLOGGER_DEFAULT_BUFFER_SIZE    = 128;
constexpr size_t LLOGGER_BUFFER_STEP_SIZE       = 64;
constexpr uint8_t TIMESTAMP_BUFF_LEN            = 10;

enum class LLogType : uint8_t
{
	CONSOLE             = 0,
	FILE                = 1,
	CONSOLE_AND_FILE    = 2
};
constexpr std::array<const char*, 3> LLogTypeStr = { "CONSOLE", "FILE", "CONSOLE_AND_FILE" };

enum class LLogLevel : uint8_t
{
	LOG_OFF     = 0,
	LOG_FATAL   = 1,
	LOG_ERROR   = 2,
	LOG_WARN    = 3,
	LOG_INFO    = 4
};
constexpr std::array<const char*, 5> LLogLevelStr = { "LOG_OFF", "LOG_FATAL", "LOG_ERROR", "LOG_WARN", "LOG_INFO" };
constexpr std::array<const char*, 5> LLogLevelPrefix = { "[OFF] ", "[FATAL] ", "[ERROR] ", "[WARN] ", "[INFO] " };

class LLogger
{
public:
	/*
	* Description    :  Default constructor. Initializes all default settings.
	* Return         :
	*/
	LLogger()
	{
#ifdef IS_MSVC
		CONSOLE_SCREEN_BUFFER_INFO  consoleBufferInfo;
		GetConsoleScreenBufferInfo(ConsoleHandle, &consoleBufferInfo);
		defaultConsoleAttr = consoleBufferInfo.wAttributes;
#endif
		logLevelColors[(uint8_t)LLogLevel::LOG_FATAL]   = LLogColor::BOLD_WHITE_ON_BOLD_RED;
		logLevelColors[(uint8_t)LLogLevel::LOG_ERROR]   = LLogColor::BOLD_RED_ON_BLACK;
		logLevelColors[(uint8_t)LLogLevel::LOG_WARN]    = LLogColor::BOLD_YELLOW_ON_BLACK;
		logLevelColors[(uint8_t)LLogLevel::LOG_INFO]    = LLogColor::BOLD_CYAN_ON_BLACK;

		//Set default values
		logType	    = LLogType::CONSOLE;
		logLevel    = LLogLevel::LOG_INFO;
		logFilePath = LLOGGER_DEFAULT_FILE_PATH;
		SetLogBufferSize(LLOGGER_DEFAULT_BUFFER_SIZE);
		showPrefix    = true;
		showTimeStamp = false;
	}

	/*
	* Description    :  Default constructor. Initializes all default settings.
	* Return         :
	*/
	LLogger(const LLogType& type, const LLogLevel& level, bool prefix = true, bool timestamp = false)
	{
#ifdef IS_MSVC
		CONSOLE_SCREEN_BUFFER_INFO  consoleBufferInfo;
		GetConsoleScreenBufferInfo(ConsoleHandle, &consoleBufferInfo);
		defaultConsoleAttr = consoleBufferInfo.wAttributes;
#endif
		logLevelColors[(uint8_t)LLogLevel::LOG_FATAL]   = LLogColor::BOLD_WHITE_ON_BOLD_RED;
		logLevelColors[(uint8_t)LLogLevel::LOG_ERROR]   = LLogColor::BOLD_RED_ON_BLACK;
		logLevelColors[(uint8_t)LLogLevel::LOG_WARN]    = LLogColor::BOLD_YELLOW_ON_BLACK;
		logLevelColors[(uint8_t)LLogLevel::LOG_INFO]    = LLogColor::BOLD_CYAN_ON_BLACK;

		logType = type;
		logLevel = level;
		logFilePath = LLOGGER_DEFAULT_FILE_PATH;
		SetLogBufferSize(LLOGGER_DEFAULT_BUFFER_SIZE);
		showPrefix = prefix;
		showTimeStamp = timestamp;
	}

	/*
	* Description    :  Default destructor.
	* Return         :
	*/
	~LLogger(){}

	/*
	* Description    :  Returns the class name as a C string.
	* Return         :  Class name as a C string.
	*/
	const char* GetClassStr() { return "LLogger"; }

	/*
	* Description    :  Sets the type of output that the logger will generate, based on enum LLogType.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	bool SetLogType(const LLogType& newType)
	{
		if ((uint8_t)newType > (uint8_t)LLogType::CONSOLE_AND_FILE)
		{
			PrintLoggerError("%s: Invalid LogType entered! Ignoring this call...", __FUNCTION__);
			return false;
		}

		logType = newType;
		return true;
	}

	/*
	* Description    :  Returns the current log type setting, based on enum LLogType.
	* Return         :  Current log type.
	*/
	const LLogType& GetLogType() const
	{
		return logType;
	}

	/*
	* Description    :  Returns the flag that determines if the log level is printed in log messages.
	* Return         :  Log prefix flag.
	*/
    bool GetShowLogPrefix() const
	{
		return showPrefix;
	}

	/*
	* Description    :  Sets the flag that determines if the log level is printed in log messages.
	* Return         :  
	*/
    void SetShowLogPrefix(const bool& flag)
	{
		showPrefix = flag;
	}

	/*
	* Description    :  Returns the flag that determines if the timestamp is printed in log messages.
	* Return         :  Timestamp flag.
	*/
    bool GetShowTimeStamp() const
	{
		return showTimeStamp;
	}

	/*
	* Description    :  Sets the flag that determines if the timestamp is printed in log messages.
	* Return         :  
	*/
    void SetShowTimeStamp(const bool& flag)
	{
		showTimeStamp = flag;
	}

	/*
	* Description    :  Sets the type of output that the logger will generate, based on enum LLogType.
	*                :  NOTE: Include file extension in the argument. (e.g.: .txt, .ini).
	* Return         :  True = Successful execution, False = Error detected.
	*/
	bool SetLogFilePath(const char* newPath)
	{
		if (newPath == nullptr || (newPath != nullptr && newPath[0] == '\0'))
		{
			PrintLoggerError("%s: Invalid file path entered! Ignoring this call...", __FUNCTION__);
			return false;
		}

		logFilePath = newPath;
		return true;
	}

	/*
	* Description    :  Returns the current log file path as a C string.
	* Return         :  Current log file path.
	*/
	const char* GetLogFilePath() const
	{
		return logFilePath.c_str();
	}

	/*
	* Description    :  Clears the contents of the log file.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	bool ClearLogFile()
	{
		if (logFilePath.empty())
			logFilePath = LLOGGER_DEFAULT_FILE_PATH;

		logFile.open(logFilePath, std::ios::out | std::ios::trunc);

		if (logFile.is_open())
			logFile.close();
		else
		{
			PrintLoggerError("%s: Unable to create/open log file \"%s\"", __FUNCTION__, logFilePath.c_str());
			return false;
		}

		return true;
	}

	/*
	* Description    :  Sets the current logging verbosity level, based on enum LLogLevel.
	*                :  Log level descriptions:
	*                       0 - Does not log anything.
    *                       1 - Only logs [FATAL] level.
    *                       2 - Logs [FATAL] and [ERROR] levels.
    *                       3 - Logs [FATAL], [ERROR], and [WARN] levels.
    *                       4 - Logs all levels.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	bool SetLogLevel(const LLogLevel& newLevel)
	{
		if (newLevel > LLogLevel::LOG_INFO)
		{
			PrintLoggerError("%s: Invalid verbosity value of %d was set! Ignoring this call...", __FUNCTION__, (uint8_t)newLevel);
			return false;
		}

		logLevel = newLevel;
		return true;
	}

    /*
	* Description    :  Returns the current logging verbosity level, based on enum LLogLevel.
	*                :  Log level descriptions:
	*                       0 - Does not log anything.
    *                       1 - Only logs [FATAL] level.
    *                       2 - Logs [FATAL] and [ERROR] levels.
    *                       3 - Logs [FATAL], [ERROR], and [WARN] levels.
    *                       4 - Logs all levels.
	* Return         :  Current log level.
	*/
	const LLogLevel& GetLogLevel() const
	{
		return logLevel;
	}

    /*
	* Description    :  Sets the color code of a selected log level.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	bool SetLogLevelColor(const LLogLevel& level, LLogColorCode colorCode)
	{
		if (level < LLogLevel::LOG_FATAL || level > LLogLevel::LOG_INFO)
		{
			PrintLoggerError("%s: Invalid log level value of %d was set! Ignoring this call...", __FUNCTION__, (uint8_t)level);
			return false;
		}
#ifdef IS_GNU
		if (colorCode == nullptr || (colorCode != nullptr && (colorCode[0] == '\0' || strstr(colorCode, "\033[") == nullptr)))
		{
			PrintLoggerError("%s: Invalid colorCode value was set! Ignoring this call...", __FUNCTION__);
			return false;
		}
#endif
		logLevelColors[(uint8_t)level] = (LLogColorCode)colorCode;
		return true;
	}

	/*
	* Description    :  Returns the currently configured color code of a selected log level.
	* Return         :  Current color code.
	*/
	LLogColorCode GetLogLevelColor(const LLogLevel& level)
	{
		if (level < LLogLevel::LOG_FATAL || level > LLogLevel::LOG_INFO)
		{
			PrintLoggerError("%s: Invalid log level value of %d was set! Ignoring this call...", __FUNCTION__, (uint8_t)level);
#ifdef IS_MSVC
			return 0;
#else
			return "";
#endif
		}

		return logLevelColors[(uint8_t)level];
	}

	/*
	* Description    :  Sets the size of the internal log buffer.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	bool SetLogBufferSize(const size_t& size)
	{
		if (size <= LLOGGER_MAX_BUFFER_SIZE)
			logBuffer.resize(size);
		else
		{
			PrintLoggerError("%s: Unable to set buffer limit of %zd characters! The maximum is %zd.", __FUNCTION__, size, LLOGGER_MAX_BUFFER_SIZE);
			return false;
		}

		return true;
	}

	/*
	* Description    :  Returns the size of the internal log buffer.
	* Return         :  Log buffer size.
	*/
	size_t GetLogBufferSize() const
	{
		return logBuffer.size();
	}

    /*
	* Description    :  Logs the list of texts in argument "msg", and displays them in their respective colors defined by argument "colorCode".
	* Return         :  True = Successful execution, False = Error detected.
	*/
	inline bool LogLineColors(const LLogLevel& level, const std::vector<const char*>& msg, const std::vector<LLogColorCode>& colorCode)
	{
		if (level == LLogLevel::LOG_OFF)
			return false;
		else if (level > LLogLevel::LOG_INFO)
		{
			PrintLoggerError("%s: Invalid log level value of %d was set! Ignoring this call...", __FUNCTION__, (uint8_t)level);
			return false;
		}
		if (msg.size() == 0)
		{
			PrintLoggerError("%s: Empty list detected for argument \"msg\"! Ignoring this call...", __FUNCTION__);
			return false;
		}

		if (logLevel >= level)
		{
			std::lock_guard<std::mutex> guard(logMutex);

			char preMsgBuffer[64];
			memset(preMsgBuffer, '\0', sizeof(preMsgBuffer));

			size_t prefixLen = (showPrefix) ? strlen(LLogLevelPrefix[(uint8_t)level]) : 0;
			size_t logLevelCodeLen = 0;
			size_t colorResetLen = 0;
			size_t timestampLen = (showTimeStamp) ? TIMESTAMP_BUFF_LEN - 1 : 0;

			char* buffPtr = preMsgBuffer;
#ifdef IS_GNU
			logLevelCodeLen = strlen(logLevelColors[(uint8_t)level]);
			colorResetLen = strlen(LLogColor::COLOR_RESET);

			memcpy(buffPtr, logLevelColors[(uint8_t)level], logLevelCodeLen);
			buffPtr += logLevelCodeLen;
#endif
			if (timestampLen > 0)
			{
				WriteTimeStampToBuffer(buffPtr);
				buffPtr += timestampLen;
			}
			if (prefixLen > 0)
			{
				memcpy(buffPtr, LLogLevelPrefix[(uint8_t)level], prefixLen);
				buffPtr += prefixLen;
			}

			auto colorIter = colorCode.begin();

			switch (logType)
			{
				case LLogType::CONSOLE: case LLogType::CONSOLE_AND_FILE:
#ifdef IS_MSVC
					CONSOLE_SCREEN_BUFFER_INFO  consoleBufferInfo;
					GetConsoleScreenBufferInfo(ConsoleHandle, &consoleBufferInfo);
					defaultConsoleAttr = consoleBufferInfo.wAttributes;

					SetConsoleTextAttribute(ConsoleHandle, logLevelColors[(uint8_t)level]);
#endif
					fputs(preMsgBuffer, stdout);

					if (logType == LLogType::CONSOLE_AND_FILE)
					{
						logFile.open(logFilePath, std::ios::app);

						if (!logFile.is_open())
							PrintLoggerError("%s: Unable to create/open log file \"%s\"", __FUNCTION__, logFilePath.c_str());
						else
						{
							const char* ptr = &preMsgBuffer[logLevelCodeLen];
							logFile.write(ptr, timestampLen + prefixLen);
						}
					}

					for (auto s : msg)
					{
						if (s != nullptr && s[0] != '\0')
						{
#ifdef IS_MSVC
							SetConsoleTextAttribute(ConsoleHandle, (colorIter == colorCode.end()) ? defaultConsoleAttr : (WORD)(*colorIter));
							fputs(s, stdout);
#else						
							fputs((colorIter == colorCode.end()) ? LLogColor::COLOR_RESET : (*colorIter), stdout);
							fputs(s, stdout);
#endif							
							if (logFile.is_open())
								logFile << s;
						}

						if (colorIter != colorCode.end())
							colorIter++;
					}
#ifdef IS_MSVC
					SetConsoleTextAttribute(ConsoleHandle, defaultConsoleAttr);
					fputs("\n", stdout);
#else
					char postMsgBuffer[sizeof(LLogColor::COLOR_RESET) + 1];
					buffPtr = postMsgBuffer;

					memcpy(buffPtr, LLogColor::COLOR_RESET, colorResetLen);
					buffPtr += colorResetLen;
					memcpy(buffPtr, "\n", 2);
								
					fputs(postMsgBuffer, stdout);
#endif
					if (logFile.is_open())
					{
						logFile << std::endl;
						logFile.close();
					}

					break;
				case LLogType::FILE:
					logFile.open(logFilePath, std::ios::app);

					if (!logFile.is_open())
						PrintLoggerError("%s: Unable to create/open log file \"%s\"", __FUNCTION__, logFilePath.c_str());
					else
					{
						const char* ptr = &preMsgBuffer[logLevelCodeLen];
						logFile.write(ptr, timestampLen + prefixLen);

						for (auto& s : msg)
						{
							if (s != nullptr && s[0] != '\0')
								logFile << s;
						}

						logFile << std::endl;
						logFile.close();
					}
					break;
			}
		}

		return true;
	}
	
	/*
	* Description    :  Logs a formatted C string at the verbosity level defined in argument "level".
	*                :  NOTE: Formatting is exactly the same as calling printf.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	inline bool LogLine(const LLogLevel& level, const char* format, ...)
	{
		if (level == LLogLevel::LOG_OFF)
			return false;
		else if (level > LLogLevel::LOG_INFO)
		{
			PrintLoggerError("%s: Invalid log level value of %d was set! Ignoring this call...", __FUNCTION__, (uint8_t)level);
			return false;
		}
		
		if (format == nullptr || (format != nullptr && format[0] == '\0'))
		{
			PrintLoggerError("%s: An empty or invalid string has been entered! Ignoring this call...", __FUNCTION__);
			return false;
		}

		if (logLevel >= level)
		{
			std::lock_guard<std::mutex> guard(logMutex);

			va_list args;
			va_start(args, format);			
			size_t msgLen = (size_t)vsnprintf(nullptr, 0, format, args);
			size_t prefixLen = (showPrefix) ? strlen(LLogLevelPrefix[(uint8_t)level]) : 0;
			size_t colorCodeLen = 0;
			size_t colorResetLen = 0;
			uint8_t timestampLen = (showTimeStamp) ? TIMESTAMP_BUFF_LEN - 1 : 0;
#ifdef IS_GNU
			colorCodeLen = strlen(logLevelColors[(uint8_t)level]);
			colorResetLen = strlen(LLogColor::COLOR_RESET);
#endif
			size_t sizeRequired = colorCodeLen + TIMESTAMP_BUFF_LEN + prefixLen + msgLen + colorResetLen + 2;  //+ 2 to account for "\n\0".

#ifdef IS_MSVC
			CONSOLE_SCREEN_BUFFER_INFO  consoleBufferInfo;
			GetConsoleScreenBufferInfo(ConsoleHandle, &consoleBufferInfo);
			defaultConsoleAttr = consoleBufferInfo.wAttributes;
#endif

			if (!CheckOrIncreaseBufferSize(sizeRequired))	
			{
				va_end(args);
				return false;
			}
			
			//Write formatted strings to the buffer.
			char* buffPtr = &logBuffer[0];
#ifdef IS_GNU
			memcpy(buffPtr, logLevelColors[(uint8_t)level], colorCodeLen);
			buffPtr += colorCodeLen;
#endif
			if (timestampLen > 0)
			{
				WriteTimeStampToBuffer(buffPtr);
				buffPtr += timestampLen;
			}
			if (prefixLen > 0)
			{
				memcpy(buffPtr, LLogLevelPrefix[(uint8_t)level], prefixLen);
				buffPtr += prefixLen;
			}
			va_start(args, format);
			vsnprintf(buffPtr, msgLen + 1, format, args);
			buffPtr += msgLen;
			va_end(args);

#ifdef IS_GNU
			memcpy(buffPtr, LLogColor::COLOR_RESET, colorResetLen);
			buffPtr += colorResetLen;
			memcpy(buffPtr, "\n", 2);	// '\n' + '\0'
#endif

			switch (logType)
			{
				case LLogType::CONSOLE: case LLogType::CONSOLE_AND_FILE:
#ifdef IS_MSVC
					SetConsoleTextAttribute(ConsoleHandle, logLevelColors[(uint8_t)level]);
					fputs(logBuffer.data(), stdout);
					SetConsoleTextAttribute(ConsoleHandle, defaultConsoleAttr);
					fputs("\n", stdout);
#else
					fputs(logBuffer.data(), stdout);
#endif
					if (logType == LLogType::CONSOLE_AND_FILE)
					{
						logFile.open(logFilePath, std::ios::app);

						if (logFile.is_open())
						{
							const char* ptr = &logBuffer[colorCodeLen];
							logFile.write(ptr, timestampLen + prefixLen + msgLen);
							logFile << std::endl;
							logFile.close();
						}
						else
							PrintLoggerError("%s: Unable to create/open log file \"%s\"", __FUNCTION__, logFilePath.c_str());
					}
					break;
				case LLogType::FILE:
					logFile.open(logFilePath, std::ios::app);

					if (logFile.is_open())
					{
						const char* ptr = &logBuffer[colorCodeLen];
						logFile.write(ptr, timestampLen + prefixLen + msgLen);
						logFile << std::endl;
						logFile.close();
					}
					else
						PrintLoggerError("%s: Unable to create/open log file \"%s\"", __FUNCTION__, logFilePath.c_str());
					
					break;
			}
		}

		return true;
	}

private:
	LLogger(const LLogger&) = delete;
	LLogger& operator=(const LLogger&) = delete;
	
	std::vector<char> logBuffer;
	std::mutex        logMutex;
	std::mutex        errMutex;

	std::string       logFilePath;
	std::ofstream     logFile;
	std::array<LLogColorCode, 5> logLevelColors;
#ifdef IS_MSVC
	WORD              defaultConsoleAttr;
#endif
    LLogType          logType;
	LLogLevel         logLevel;
	bool              showPrefix;
	bool              showTimeStamp;

	/*
	* Description    :  Prints an error message as a C string.
	* Return         :  
	*/
	inline void PrintLoggerError(const char* format, ...)
	{
		constexpr char LLogClassPrefix[] = "[LLogger] ";
		LLogColorCode colorCode = LLogColor::RED_ON_BLACK;

		char buffer[LLOGGER_ERR_BUFFER_SIZE];
		memset(buffer, '\0', sizeof(buffer));

		std::lock_guard<std::mutex> guard(errMutex);

		size_t colorCodeLen = 0;
		size_t timestampLen = (showTimeStamp) ? TIMESTAMP_BUFF_LEN - 1 : 0;

		char* buffPtr = buffer;
#ifdef IS_GNU
		colorCodeLen = sizeof(LLogColor::RED_ON_BLACK) - 1;
		
		memcpy(buffPtr, colorCode, colorCodeLen);
		buffPtr += colorCodeLen;
#endif
		if (timestampLen > 0)
		{
			WriteTimeStampToBuffer(buffPtr);
			buffPtr += timestampLen;
		}

		memcpy(buffPtr, LLogClassPrefix, sizeof(LLogClassPrefix) - 1);
		buffPtr += sizeof(LLogClassPrefix) - 1;

		va_list args;
		va_start(args, format);			
		size_t msgLen = (size_t)vsnprintf(nullptr, 0, format, args);

		va_start(args, format);
		vsnprintf(buffPtr, msgLen + 1, format, args);
		va_end(args);

		buffPtr += msgLen;

#ifdef IS_MSVC
		SetConsoleTextAttribute(ConsoleHandle, (WORD)colorCode);
		fputs(buffer, stdout);
		SetConsoleTextAttribute(ConsoleHandle, defaultConsoleAttr);
		fputs("\n", stdout);
#else
		memcpy(buffPtr, LLogColor::COLOR_RESET, sizeof(LLogColor::COLOR_RESET) - 1);
		buffPtr += sizeof(LLogColor::COLOR_RESET) - 1;
		memcpy(buffPtr, "\n", 2);

		fputs(buffer, stdout);
#endif	
	}

	/*
	* Description    :  Checks if the log buffer size is adequate for the size in argument "setSize".
	*                   If the current buffer size is smaller, it will increase in steps.
	* Return         :  True = Successful execution, False = Error detected.
	*/
	inline bool CheckOrIncreaseBufferSize(const size_t& setSize)
	{
		if (setSize > LLOGGER_MAX_BUFFER_SIZE)
		{
			PrintLoggerError("%s: Unable to set buffer limit of %zd characters! The maximum is %zd.", __FUNCTION__, setSize, LLOGGER_MAX_BUFFER_SIZE);
			return false;
		}
		else if (setSize > logBuffer.size() && setSize <= LLOGGER_MAX_BUFFER_SIZE)
		{
			size_t factor = setSize / LLOGGER_BUFFER_STEP_SIZE;
			logBuffer.resize(minSizeOf(LLOGGER_BUFFER_STEP_SIZE * (factor + 1), LLOGGER_MAX_BUFFER_SIZE));

			return true;
		}
		else
			return true;
	}

	/*
	* Description    :  Writes a formatted string of the current system time to a buffer specified in the argument.
	* Return         :  
	*/
	inline void WriteTimeStampToBuffer(char* buff)
	{
		std::time_t timenow = std::time(nullptr);
		std::strftime(buff, TIMESTAMP_BUFF_LEN, "%H:%M:%S ", std::localtime(&timenow)); //Added a space at the end of the formatted string. 
	}

	//This function is declared for the purpose of avoiding the min/max macro compatibility issue across different compilers.
	template<typename T>
	inline T minSizeOf(const T& a, const T& b)
	{
		return (a < b) ? a : b;
	}
};

#endif	//_LLOGGER_H_
