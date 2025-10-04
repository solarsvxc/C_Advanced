#include <stdio.h>
#include "include/config.h"

void sensors_init(void)
{
    printf("<! SENSORS INITIALIZED");
}

float moisture_soil_get(void) 
{
    return SIMULATED_MOISTURE_SOIL / AVERAGE_DATA_MOISTURE;
}

float enviroment_tempurature_get(void)
{
    return  SIMLUATED_ENVIROMENT_TEMPURATURE / AVERAGE_DATA_TEMPURATURE;
}