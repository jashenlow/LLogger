# LLogger
A simple and lightweight C++ console logger.
## Highlights
- Header only
- C++11-compliant.
- Cross-platform (Windows/Mac/Linux)
- Thread-safe
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
| 1             | `[FATAL]`     | Only logs the [FATAL] level messages.              |
| 2             | `[ERROR]`     | Logs [FATAL] and [ERROR] messages.                 |
| 3             | `[WARN]`      | Logs [FATAL], [ERROR], and [WARN] messages.        |
| 4             | `[INFO]`      | Logs all messages.                                 |

Colors are configurable for all log levels by simply calling `SetLogLevelColor`. Information regarding the color codes can be found here:

> [Terminal Colors](https://chrisyeh96.github.io/2020/03/28/terminal-colors.html)

## Future Developments
- Unicode compatibility.
