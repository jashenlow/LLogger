#include "../LLogger.h"
#include <gtest/gtest.h>
#include <cmath>

#ifdef IS_MSVC
#pragma comment(lib, "gtest.lib")
#pragma comment(lib, "gtest_main.lib")
#endif

TEST(LogType, validInput)
{
    LLogger logger;

    LLogType newType = LLogType::CONSOLE_AND_FILE;

    bool res = logger.SetLogType(newType);

    EXPECT_TRUE(res && newType == logger.GetLogType());
}

TEST(LogType, invalidInput)
{
    LLogger logger;

    LLogType defaultType = logger.GetLogType();
    bool res[2] = {true, true};

    res[0] = logger.SetLogType((LLogType)-1); // Too low
    res[1] = logger.SetLogType((LLogType)4);  // Too high

    EXPECT_TRUE(!res[0] && !res[1] && defaultType == logger.GetLogType());
}

TEST(LogFilePath, validInput)
{
    LLogger logger;

    std::string testFilePath = "testing/testLog.txt";
    bool res = logger.SetLogFilePath(testFilePath.c_str());

    EXPECT_TRUE(res && strcmp(testFilePath.c_str(), logger.GetLogFilePath()) == 0);
}

TEST(LogFilePath, invalidInput)
{
    LLogger logger;

    std::string defaultFilePath = logger.GetLogFilePath();
    bool res[2] = {true, true};

    res[0] = logger.SetLogFilePath(nullptr); // nullptr input
    res[1] = logger.SetLogFilePath("");      // empty string

    EXPECT_TRUE(!res[0] && !res[1] && strcmp(defaultFilePath.c_str(), logger.GetLogFilePath()) == 0);
}

TEST(ClearLogFile, ClearLogFileTest)
{
    LLogger logger;

    logger.SetLogType(LLogType::FILE);
    logger.LogLine(LLogLevel::LOG_INFO, "This is a test logging sentnece.");
    logger.LogLine(LLogLevel::LOG_WARN, "Test print numbers (%d, %d, %d).", 1, 2, 3);

    std::ifstream logFile;
    std::stringstream logFileText;

    logFile.open(logger.GetLogFilePath(), std::ios::in);
    if (logFile.is_open())
    {
        logFileText << logFile.rdbuf();
        logFile.close();
    }
    printf("Log File Text (Before): %s\n", logFileText.str().c_str());

    ASSERT_STRNE(logFileText.str().c_str(), ""); // Assert in case the log file is already empty.
    logFileText.str("");

    bool res = logger.ClearLogFile();

    logFile.open(logger.GetLogFilePath(), std::ios::in);
    if (logFile.is_open())
    {
        logFileText << logFile.rdbuf();
        logFile.close();
    }

    printf("Log File Text (After): %s\n", logFileText.str().c_str());
    EXPECT_TRUE(res && logFileText.str().empty());
}

TEST(LogLevel, validInput)
{
    LLogger logger;

    LLogLevel newLevel = LLogLevel::LOG_WARN;

    bool res = logger.SetLogLevel(newLevel);

    EXPECT_TRUE(res && newLevel == logger.GetLogLevel());
}

TEST(LogLevel, invalidInput)
{
    LLogger logger;

    LLogLevel defaultLevel = logger.GetLogLevel();
    bool res[2] = {true, true};
    res[0] = logger.SetLogLevel((LLogLevel)-1); // Too low
    res[1] = logger.SetLogLevel((LLogLevel)10); // Too high

    EXPECT_TRUE(!res[0] && !res[1] && defaultLevel == logger.GetLogLevel());
}

TEST(LogLevelColor, validInput)
{
    LLogger logger;

    LLogLevel setLogLevel = LLogLevel::LOG_WARN;

#ifdef IS_MSVC
    LLogColor newColorCode = LLogColor::BOLD_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor(setLogLevel, newColorCode);
    EXPECT_TRUE(res && logger.GetLogLevelColor(setLogLevel) == newColorCode);
#else
    auto newColorCode = LLogColor::BOLD_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor(setLogLevel, newColorCode);
    EXPECT_TRUE(res && strcmp(logger.GetLogLevelColor(setLogLevel), newColorCode) == 0);
#endif
}

TEST(LogLevelColor, zeroLogLevel)
{
    LLogger logger;

#ifdef IS_MSVC
    LLogColor newColorCode = LLogColor::BOLD_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && logger.GetLogLevelColor((LLogLevel)0) != newColorCode);
#else
    auto newColorCode = LLogColor::BOLD_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor((LLogLevel)0), newColorCode) != 0);
#endif
}

TEST(LogLevelColor, tooLargeLogLevel)
{
    LLogger logger;

#ifdef IS_MSVC
    LLogColor newColorCode = LLogColor::BOLD_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && logger.GetLogLevelColor((LLogLevel)6) != newColorCode);
#else
    auto newColorCode = LLogColor::BOLD_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor((LLogLevel)6), newColorCode) != 0);
#endif
}
#ifdef IS_GNU
TEST(LogLevelColor, nullColorCode)
{
    LLogger logger;

    auto oldColorCode = logger.GetLogLevelColor(LLogLevel::LOG_INFO);
    bool res = logger.SetLogLevelColor(LLogLevel::LOG_INFO, nullptr);

    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor(LLogLevel::LOG_INFO), oldColorCode) == 0);
}

TEST(LogLevelColor, emptyString)
{
    LLogger logger;

    auto oldColorCode = logger.GetLogLevelColor(LLogLevel::LOG_INFO);
    bool res = logger.SetLogLevelColor(LLogLevel::LOG_INFO, "");

    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor(LLogLevel::LOG_INFO), oldColorCode) == 0);
}

TEST(LogLevelColor, wordString)
{
    LLogger logger;

    auto oldColorCode = logger.GetLogLevelColor(LLogLevel::LOG_INFO);
    bool res = logger.SetLogLevelColor(LLogLevel::LOG_INFO, "blahblah");

    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor(LLogLevel::LOG_INFO), oldColorCode) == 0);
}
#endif

TEST(LogBufferSize, validSize)
{
    LLogger logger;
    std::string dummyStr;

    size_t newSize = LLOGGER_MAX_BUFFER_SIZE;

    bool res = logger.SetLogBufferSize(newSize);

    EXPECT_TRUE(res && logger.GetLogBufferSize() == newSize);
}

TEST(LogBufferSize, inValidSize)
{
    LLogger logger;
    std::string dummyStr;
    size_t newSize = LLOGGER_MAX_BUFFER_SIZE + 1;

    bool res = logger.SetLogBufferSize(newSize);

    EXPECT_TRUE(!res && logger.GetLogBufferSize() < newSize);
}

TEST(LogLine, validString)
{
    LLogger logger;
    std::string testStr("This is a test print string.");

    EXPECT_TRUE(logger.LogLine(LLogLevel::LOG_INFO, testStr.c_str()));
}

TEST(LogLine, bufferResize)
{
    LLogger logger;
    std::string testStr(LLOGGER_DEFAULT_BUFFER_SIZE + 1, 'a');

    bool res = logger.LogLine(LLogLevel::LOG_INFO, testStr.c_str());

    EXPECT_TRUE(res && logger.GetLogBufferSize() == (LLOGGER_DEFAULT_BUFFER_SIZE + LLOGGER_BUFFER_STEP_SIZE));
}

TEST(LogLine, LOG_OFF)
{
    LLogger logger;
    std::string testStr("This is a test print string.");

    EXPECT_FALSE(logger.LogLine(LLogLevel::LOG_OFF, testStr.c_str()));
}

TEST(LogLine, nullptrString)
{
    LLogger logger;

    EXPECT_FALSE(logger.LogLine(LLogLevel::LOG_INFO, nullptr));
}

TEST(LogLine, emptyString)
{
    LLogger logger;

    EXPECT_FALSE(logger.LogLine(LLogLevel::LOG_INFO, ""));
}

TEST(LogLine, includePrefix)
{
    LLogger logger;

    logger.SetLogType(LLogType::CONSOLE_AND_FILE);
    logger.SetShowLogPrefix(true);
    bool res = logger.LogLine(LLogLevel::LOG_INFO, "This is a test print string.");

    std::ifstream logFile;
    logFile.open(logger.GetLogFilePath());

    ASSERT_TRUE(logFile.is_open());
    std::stringstream ss;
    ss << logFile.rdbuf();
    logFile.close();
    logger.ClearLogFile();

    size_t prefixIndex = ss.str().find(LLogLevelPrefix[(uint8_t)LLogLevel::LOG_INFO]);

    EXPECT_TRUE(res && prefixIndex != std::string::npos);
}

TEST(LogLine, excludePrefix)
{
    LLogger logger;

    logger.SetLogType(LLogType::CONSOLE_AND_FILE);
    logger.SetShowLogPrefix(false);
    bool res = logger.LogLine(LLogLevel::LOG_INFO, "This is a test print string.");

    std::ifstream logFile;
    logFile.open(logger.GetLogFilePath());

    ASSERT_TRUE(logFile.is_open());
    std::stringstream ss;
    ss << logFile.rdbuf();
    logFile.close();
    logger.ClearLogFile();

    size_t prefixIndex = ss.str().find(LLogLevelPrefix[(uint8_t)LLogLevel::LOG_INFO]);

    EXPECT_TRUE(res && prefixIndex == std::string::npos);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
