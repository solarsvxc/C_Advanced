/*******************************************************************************
 * Include
 ******************************************************************************/
#include "logger.h"
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
static log_level_t g_log_level = LOG_INFO;

static  FILE* g_file  = NULL;

static const char* g_level_names[] = { 
    "EMERGENCY",
    "ALERT",
    "CRITICAL",
    "ERROR",
    "WARNING",
    "NOTICE",
    "INFO",
    "DEBUG"
};

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief 
 * 
 * @param log_level 
 * @param file 
 * @return int 
 */
int logger_init(log_level_t log_level,const char* file)
{
    g_log_level = log_level;

    if (NULL != file)
    {
        g_file = fopen(file,"w");

        if (NULL == g_file)
        {
            return ERROR;
        } else {
            return NORMAL;            
        }
    } else {
        return NORMAL;
    }
}

/**
 * @brief 
 * 
 * @param log_level 
 */
void logger_set_level(log_level_t log_level)
{
    g_log_level = log_level;
}

/**
 * @brief close file log is writing
 * 
 */
void logger_cleanup(void)
{
    if (NULL != g_file)
    {
        fclose(g_file);
    } else {
        /* DO NOTTHING*/
    }
}

/**
 * @brief level filtering, 
 * 
 * @param [in] log_level    log level
 * @param [in] file         file name
 * @param [in] line         line of file 
 * @param [in] message      message you want to write to file and print to console in log_message use in main.c
 * @param ... 
 */
void logger_log(log_level_t log_level, const char* file, int line,const char* message,...)
{
    if (log_level > g_log_level) { return; }
    
    char message_buff[1024];

    va_list args;
    va_start(args,message);
    vsnprintf(message_buff,sizeof(message_buff),message,args);
    va_end(args);
    
    /* [YYYY-MM-DD HH:MM:SS] [LEVEL] [FILENAME:LINE] */
    time_t curtime;
    time(&curtime);
    struct tm *local_time =  localtime(&curtime);
    
    /* format time to YYYY-MM-DD HH-MM-SS time: localtime, store it to a char array 20 byte */
    char time_buff[20];
    strftime(time_buff,sizeof(time_buff),"%Y-%m-%d %H:%M:%S",local_time);

    char log_buff[2048];
    snprintf(log_buff,sizeof(log_buff),"[%s] [%-9s] [%s:%d] - %s", time_buff, g_level_names[log_level], file, line, message_buff);

    /* CONSOLE Print */
    if (LOG_ERROR >= log_level )
    {   
        fprintf(stderr,"%s\n", log_buff);
    } else
    {
        fprintf(stdout,"%s\n", log_buff);
    }

    if (NULL != g_file)
    {
        fprintf(g_file,"%s\n",log_buff);
        fflush(g_file);
    } else
    {
        /* DO NOTTHING */
    }
}



