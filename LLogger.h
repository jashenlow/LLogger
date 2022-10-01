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

#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <vector>
#include <mutex>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__NT__)
#define IS_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#include <Windows.h>
#include <wincon.h>

#define FOREGROUND_WHITE			(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_YELLOW       	(FOREGROUND_RED | FOREGROUND_GREEN)
#define FOREGROUND_CYAN		        (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define FOREGROUND_MAGENTA	        (FOREGROUND_RED | FOREGROUND_BLUE)
#define FOREGROUND_BLACK			0x0000

#define FOREGROUND_INTENSE_RED		(FOREGROUND_RED | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_GREEN	(FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_BLUE		(FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_WHITE	(FOREGROUND_WHITE | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_YELLOW	(FOREGROUND_YELLOW | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_CYAN		(FOREGROUND_CYAN | FOREGROUND_INTENSITY)
#define FOREGROUND_INTENSE_MAGENTA	(FOREGROUND_MAGENTA | FOREGROUND_INTENSITY)

#define BACKGROUND_WHITE			(BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN)
#define BACKGROUND_YELLOW	        (BACKGROUND_RED | BACKGROUND_GREEN)
#define BACKGROUND_CYAN		        (BACKGROUND_BLUE | BACKGROUND_GREEN)
#define BACKGROUND_MAGENTA	        (BACKGROUND_RED | BACKGROUND_BLUE)
#define BACKGROUND_BLACK			0x0000

#define BACKGROUND_INTENSE_RED		(BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_GREEN	(BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_BLUE		(BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_WHITE	(BACKGROUND_WHITE | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_YELLOW	(BACKGROUND_YELLOW | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_CYAN		(BACKGROUND_CYAN | BACKGROUND_INTENSITY)
#define BACKGROUND_INTENSE_MAGENTA	(BACKGROUND_MAGENTA | BACKGROUND_INTENSITY)

#define ConsoleHandle GetStdHandle(STD_OUTPUT_HANDLE)

typedef std::map<uint8_t, int> LogLevelColorMap;

#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
#define IS_UNIX

#include <stdarg.h>

#define FOREGROUND_GRAY				"\033[0;30m"
#define FOREGROUND_RED				"\033[0;31m"
#define FOREGROUND_GREEN			"\033[0;32m"
#define FOREGROUND_YELLOW       	"\033[0;33m"
#define FOREGROUND_BLUE				"\033[0;34m"
#define FOREGROUND_MAGENTA	        "\033[0;35m"
#define FOREGROUND_CYAN		        "\033[0;36m"
#define FOREGROUND_WHITE			"\033[0;37m"

#define FOREGROUND_INTENSE_GRAY		"\033[0;90m"
#define FOREGROUND_INTENSE_RED		"\033[0;91m"
#define FOREGROUND_INTENSE_GREEN	"\033[0;92m"
#define FOREGROUND_INTENSE_YELLOW	"\033[0;93m"
#define FOREGROUND_INTENSE_BLUE		"\033[0;94m"
#define FOREGROUND_INTENSE_MAGENTA	"\033[0;95m"
#define FOREGROUND_INTENSE_CYAN		"\033[0;96m"
#define FOREGROUND_INTENSE_WHITE	"\033[0;97m"

#define BACKGROUND_BLACK			"\033[40m"
#define BACKGROUND_RED				"\033[41m"
#define BACKGROUND_GREEN			"\033[42m"
#define BACKGROUND_YELLOW	        "\033[43m"
#define BACKGROUND_BLUE				"\033[44m"
#define BACKGROUND_MAGENTA	        "\033[45m"
#define BACKGROUND_CYAN		        "\033[46m"
#define BACKGROUND_WHITE			"\033[47m"

#define BACKGROUND_INTENSE_BLACK	"\033[100m"
#define BACKGROUND_INTENSE_RED		"\033[101m"
#define BACKGROUND_INTENSE_GREEN	"\033[102m"
#define BACKGROUND_INTENSE_YELLOW	"\033[103m"
#define BACKGROUND_INTENSE_BLUE		"\033[104m"
#define BACKGROUND_INTENSE_MAGENTA	"\033[105m"
#define BACKGROUND_INTENSE_CYAN		"\033[106m"
#define BACKGROUND_INTENSE_WHITE	"\033[107m"

#define COLOR_RESET					"\033[0m"

typedef std::map<uint8_t, std::pair<std::string, std::string>> LogLevelColorMap;	//Level, <bgColor, fgColor>

#endif

constexpr size_t LLOGGER_DEFAULT_CHAR_LIMIT		= 100000;
constexpr const char* LLOGGER_DEFAULT_FILE_PATH = "./log.txt";

enum class LLogType : uint8_t
{
	CONSOLE				= 0,
	FILE				= 1,
	CONSOLE_AND_FILE	= 2
};

enum LLogLevel : uint8_t
{
	LOG_FATAL	= 1,
	LOG_ERROR	= 2,
	LOG_WARN	= 3,
	LOG_INFO	= 4
};
constexpr std::array<const char*, 5> LLogLevelPrefix = { "[OFF] ", "[FATAL] ", "[ERROR] ", "[WARN] ", "[INFO] " };

class LLogger
{
public:
	const char* GetClassStr() { return "LLogger"; }

	static LLogger* GetInstance()
	{
		if (instance == nullptr)
			instance = new LLogger();

		return instance;
	}

	static bool DestroyInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}

		return (instance == nullptr);
	}

	void SetLogType(const LLogType& newType)
	{
		logType = newType;
	}

	const LLogType& GetLogType() const
	{
		return logType;
	}

	//Include file extensionn this argument. (e.g.: .txt, .ini)
	void SetLogFilePath(const char* newPath)
	{
		logFilePath = newPath;
	}

	const char* GetLogFilePath() const
	{
		return logFilePath.c_str();
	}

	void ClearLogFile()
	{
		if ((logType == LLogType::FILE) || (logType == LLogType::CONSOLE_AND_FILE))
		{
			if (logFilePath.empty())
				logFilePath = LLOGGER_DEFAULT_FILE_PATH;

			logFile.open(logFilePath, std::ios::trunc);

			if (logFile.is_open())
				logFile.close();
			else
				PrintLoggerError(BACKGROUND_BLACK, FOREGROUND_RED, "Unable to create/open log file \"%s\"", logFilePath.c_str());
		}
	}

/*
* Verbosity Levels:
*   0 - Does not log anything.
*   1 - Only logs [FATAL] level.
*   2 - Logs [FATAL] and [ERROR] levels.
*   3 - Logs [FATAL], [ERROR], and [WARN] levels.
*   4 - Logs all levels.
*/
	void SetVerbosity(const uint8_t& newVerbosity)
	{
		verbosity = (newVerbosity <= LLogLevel::LOG_INFO) ? newVerbosity : LLogLevel::LOG_INFO;
	}

/*
* Verbosity Levels:
*   0 - Does not log anything.
*   1 - Only logs [FATAL] level.
*   2 - Logs [FATAL] and [ERROR] levels.
*   3 - Logs [FATAL], [ERROR], and [WARN] levels.
*   4 - Logs all levels.
*/
	const uint8_t& GetVerbosity() const
	{
		return verbosity;
	}

#ifdef IS_WINDOWS
	void SetLogLevelColor(const LLogLevel& level, const int& colorCode)
	{
		logLevelColors[level] = colorCode;
	}

	const int& GetLogLevelColor(const LLogLevel& level)
	{
		return logLevelColors[level];
	}
#else
	void SetLogLevelColor(const LLogLevel& level, const char* bgCode, const char* fgCode)
	{
		logLevelColors[level].first		= bgCode;
		logLevelColors[level].second	= fgCode;
	}

	const std::pair<std::string, std::string>& GetLogLevelColor(const LLogLevel& level)
	{
		return logLevelColors[level];
	}
#endif

	void SetLogBufferLimit(const size_t& size)
	{
		logBuffer.resize(size);
	}

	size_t GetLogBufferLimit() const
	{
		return logBuffer.size();
	}

	void LogLine(const LLogLevel& level, const char* format, ...)
	{
		if (instance != nullptr)
		{
			logMutex.lock();

			if (verbosity >= level)
			{
				va_list args;
				va_start(args, format);
				vsnprintf(logBuffer.data(), logBuffer.size(), format, args);
				va_end(args);
				
				switch (logType)
				{
					case LLogType::CONSOLE: case LLogType::CONSOLE_AND_FILE:
#ifdef IS_WINDOWS
						SetConsoleTextAttribute(ConsoleHandle, logLevelColors[level]);
						printf("%s%s\n", LLogLevelPrefix[level], logBuffer.data());
						SetConsoleTextAttribute(ConsoleHandle, initialConsoleAttr);
#else
						printf("%s%s%s%s%s\n", logLevelColors[level].first.c_str(), logLevelColors[level].second.c_str(), LLogLevelPrefix[level], logBuffer.data(), COLOR_RESET);
#endif
						if (logType == LLogType::CONSOLE_AND_FILE)
						{
							if (logFilePath.empty())
								logFilePath = LLOGGER_DEFAULT_FILE_PATH;

							logFile.open(logFilePath, std::ios::app);

							if (logFile.is_open())
							{
								logFile << LLogLevelPrefix[level] << logBuffer.data() << std::endl;
								logFile.close();
							}
							else
								PrintLoggerError(BACKGROUND_BLACK, FOREGROUND_RED, "Unable to create/open log file \"%s\"", logFilePath.c_str());
						}
						break;
					case LLogType::FILE:
						if (logFilePath.empty())
							logFilePath = LLOGGER_DEFAULT_FILE_PATH;

						logFile.open(logFilePath, std::ios::app);

						if (logFile.is_open())
						{
							logFile << LLogLevelPrefix[level] << logBuffer.data() << std::endl;
							logFile.close();
						}
						else
							PrintLoggerError(BACKGROUND_BLACK, FOREGROUND_RED, "Unable to create/open log file \"%s\"", logFilePath.c_str());
						break;
				}
			}

			logMutex.unlock();
		}
	}

private:
	LLogger()
	{
#ifdef IS_WINDOWS
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(ConsoleHandle, &info);
		initialConsoleAttr = info.wAttributes;

		logLevelColors[LLogLevel::LOG_FATAL]	= BACKGROUND_INTENSE_RED | FOREGROUND_INTENSE_WHITE;
		logLevelColors[LLogLevel::LOG_ERROR]	= BACKGROUND_BLACK | FOREGROUND_INTENSE_RED;
		logLevelColors[LLogLevel::LOG_WARN]		= BACKGROUND_BLACK | FOREGROUND_INTENSE_YELLOW;
		logLevelColors[LLogLevel::LOG_INFO]		= BACKGROUND_BLACK | FOREGROUND_INTENSE_CYAN;
#else

		logLevelColors[LLogLevel::LOG_FATAL]	= std::make_pair(BACKGROUND_INTENSE_RED, FOREGROUND_INTENSE_WHITE);
		logLevelColors[LLogLevel::LOG_ERROR]	= std::make_pair(BACKGROUND_BLACK, FOREGROUND_INTENSE_RED);
		logLevelColors[LLogLevel::LOG_WARN]		= std::make_pair(BACKGROUND_BLACK, FOREGROUND_INTENSE_YELLOW);
		logLevelColors[LLogLevel::LOG_INFO]		= std::make_pair(BACKGROUND_BLACK,  FOREGROUND_INTENSE_CYAN);
#endif
		//Set default values
		logType = LLogType::CONSOLE;
		verbosity = 4;

		SetLogBufferLimit(LLOGGER_DEFAULT_CHAR_LIMIT);
	}
	~LLogger()
	{

	}
	LLogger(const LLogger&) = delete;
	void operator=(const LLogger&) = delete;

	static LLogger* instance;
	
	LLogType				logType;
	uint8_t					verbosity;
	std::string				logFilePath;
	std::ofstream			logFile;
	LogLevelColorMap		logLevelColors;
	int						initialConsoleAttr;	//Windows only
	std::vector<char>		logBuffer;
	std::mutex				logMutex;

	template <typename T>
	inline void PrintLoggerError(T bgCode, T fgCode, const char* format, ...)
	{
		if (instance != nullptr)
		{
			logMutex.lock();

			va_list args;
			va_start(args, format);
			vsnprintf(logBuffer.data(), logBuffer.size(), format, args);
			va_end(args);

#ifdef IS_WINDOWS
			SetConsoleTextAttribute(ConsoleHandle, bgCode | fgCode);
			printf("[%s]: %s\n", GetClassStr(), logBuffer.data());
			SetConsoleTextAttribute(ConsoleHandle, initialConsoleAttr);
#else
			printf("%s%s[%s]: %s%s\n", bgCode, fgCode, GetClassStr(), logBuffer.data(), COLOR_RESET);
#endif
			logMutex.unlock();
		}
	}
};

LLogger* LLogger::instance = nullptr;

#endif	//_LLOGGER_H_
