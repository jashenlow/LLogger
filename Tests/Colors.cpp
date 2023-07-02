#include "../LLogger.h"

int main(int argc, char **argv)
{
    LLogger logger;

    logger.SetLogType(LLogType::CONSOLE_AND_FILE);
    // logger.SetShowLogPrefix(false);
    logger.SetShowTimeStamp(true);

    if (logger.GetLogType() != LLogType::CONSOLE)
        logger.ClearLogFile();

    logger.SetLogLevel(LLogLevel::LOG_DEBUG);

    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_GREEN"}, {LLogColor::RED_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BLUE"}, {LLogColor::RED_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_WHITE"}, {LLogColor::RED_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_YELLOW"}, {LLogColor::RED_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_CYAN"}, {LLogColor::RED_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_MAGENTA"}, {LLogColor::RED_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BLACK"}, {LLogColor::RED_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_RED"}, {LLogColor::RED_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_GREEN"}, {LLogColor::RED_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_BLUE"}, {LLogColor::RED_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_WHITE"}, {LLogColor::RED_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_YELLOW"}, {LLogColor::RED_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_CYAN"}, {LLogColor::RED_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_MAGENTA"}, {LLogColor::RED_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED_ON_BOLD_BLACK"}, {LLogColor::RED_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_RED"}, {LLogColor::GREEN_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BLUE"}, {LLogColor::GREEN_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_WHITE"}, {LLogColor::GREEN_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_YELLOW"}, {LLogColor::GREEN_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_CYAN"}, {LLogColor::GREEN_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_MAGENTA"}, {LLogColor::GREEN_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BLACK"}, {LLogColor::GREEN_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_RED"}, {LLogColor::GREEN_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_GREEN"}, {LLogColor::GREEN_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_BLUE"}, {LLogColor::GREEN_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_WHITE"}, {LLogColor::GREEN_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_YELLOW"}, {LLogColor::GREEN_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_CYAN"}, {LLogColor::GREEN_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_MAGENTA"}, {LLogColor::GREEN_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"GREEN_ON_BOLD_BLACK"}, {LLogColor::GREEN_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_RED"}, {LLogColor::BLUE_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_GREEN"}, {LLogColor::BLUE_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_WHITE"}, {LLogColor::BLUE_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_YELLOW"}, {LLogColor::BLUE_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_CYAN"}, {LLogColor::BLUE_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_MAGENTA"}, {LLogColor::BLUE_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BLACK"}, {LLogColor::BLUE_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_RED"}, {LLogColor::BLUE_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_GREEN"}, {LLogColor::BLUE_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_BLUE"}, {LLogColor::BLUE_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_WHITE"}, {LLogColor::BLUE_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_YELLOW"}, {LLogColor::BLUE_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_CYAN"}, {LLogColor::BLUE_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_MAGENTA"}, {LLogColor::BLUE_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLUE_ON_BOLD_BLACK"}, {LLogColor::BLUE_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_RED"}, {LLogColor::WHITE_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_GREEN"}, {LLogColor::WHITE_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BLUE"}, {LLogColor::WHITE_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_YELLOW"}, {LLogColor::WHITE_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_CYAN"}, {LLogColor::WHITE_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_MAGENTA"}, {LLogColor::WHITE_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BLACK"}, {LLogColor::WHITE_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_RED"}, {LLogColor::WHITE_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_GREEN"}, {LLogColor::WHITE_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_BLUE"}, {LLogColor::WHITE_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_WHITE"}, {LLogColor::WHITE_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_YELLOW"}, {LLogColor::WHITE_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_CYAN"}, {LLogColor::WHITE_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_MAGENTA"}, {LLogColor::WHITE_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"WHITE_ON_BOLD_BLACK"}, {LLogColor::WHITE_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_RED"}, {LLogColor::YELLOW_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_GREEN"}, {LLogColor::YELLOW_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BLUE"}, {LLogColor::YELLOW_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_WHITE"}, {LLogColor::YELLOW_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_CYAN"}, {LLogColor::YELLOW_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_MAGENTA"}, {LLogColor::YELLOW_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BLACK"}, {LLogColor::YELLOW_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_RED"}, {LLogColor::YELLOW_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_GREEN"}, {LLogColor::YELLOW_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_BLUE"}, {LLogColor::YELLOW_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_WHITE"}, {LLogColor::YELLOW_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_YELLOW"}, {LLogColor::YELLOW_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_CYAN"}, {LLogColor::YELLOW_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_MAGENTA"}, {LLogColor::YELLOW_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"YELLOW_ON_BOLD_BLACK"}, {LLogColor::YELLOW_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_RED"}, {LLogColor::CYAN_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_GREEN"}, {LLogColor::CYAN_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BLUE"}, {LLogColor::CYAN_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_WHITE"}, {LLogColor::CYAN_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_YELLOW"}, {LLogColor::CYAN_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_MAGENTA"}, {LLogColor::CYAN_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BLACK"}, {LLogColor::CYAN_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_RED"}, {LLogColor::CYAN_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_GREEN"}, {LLogColor::CYAN_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_BLUE"}, {LLogColor::CYAN_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_WHITE"}, {LLogColor::CYAN_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_YELLOW"}, {LLogColor::CYAN_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_CYAN"}, {LLogColor::CYAN_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_MAGENTA"}, {LLogColor::CYAN_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"CYAN_ON_BOLD_BLACK"}, {LLogColor::CYAN_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_RED"}, {LLogColor::MAGENTA_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_GREEN"}, {LLogColor::MAGENTA_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BLUE"}, {LLogColor::MAGENTA_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_WHITE"}, {LLogColor::MAGENTA_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_YELLOW"}, {LLogColor::MAGENTA_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_CYAN"}, {LLogColor::MAGENTA_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BLACK"}, {LLogColor::MAGENTA_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_RED"}, {LLogColor::MAGENTA_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_GREEN"}, {LLogColor::MAGENTA_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_BLUE"}, {LLogColor::MAGENTA_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_WHITE"}, {LLogColor::MAGENTA_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_YELLOW"}, {LLogColor::MAGENTA_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_CYAN"}, {LLogColor::MAGENTA_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_MAGENTA"}, {LLogColor::MAGENTA_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"MAGENTA_ON_BOLD_BLACK"}, {LLogColor::MAGENTA_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_RED"}, {LLogColor::BLACK_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_GREEN"}, {LLogColor::BLACK_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BLUE"}, {LLogColor::BLACK_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_WHITE"}, {LLogColor::BLACK_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_YELLOW"}, {LLogColor::BLACK_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_CYAN"}, {LLogColor::BLACK_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_MAGENTA"}, {LLogColor::BLACK_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_RED"}, {LLogColor::BLACK_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_GREEN"}, {LLogColor::BLACK_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_BLUE"}, {LLogColor::BLACK_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_WHITE"}, {LLogColor::BLACK_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_YELLOW"}, {LLogColor::BLACK_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_CYAN"}, {LLogColor::BLACK_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_MAGENTA"}, {LLogColor::BLACK_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BLACK_ON_BOLD_BLACK"}, {LLogColor::BLACK_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_RED"}, {LLogColor::BOLD_RED_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_GREEN"}, {LLogColor::BOLD_RED_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BLUE"}, {LLogColor::BOLD_RED_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_WHITE"}, {LLogColor::BOLD_RED_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_YELLOW"}, {LLogColor::BOLD_RED_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_CYAN"}, {LLogColor::BOLD_RED_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_MAGENTA"}, {LLogColor::BOLD_RED_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BLACK"}, {LLogColor::BOLD_RED_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_GREEN"}, {LLogColor::BOLD_RED_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_BLUE"}, {LLogColor::BOLD_RED_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_WHITE"}, {LLogColor::BOLD_RED_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_YELLOW"}, {LLogColor::BOLD_RED_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_CYAN"}, {LLogColor::BOLD_RED_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_RED_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_RED_ON_BOLD_BLACK"}, {LLogColor::BOLD_RED_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_RED"}, {LLogColor::BOLD_GREEN_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_GREEN"}, {LLogColor::BOLD_GREEN_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BLUE"}, {LLogColor::BOLD_GREEN_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_WHITE"}, {LLogColor::BOLD_GREEN_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_YELLOW"}, {LLogColor::BOLD_GREEN_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_CYAN"}, {LLogColor::BOLD_GREEN_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_MAGENTA"}, {LLogColor::BOLD_GREEN_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BLACK"}, {LLogColor::BOLD_GREEN_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_RED"}, {LLogColor::BOLD_GREEN_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_BLUE"}, {LLogColor::BOLD_GREEN_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_WHITE"}, {LLogColor::BOLD_GREEN_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_YELLOW"}, {LLogColor::BOLD_GREEN_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_CYAN"}, {LLogColor::BOLD_GREEN_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_GREEN_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_GREEN_ON_BOLD_BLACK"}, {LLogColor::BOLD_GREEN_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_RED"}, {LLogColor::BOLD_BLUE_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_GREEN"}, {LLogColor::BOLD_BLUE_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BLUE"}, {LLogColor::BOLD_BLUE_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_WHITE"}, {LLogColor::BOLD_BLUE_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_YELLOW"}, {LLogColor::BOLD_BLUE_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_CYAN"}, {LLogColor::BOLD_BLUE_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_MAGENTA"}, {LLogColor::BOLD_BLUE_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BLACK"}, {LLogColor::BOLD_BLUE_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_RED"}, {LLogColor::BOLD_BLUE_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_GREEN"}, {LLogColor::BOLD_BLUE_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_WHITE"}, {LLogColor::BOLD_BLUE_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_YELLOW"}, {LLogColor::BOLD_BLUE_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_CYAN"}, {LLogColor::BOLD_BLUE_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_BLUE_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLUE_ON_BOLD_BLACK"}, {LLogColor::BOLD_BLUE_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_RED"}, {LLogColor::BOLD_WHITE_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_GREEN"}, {LLogColor::BOLD_WHITE_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BLUE"}, {LLogColor::BOLD_WHITE_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_WHITE"}, {LLogColor::BOLD_WHITE_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_YELLOW"}, {LLogColor::BOLD_WHITE_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_CYAN"}, {LLogColor::BOLD_WHITE_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_MAGENTA"}, {LLogColor::BOLD_WHITE_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BLACK"}, {LLogColor::BOLD_WHITE_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_RED"}, {LLogColor::BOLD_WHITE_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_GREEN"}, {LLogColor::BOLD_WHITE_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_BLUE"}, {LLogColor::BOLD_WHITE_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_YELLOW"}, {LLogColor::BOLD_WHITE_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_CYAN"}, {LLogColor::BOLD_WHITE_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_WHITE_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_WHITE_ON_BOLD_BLACK"}, {LLogColor::BOLD_WHITE_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_RED"}, {LLogColor::BOLD_YELLOW_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_GREEN"}, {LLogColor::BOLD_YELLOW_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BLUE"}, {LLogColor::BOLD_YELLOW_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_WHITE"}, {LLogColor::BOLD_YELLOW_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_YELLOW"}, {LLogColor::BOLD_YELLOW_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_CYAN"}, {LLogColor::BOLD_YELLOW_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_MAGENTA"}, {LLogColor::BOLD_YELLOW_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BLACK"}, {LLogColor::BOLD_YELLOW_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_RED"}, {LLogColor::BOLD_YELLOW_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_GREEN"}, {LLogColor::BOLD_YELLOW_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_BLUE"}, {LLogColor::BOLD_YELLOW_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_WHITE"}, {LLogColor::BOLD_YELLOW_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_CYAN"}, {LLogColor::BOLD_YELLOW_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_YELLOW_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_YELLOW_ON_BOLD_BLACK"}, {LLogColor::BOLD_YELLOW_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_RED"}, {LLogColor::BOLD_CYAN_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_GREEN"}, {LLogColor::BOLD_CYAN_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BLUE"}, {LLogColor::BOLD_CYAN_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_WHITE"}, {LLogColor::BOLD_CYAN_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_YELLOW"}, {LLogColor::BOLD_CYAN_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_CYAN"}, {LLogColor::BOLD_CYAN_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_MAGENTA"}, {LLogColor::BOLD_CYAN_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BLACK"}, {LLogColor::BOLD_CYAN_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BOLD_RED"}, {LLogColor::BOLD_CYAN_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BOLD_GREEN"}, {LLogColor::BOLD_CYAN_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BOLD_BLUE"}, {LLogColor::BOLD_CYAN_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BOLD_WHITE"}, {LLogColor::BOLD_CYAN_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_C,YAN_ON_BOLD_YELLOW"}, {LLogColor::BOLD_CYAN_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_CYAN_ON_BOLD_MAGENTA});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_CYAN_ON_BOLD_BLACK"}, {LLogColor::BOLD_CYAN_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_RED"}, {LLogColor::BOLD_MAGENTA_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_GREEN"}, {LLogColor::BOLD_MAGENTA_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BLUE"}, {LLogColor::BOLD_MAGENTA_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_WHITE"}, {LLogColor::BOLD_MAGENTA_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_YELLOW"}, {LLogColor::BOLD_MAGENTA_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_CYAN"}, {LLogColor::BOLD_MAGENTA_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_MAGENTA"}, {LLogColor::BOLD_MAGENTA_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BLACK"}, {LLogColor::BOLD_MAGENTA_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_RED"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_GREEN"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_BLUE"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_WHITE"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_YELLOW"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_CYAN"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_CYAN});
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_MAGENTA_ON_BOLD_BLACK"}, {LLogColor::BOLD_MAGENTA_ON_BOLD_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
#ifdef IS_GNU
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_RED"}, {LLogColor::BOLD_BLACK_ON_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_GREEN"}, {LLogColor::BOLD_BLACK_ON_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BLUE"}, {LLogColor::BOLD_BLACK_ON_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_WHITE"}, {LLogColor::BOLD_BLACK_ON_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_YELLOW"}, {LLogColor::BOLD_BLACK_ON_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_CYAN"}, {LLogColor::BOLD_BLACK_ON_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_MAGENTA"}, {LLogColor::BOLD_BLACK_ON_MAGENTA});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BLACK"}, {LLogColor::BOLD_BLACK_ON_BLACK});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_RED"}, {LLogColor::BOLD_BLACK_ON_BOLD_RED});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_GREEN"}, {LLogColor::BOLD_BLACK_ON_BOLD_GREEN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_BLUE"}, {LLogColor::BOLD_BLACK_ON_BOLD_BLUE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_WHITE"}, {LLogColor::BOLD_BLACK_ON_BOLD_WHITE});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_YELLOW"}, {LLogColor::BOLD_BLACK_ON_BOLD_YELLOW});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_CYAN"}, {LLogColor::BOLD_BLACK_ON_BOLD_CYAN});
    logger.LogLineColors(LLogLevel::LOG_INFO, {"BOLD_BLACK_ON_BOLD_MAGENTA"}, {LLogColor::BOLD_BLACK_ON_BOLD_MAGENTA});
    printf("--------------------------------------------------------------------\n");
#endif

    logger.LogLineColors(LLogLevel::LOG_INFO, {"RED ", "GREEN ", "BLUE ", "YELLOW"}, {LLogColor::BOLD_RED_ON_BLACK, LLogColor::BOLD_GREEN_ON_BLACK, LLogColor::BOLD_BLUE_ON_BLACK, LLogColor::BOLD_YELLOW_ON_BLACK});

    for (uint8_t i = 0; i < 6; i++)
        logger.LogLine((LLogLevel)i, "LOG LEVEL %d TEST", i);

#ifdef IS_MSVC
    system("pause");
#endif
    return 0;
}
