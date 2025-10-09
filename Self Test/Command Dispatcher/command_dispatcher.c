#include <stdio.h>
#include <string.h>
#include <stdint.h>

void command_help(const char *args);
void led_on(const char *args);
void led_off(const char *args);

typedef struct 
{   
    const char *name; // Name command
    void (*handler) (const char *args); // Pointer point to function handler with parameter is a char pointer
    const char *description; // Description of function pointed
} command_dispatcher_t;


/**
 * @brief this is an array variable named command_table with many struct mini insight the array
 * 
 */
command_dispatcher_t command_table[] = {
    {"LED_ON", led_on,"LED ON"},
    {"LED_OFF", led_off,"LED OFF"},
    {"HELP", command_help,"Help function call"},

};

/**
 * @brief logic to call function via command user text in 
 * @param cmd [in] command to call
 */
void dispatcher(const char *cmd,const char *args)
{
    int num_cmds = sizeof(command_table) / sizeof(command_table[0]);

    for (int i = 0; i < num_cmds; i++)
    {
        if (strcmp(cmd,command_table[i].name) == 0)
        {
            command_table[i].handler(args);
            return;
        } else {
            /* DO NOTTHING */
        }
    } 
    printf("UNKNOW COMMAND: %s\n",cmd);
}

void command_help(const char *args)
{
    (void)args; // This line prevents a compiler warning about an unused parameter.
    int num_cmds = sizeof(command_table) / sizeof(command_table[0]);

    printf("===LIST COMMAND VERIFIED===\n");

    for (int i = 0; i < num_cmds; i++)
    {
        printf("+ %-10s | Description: %s\n" ,command_table[i].name,command_table[i].description);
    }
}

void led_on(const char *args)
{
    printf("LED being ON%s\n",args);
}

void led_off(const char *args)
{
    printf("LED being OFF%s\n",args);
}

int main(void)
{
        command_help("");
        dispatcher("LED_ON","");    
}