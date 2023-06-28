#include "../LLogger.h"

#include <thread>

void LogLineTest(LLogger& logger, const LLogLevel& level)
{
    for (int i = 0; i < 1000; i++)
    {
        logger.LogLine(level, "Test %s (%d)", __FUNCTION__, i);
    }
}

void LogLineColorsTest(LLogger& logger, const LLogLevel& level)
{
    for (int i = 0; i < 1000; i++)
    {
        logger.LogLineColors(level, {"Test ", __FUNCTION__ , std::to_string(i).c_str() }, {LLogColor::BOLD_MAGENTA_ON_BLACK, LLogColor::BOLD_GREEN_ON_BLACK, LLogColor::BOLD_YELLOW_ON_BLACK});
    }
}

int main(int argc, char** argv)
{
    LLogger logger;

    logger.SetLogType(LLogType::CONSOLE_AND_FILE);
    //logger.SetShowLogPrefix(false);
    logger.SetShowTimeStamp(true);

    if (logger.GetLogType() != LLogType::CONSOLE)
        logger.ClearLogFile();

    std::thread t1 = std::thread(LogLineTest, std::ref(logger), LLogLevel::LOG_ERROR);
    std::thread t2 = std::thread(LogLineTest, std::ref(logger), LLogLevel::LOG_WARN);
    std::thread t3 = std::thread(LogLineTest, std::ref(logger), LLogLevel::LOG_INFO);

    t1.join();
    t2.join();
    t3.join();

    t1 = std::thread(LogLineColorsTest, std::ref(logger), LLogLevel::LOG_ERROR);
    t2 = std::thread(LogLineColorsTest, std::ref(logger), LLogLevel::LOG_WARN);
    t3 = std::thread(LogLineColorsTest, std::ref(logger), LLogLevel::LOG_INFO);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}