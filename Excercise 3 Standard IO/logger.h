#ifndef LOGGER_H
#define LOGGER_H
/*******************************************************************************
 * Include
 ******************************************************************************/
#include "stdint.h"
#include "stdarg.h"
/*******************************************************************************
 * Variables
 ******************************************************************************/
typedef enum {
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG,
} log_level_t;

typedef enum {
    ERROR = -1,
    NORMAL = 0,
} condition_t;

/*******************************************************************************
 * API
 ******************************************************************************/
int logger_init( log_level_t log_level,const char* file);
void logger_set_level(log_level_t log_level);
void logger_cleanup(void);
void logger_log(log_level_t log_level, const char* file, int line,const char* message,...);

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define log_message(level,messages,...)   logger_log(level,__FILE__,__LINE__,messages,##__VA_ARGS__)

#endif /* LOGGER_H */
