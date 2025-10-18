#include "logger.h"
#include <stdio.h>

int main(void)
{
    /* Function to check log file is open? if not its return 1 else it do notthing, 
    * it will create a app.txt to store log message of system */
    if (0 != logger_init(LOG_DEBUG,"app.txt"))
    {
        printf("Cant open log file");
        return 1;
    } else
    {
        /* DO NOTTHING */
    }
    /* set the minimum log level to system */
    logger_set_level(LOG_DEBUG);

    
    log_message(LOG_EMERGENCY,"Canh bao");
    log_message(LOG_ALERT,"Canh bao");
    log_message(LOG_CRITICAL,"Canh bao");
    log_message(LOG_ERROR,"Canh bao");
    log_message(LOG_WARNING,"Canh bao");
    log_message(LOG_NOTICE,"Canh bao");
    log_message(LOG_INFO,"Canh bao");
    log_message(LOG_DEBUG,"Canh bao");

    logger_cleanup();
}