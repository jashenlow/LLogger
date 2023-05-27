#include "../LLogger.h"
#include "gtest/gtest.h"
#include <cmath>

TEST(LogType, validInput)
{
    LLogger logger;

    LLogType newType = LLogType::CONSOLE_AND_FILE;

    bool res = logger.SetLogType(newType);

    EXPECT_TRUE(res && newType == logger.GetLogType());
}

TEST(LogType, negative)
{
    LLogger logger;

    LLogType defaultType = logger.GetLogType();

    bool res = logger.SetLogType((LLogType)-1);

    EXPECT_TRUE(!res && defaultType == logger.GetLogType());
}

TEST(LogType, tooLarge)
{
    LLogger logger;

    LLogType defaultType = logger.GetLogType();

    bool res = logger.SetLogType((LLogType)5);

    EXPECT_TRUE(!res && defaultType == logger.GetLogType());
}

TEST(LogFilePath, validInput)
{
    LLogger logger;

    std::string testFilePath = "testing/testLog.txt";
    bool res = logger.SetLogFilePath(testFilePath.c_str());

    EXPECT_TRUE(res && strcmp(testFilePath.c_str(), logger.GetLogFilePath()) == 0);
}

TEST(LogFilePath, nullInput)
{
    LLogger logger;

    std::string defaultFilePath = logger.GetLogFilePath();
    bool res = logger.SetLogFilePath(nullptr);

    EXPECT_TRUE(!res && strcmp(defaultFilePath.c_str(), logger.GetLogFilePath()) == 0);
}

TEST(LogFilePath, emptyStringInput)
{
    LLogger logger;

    std::string defaultFilePath = logger.GetLogFilePath();
    bool res = logger.SetLogFilePath("");

    EXPECT_TRUE(!res && strcmp(defaultFilePath.c_str(), logger.GetLogFilePath()) == 0);
}

TEST(ClearLogFile, ClearLogFileTest)
{
    LLogger logger;

    logger.SetLogType(LLogType::FILE);
    logger.LogLine(LLogLevel::LOG_INFO, true, "This is a test logging sentnece.");
    logger.LogLine(LLogLevel::LOG_WARN, true, "Test print numbers (%d, %d, %d).", 1, 2, 3);
    
    std::ifstream logFile;
    std::stringstream logFileText;

    logFile.open(logger.GetLogFilePath(), std::ios::in);
    if (logFile.is_open())
    {
        logFileText << logFile.rdbuf();
        logFile.close();
    }
    printf("Log File Text (Before): %s\n", logFileText.str().c_str());

    ASSERT_STRNE(logFileText.str().c_str(), "");    //Assert in case the log file is already empty.
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

TEST(LogLevel, negative)
{
    LLogger logger;

    LLogLevel defaultLevel = logger.GetLogLevel();

    bool res = logger.SetLogLevel((LLogLevel)-1);

    EXPECT_TRUE(!res && defaultLevel == logger.GetLogLevel());
}

TEST(LogLevel, tooLarge)
{
    LLogger logger;

    LLogLevel defaultLevel = logger.GetLogLevel();

    bool res = logger.SetLogLevel((LLogLevel)10);

    EXPECT_TRUE(!res && defaultLevel == logger.GetLogLevel());
}

TEST(LogLevelColor, validInput)
{
    LLogger logger;

    LLogLevel setLogLevel = LLogLevel::LOG_WARN;
    
#ifdef IS_MSVC
    LLogColor newColorCode = LLogColor::INTENSE_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor(setLogLevel, newColorCode);
    EXPECT_TRUE(res && logger.GetLogLevelColor(setLogLevel) == newColorCode);
#else
    const char* newColorCode = LLogColor::INTENSE_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor(setLogLevel, newColorCode);
    EXPECT_TRUE(res && strcmp(logger.GetLogLevelColor(setLogLevel), newColorCode) == 0);
#endif
}

TEST(LogLevelColor, zeroLogLevel)
{
    LLogger logger;

#ifdef IS_MSVC
    LLogColor newColorCode = LLogColor::INTENSE_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && logger.GetLogLevelColor((LLogLevel)0) != newColorCode);
#else
    const char* newColorCode = LLogColor::INTENSE_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor((LLogLevel)0), newColorCode) != 0);
#endif    
}

TEST(LogLevelColor, tooLargeLogLevel)
{
    LLogger logger;

#ifdef IS_MSVC
    LLogColor newColorCode = LLogColor::INTENSE_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && logger.GetLogLevelColor((LLogLevel)5) != newColorCode);
#else
    const char* newColorCode = LLogColor::INTENSE_MAGENTA_ON_BLACK;

    bool res = logger.SetLogLevelColor((LLogLevel)0, newColorCode);
    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor((LLogLevel)6), newColorCode) != 0);
#endif
}
#ifdef IS_GNU
TEST(LogLevelColor, nullColorCode)
{
    LLogger logger;

    const char* oldColorCode = logger.GetLogLevelColor(LLogLevel::LOG_INFO);
    bool res = logger.SetLogLevelColor(LLogLevel::LOG_INFO, nullptr);

    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor(LLogLevel::LOG_INFO), oldColorCode) == 0);
}

TEST(LogLevelColor, emptyString)
{
    LLogger logger;

    const char* oldColorCode = logger.GetLogLevelColor(LLogLevel::LOG_INFO);
    bool res = logger.SetLogLevelColor(LLogLevel::LOG_INFO, "");

    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor(LLogLevel::LOG_INFO), oldColorCode) == 0);
}

TEST(LogLevelColor, wordString)
{
    LLogger logger;

    const char* oldColorCode = logger.GetLogLevelColor(LLogLevel::LOG_INFO);
    bool res = logger.SetLogLevelColor(LLogLevel::LOG_INFO, "blahblah");

    EXPECT_TRUE(!res && strcmp(logger.GetLogLevelColor(LLogLevel::LOG_INFO), oldColorCode) == 0);
}
#endif

TEST(LogBufferLimit, validSize)
{
    LLogger logger;
    std::string dummyStr;
    
    size_t newSize = LLOGGER_MAX_CHAR_LIMIT;

    bool res = logger.SetLogBufferLimit(newSize);

    EXPECT_TRUE(res && logger.GetLogBufferLimit() == newSize);
}

TEST(LogBufferLimit, inValidSize)
{
    LLogger logger;
    std::string dummyStr;
    
    size_t newSize = LLOGGER_MAX_CHAR_LIMIT + 1;

    bool res = logger.SetLogBufferLimit(newSize);

    EXPECT_TRUE(!res && logger.GetLogBufferLimit() < newSize);
}

TEST(LogLine, validString)
{
    LLogger logger;
    std::string testStr("This is a test print string.");

    EXPECT_TRUE(logger.LogLine(LLogLevel::LOG_INFO, true, testStr.c_str()));
}

TEST(LogLine, bufferResize)
{
    LLogger logger;
    std::string testStr(LLOGGER_PRINTF_CHAR_LIMIT + 1, 'a');

    bool res = logger.LogLine(LLogLevel::LOG_INFO, true, testStr.c_str());

    EXPECT_TRUE(res && logger.GetLogBufferLimit() == (LLOGGER_PRINTF_CHAR_LIMIT + LLOGGER_BUFFER_STEP_SIZE));
}

TEST(LogLine, LOG_OFF)
{
    LLogger logger;
    std::string testStr("This is a test print string.");

    EXPECT_FALSE(logger.LogLine(LLogLevel::LOG_OFF, true, testStr.c_str()));
}

TEST(LogLine, nullptrString)
{
    LLogger logger;

    EXPECT_FALSE(logger.LogLine(LLogLevel::LOG_INFO, true, nullptr));
}

TEST(LogLine, emptyString)
{
    LLogger logger;

    EXPECT_FALSE(logger.LogLine(LLogLevel::LOG_INFO, true, ""));
}

TEST(LogLine, includePrefix)
{
    LLogger logger;

    logger.SetLogType(LLogType::CONSOLE_AND_FILE);
    bool res = logger.LogLine(LLogLevel::LOG_INFO, true, "This is a test print string.");

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
    bool res = logger.LogLine(LLogLevel::LOG_INFO, false, "This is a test print string.");

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


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

