#include <stdio.h>
#include <time.h>

int main(void) {
    
    time_t curtime;
    time(&curtime);
    struct tm *local_time =  localtime(&curtime);
    char time_arr[20];

    strftime(time_arr,sizeof(time_arr),"%yyyy-%mm-%dd %H:%M:%S",local_time);
    printf(strftime(time_arr,sizeof(time_arr),"%yyyy-%mm-%dd %H:%M:%S",local_time));
}