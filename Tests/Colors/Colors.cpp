#include "../../LLogger.h"

int main(int argc, char** argv)
{
    LLogger* p_Logger = LLogger::GetInstance();
    
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_GREEN"}, {LLogColor::RED_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_BLUE"}, {LLogColor::RED_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_WHITE"}, {LLogColor::RED_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_YELLOW"}, {LLogColor::RED_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_CYAN"}, {LLogColor::RED_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_MAGENTA"}, {LLogColor::RED_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_BLACK"}, {LLogColor::RED_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_RED"}, {LLogColor::RED_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_GREEN"}, {LLogColor::RED_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_BLUE"}, {LLogColor::RED_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_WHITE"}, {LLogColor::RED_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_YELLOW"}, {LLogColor::RED_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_CYAN"}, {LLogColor::RED_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_MAGENTA"}, {LLogColor::RED_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"RED_ON_INTENSE_BLACK"}, {LLogColor::RED_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_RED"}, {LLogColor::GREEN_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_BLUE"}, {LLogColor::GREEN_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_WHITE"}, {LLogColor::GREEN_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_YELLOW"}, {LLogColor::GREEN_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_CYAN"}, {LLogColor::GREEN_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_MAGENTA"}, {LLogColor::GREEN_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_BLACK"}, {LLogColor::GREEN_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_RED"}, {LLogColor::GREEN_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_GREEN"}, {LLogColor::GREEN_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_BLUE"}, {LLogColor::GREEN_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_WHITE"}, {LLogColor::GREEN_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_YELLOW"}, {LLogColor::GREEN_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_CYAN"}, {LLogColor::GREEN_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_MAGENTA"}, {LLogColor::GREEN_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"GREEN_ON_INTENSE_BLACK"}, {LLogColor::GREEN_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_RED"}, {LLogColor::BLUE_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_GREEN"}, {LLogColor::BLUE_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_WHITE"}, {LLogColor::BLUE_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_YELLOW"}, {LLogColor::BLUE_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_CYAN"}, {LLogColor::BLUE_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_MAGENTA"}, {LLogColor::BLUE_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_BLACK"}, {LLogColor::BLUE_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_RED"}, {LLogColor::BLUE_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_GREEN"}, {LLogColor::BLUE_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_BLUE"}, {LLogColor::BLUE_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_WHITE"}, {LLogColor::BLUE_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_YELLOW"}, {LLogColor::BLUE_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_CYAN"}, {LLogColor::BLUE_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_MAGENTA"}, {LLogColor::BLUE_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLUE_ON_INTENSE_BLACK"}, {LLogColor::BLUE_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_RED"}, {LLogColor::WHITE_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_GREEN"}, {LLogColor::WHITE_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_BLUE"}, {LLogColor::WHITE_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_YELLOW"}, {LLogColor::WHITE_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_CYAN"}, {LLogColor::WHITE_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_MAGENTA"}, {LLogColor::WHITE_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_BLACK"}, {LLogColor::WHITE_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_RED"}, {LLogColor::WHITE_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_GREEN"}, {LLogColor::WHITE_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_BLUE"}, {LLogColor::WHITE_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_WHITE"}, {LLogColor::WHITE_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_YELLOW"}, {LLogColor::WHITE_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_CYAN"}, {LLogColor::WHITE_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_MAGENTA"}, {LLogColor::WHITE_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"WHITE_ON_INTENSE_BLACK"}, {LLogColor::WHITE_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_RED"}, {LLogColor::YELLOW_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_GREEN"}, {LLogColor::YELLOW_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_BLUE"}, {LLogColor::YELLOW_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_WHITE"}, {LLogColor::YELLOW_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_CYAN"}, {LLogColor::YELLOW_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_MAGENTA"}, {LLogColor::YELLOW_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_BLACK"}, {LLogColor::YELLOW_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_RED"}, {LLogColor::YELLOW_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_GREEN"}, {LLogColor::YELLOW_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_BLUE"}, {LLogColor::YELLOW_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_WHITE"}, {LLogColor::YELLOW_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_YELLOW"}, {LLogColor::YELLOW_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_CYAN"}, {LLogColor::YELLOW_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_MAGENTA"}, {LLogColor::YELLOW_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"YELLOW_ON_INTENSE_BLACK"}, {LLogColor::YELLOW_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_RED"}, {LLogColor::CYAN_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_GREEN"}, {LLogColor::CYAN_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_BLUE"}, {LLogColor::CYAN_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_WHITE"}, {LLogColor::CYAN_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_YELLOW"}, {LLogColor::CYAN_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_MAGENTA"}, {LLogColor::CYAN_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_BLACK"}, {LLogColor::CYAN_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_RED"}, {LLogColor::CYAN_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_GREEN"}, {LLogColor::CYAN_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_BLUE"}, {LLogColor::CYAN_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_WHITE"}, {LLogColor::CYAN_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_YELLOW"}, {LLogColor::CYAN_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_CYAN"}, {LLogColor::CYAN_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_MAGENTA"}, {LLogColor::CYAN_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"CYAN_ON_INTENSE_BLACK"}, {LLogColor::CYAN_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_RED"}, {LLogColor::MAGENTA_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_GREEN"}, {LLogColor::MAGENTA_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_BLUE"}, {LLogColor::MAGENTA_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_WHITE"}, {LLogColor::MAGENTA_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_YELLOW"}, {LLogColor::MAGENTA_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_CYAN"}, {LLogColor::MAGENTA_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_BLACK"}, {LLogColor::MAGENTA_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_RED"}, {LLogColor::MAGENTA_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_GREEN"}, {LLogColor::MAGENTA_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_BLUE"}, {LLogColor::MAGENTA_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_WHITE"}, {LLogColor::MAGENTA_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_YELLOW"}, {LLogColor::MAGENTA_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_CYAN"}, {LLogColor::MAGENTA_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_MAGENTA"}, {LLogColor::MAGENTA_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"MAGENTA_ON_INTENSE_BLACK"}, {LLogColor::MAGENTA_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_RED"}, {LLogColor::BLACK_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_GREEN"}, {LLogColor::BLACK_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_BLUE"}, {LLogColor::BLACK_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_WHITE"}, {LLogColor::BLACK_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_YELLOW"}, {LLogColor::BLACK_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_CYAN"}, {LLogColor::BLACK_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_MAGENTA"}, {LLogColor::BLACK_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_RED"}, {LLogColor::BLACK_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_GREEN"}, {LLogColor::BLACK_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_BLUE"}, {LLogColor::BLACK_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_WHITE"}, {LLogColor::BLACK_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_YELLOW"}, {LLogColor::BLACK_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_CYAN"}, {LLogColor::BLACK_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_MAGENTA"}, {LLogColor::BLACK_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"BLACK_ON_INTENSE_BLACK"}, {LLogColor::BLACK_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");    
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_RED"}, {LLogColor::INTENSE_RED_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_GREEN"}, {LLogColor::INTENSE_RED_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_BLUE"}, {LLogColor::INTENSE_RED_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_WHITE"}, {LLogColor::INTENSE_RED_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_YELLOW"}, {LLogColor::INTENSE_RED_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_CYAN"}, {LLogColor::INTENSE_RED_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_MAGENTA"}, {LLogColor::INTENSE_RED_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_BLACK"}, {LLogColor::INTENSE_RED_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_RED_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_RED_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_RED_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_RED_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_RED_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_RED_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_RED_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_RED_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_RED"}, {LLogColor::INTENSE_GREEN_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_GREEN"}, {LLogColor::INTENSE_GREEN_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_BLUE"}, {LLogColor::INTENSE_GREEN_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_WHITE"}, {LLogColor::INTENSE_GREEN_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_YELLOW"}, {LLogColor::INTENSE_GREEN_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_CYAN"}, {LLogColor::INTENSE_GREEN_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_MAGENTA"}, {LLogColor::INTENSE_GREEN_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_BLACK"}, {LLogColor::INTENSE_GREEN_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_RED"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_GREEN_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_GREEN_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_RED"}, {LLogColor::INTENSE_BLUE_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_GREEN"}, {LLogColor::INTENSE_BLUE_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_BLUE"}, {LLogColor::INTENSE_BLUE_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_WHITE"}, {LLogColor::INTENSE_BLUE_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_YELLOW"}, {LLogColor::INTENSE_BLUE_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_CYAN"}, {LLogColor::INTENSE_BLUE_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_MAGENTA"}, {LLogColor::INTENSE_BLUE_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_BLACK"}, {LLogColor::INTENSE_BLUE_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_RED"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLUE_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_BLUE_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_RED"}, {LLogColor::INTENSE_WHITE_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_GREEN"}, {LLogColor::INTENSE_WHITE_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_BLUE"}, {LLogColor::INTENSE_WHITE_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_WHITE"}, {LLogColor::INTENSE_WHITE_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_YELLOW"}, {LLogColor::INTENSE_WHITE_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_CYAN"}, {LLogColor::INTENSE_WHITE_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_MAGENTA"}, {LLogColor::INTENSE_WHITE_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_BLACK"}, {LLogColor::INTENSE_WHITE_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_RED"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_WHITE_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_WHITE_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_RED"}, {LLogColor::INTENSE_YELLOW_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_GREEN"}, {LLogColor::INTENSE_YELLOW_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_BLUE"}, {LLogColor::INTENSE_YELLOW_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_WHITE"}, {LLogColor::INTENSE_YELLOW_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_YELLOW"}, {LLogColor::INTENSE_YELLOW_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_CYAN"}, {LLogColor::INTENSE_YELLOW_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_MAGENTA"}, {LLogColor::INTENSE_YELLOW_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_BLACK"}, {LLogColor::INTENSE_YELLOW_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_RED"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_YELLOW_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_YELLOW_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_RED"}, {LLogColor::INTENSE_CYAN_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_GREEN"}, {LLogColor::INTENSE_CYAN_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_BLUE"}, {LLogColor::INTENSE_CYAN_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_WHITE"}, {LLogColor::INTENSE_CYAN_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_YELLOW"}, {LLogColor::INTENSE_CYAN_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_CYAN"}, {LLogColor::INTENSE_CYAN_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_MAGENTA"}, {LLogColor::INTENSE_CYAN_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_BLACK"}, {LLogColor::INTENSE_CYAN_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_RED"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_MAGENTA});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_CYAN_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_CYAN_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_RED"}, {LLogColor::INTENSE_MAGENTA_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_GREEN"}, {LLogColor::INTENSE_MAGENTA_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_BLUE"}, {LLogColor::INTENSE_MAGENTA_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_WHITE"}, {LLogColor::INTENSE_MAGENTA_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_YELLOW"}, {LLogColor::INTENSE_MAGENTA_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_CYAN"}, {LLogColor::INTENSE_MAGENTA_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_MAGENTA"}, {LLogColor::INTENSE_MAGENTA_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_BLACK"}, {LLogColor::INTENSE_MAGENTA_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_RED"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_CYAN});
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_MAGENTA_ON_INTENSE_BLACK"}, {LLogColor::INTENSE_MAGENTA_ON_INTENSE_BLACK});
#endif
    printf("--------------------------------------------------------------------\n");
#ifdef IS_GNU
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_RED"}, {LLogColor::INTENSE_BLACK_ON_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_GREEN"}, {LLogColor::INTENSE_BLACK_ON_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_BLUE"}, {LLogColor::INTENSE_BLACK_ON_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_WHITE"}, {LLogColor::INTENSE_BLACK_ON_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_YELLOW"}, {LLogColor::INTENSE_BLACK_ON_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_CYAN"}, {LLogColor::INTENSE_BLACK_ON_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_MAGENTA"}, {LLogColor::INTENSE_BLACK_ON_MAGENTA});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_BLACK"}, {LLogColor::INTENSE_BLACK_ON_BLACK});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_RED"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_RED});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_GREEN"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_GREEN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_BLUE"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_BLUE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_WHITE"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_WHITE});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_YELLOW"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_YELLOW});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_CYAN"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_CYAN});
    p_Logger->LogLineColors(LLogLevel::LOG_INFO, false, {"INTENSE_BLACK_ON_INTENSE_MAGENTA"}, {LLogColor::INTENSE_BLACK_ON_INTENSE_MAGENTA});
    printf("--------------------------------------------------------------------\n");
#endif

	for (uint8_t i = 0; i < 5; i++)
        p_Logger->LogLine((LLogLevel)i, true, "LOG LEVEL %i TEST", i);

    p_Logger->DestroyInstance();
#ifdef IS_MSVC
    system("pause");
#endif
    return 0;
}