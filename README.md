# LLogger
A simple and lightweight C++ console logger.
## Highlights
- Header only
- C++11 and above.
- Cross-platform (Windows/Mac/Linux)
- Thread-safe
- Fast, minimizes unnecessary string formatting calls.
## Information

Logging Types:

| **Type**           | **Description**                                              |
|:-------------------|:-------------------------------------------------------------|
| `CONSOLE`          | Only logs to the console output.                             |
| `FILE`             | Only logs to a text file, defined by calling SetLogFilePath. |
| `CONSOLE_AND_FILE` | Logs to both the console and a text file.                    |
   
Levels of verbosity:

| **Verbosity** | **Log Level** | **Description**                                    |
|:--------------|:--------------|:---------------------------------------------------|
| 0             |               | Does not log anything, equivalent to an OFF state. |
| 1             | `[FATAL]`     | Logs [FATAL] messages.                             |
| 2             | `[ERROR]`     | Logs [FATAL], [ERROR] messages.                    |
| 3             | `[WARN]`      | Logs [FATAL], [ERROR], [WARN] messages.            |
| 4             | `[INFO]`      | Logs [FATAL], [ERROR], [WARN], [INFO] messages.    |
| 5             | `[DEBUG]`     | Logs all messages.                                 |

Colors are configurable for all log levels by simply calling `SetLogLevelColor`. Information regarding the color codes can be found here:

> [Terminal Colors](https://chrisyeh96.github.io/2020/03/28/terminal-colors.html)

## Usage (Example)
**Code:**   
```
#include "../LLogger.h"

int main(int argc, char** argv)
{
    LLogger logger;

    logger.SetLogLevel(LLogLevel::LOG_INFO);
    logger.SetLogType(LLogType::CONSOLE_AND_FILE);

    logger.LogLine(LLogLevel::LOG_FATAL, "This is a test log with prefix.");
    logger.LogLine(LLogLevel::LOG_ERROR, "This is a test log with prefix.");
    logger.LogLine(LLogLevel::LOG_WARN, "This is a test log with prefix.");
    logger.LogLine(LLogLevel::LOG_INFO, "This is a test log with prefix.");
    
    printf("\n");
    logger.SetShowLogPrefix(false);

    logger.LogLine(LLogLevel::LOG_FATAL, "This is a test log without prefix.");
    logger.LogLine(LLogLevel::LOG_ERROR, "This is a test log without prefix.");
    logger.LogLine(LLogLevel::LOG_WARN, "This is a test log without prefix.");
    logger.LogLine(LLogLevel::LOG_INFO, "This is a test log without prefix.");
    
    logger.SetShowLogPrefix(true);

    logger.LogLineColors(LLogLevel::LOG_INFO, {"Red ", "Green ", "Blue"}, 
        {LLogColor::BOLD_RED_ON_BLACK, LLogColor::BOLD_GREEN_ON_BLACK, LLogColor::BOLD_BLUE_ON_BLACK});

    return 0;
}
```
**Output:**   
![UsageExample_Output](https://user-images.githubusercontent.com/50681738/218299689-90ffb443-6a00-40c3-a15d-36e19b4fb7cb.PNG)

## Future Developments
- Unicode compatibility.
