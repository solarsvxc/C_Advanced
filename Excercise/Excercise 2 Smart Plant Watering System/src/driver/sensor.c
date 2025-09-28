#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/sensor.h"

/*<! Take the average value of 4 four sensor measurement */
#define MOISTURE_AVG_WINDOW 4

static float moisture_buffer[MOISTURE_AVG_WINDOW];
static int moisture_index   = 0;
static int moisture_count   = 0;

void sensor_init(void)
{
    /*<! Random number from random seed   */
    srand((unsigned)time(NULL));


}