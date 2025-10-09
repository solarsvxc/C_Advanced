#include <stdio.h>
#include <time.h>

int main(void) {
    time_t curtime;
    time(&curtime);

    printf("Thời gian hiện tại: %s", ctime(&curtime));

}