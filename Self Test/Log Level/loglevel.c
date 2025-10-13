#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} log_level_t;

static log_level_t current_log = LOG_DEBUG;

void log_message(log_level_t level, const char *format, ...)
{
    /**
     * Checks if the specified log level is lower than the current log level.
     * If so, the function returns immediately and no further action is taken.
     * Otherwise, execution continues (currently no operation is performed).
     *
     * @param level The log level to check.
     * @param current_log The current log level threshold.
     */
    if (level < current_log) 
    {
        return;
    } else { 
    /* DO NOTTHING */
    }
    
    /*
     * Formats and prints a log message with a timestamp and log level.
     *
     * - `level_string`: Array of log level strings ("DEBUG", "INFO", "WARNING", "ERROR").
     * - `now`: Current time obtained using `time(NULL)`.
     * - `time_str`: Buffer to store formatted timestamp as "YYYY-MM-DD HH:MM:SS".
     * - Uses `strftime` to format the current time.
     * - Prints the timestamp and log level using `printf`.
     *
     * Example output:
     * [2024-06-01 12:34:56] Log: [INFO]
     */
    const char *level_string[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    time_t now  = time(NULL);
    char time_str[20];
    strftime(time_str,sizeof(time_str),"%Y-%m-%d %H:%M:%S",localtime(&now));

    printf("[%s] Log: [%-7s] -> ", time_str, level_string[level]);

    /**
     * Initializes a variable argument list, prints a formatted string to stdout using the provided format and arguments,
     * then cleans up the argument list and prints a newline character.
     *
     * @param format The format string for output.
     * @param ...    Additional arguments to be formatted and printed.
     */
    va_list args;
    _crt_va_start(args,format);
    vprintf(format,args);
    _crt_va_end(args);
    printf("\n");
}

int main(void)
{
    log_message(LOG_DEBUG, "This is a debug message.");
    log_message(LOG_INFO, "Application started.");
    log_message(LOG_WARNING, "Low disk space.");
    log_message(LOG_ERROR, "Failed to open file.");

    return 0;
}