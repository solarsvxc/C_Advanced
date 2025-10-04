#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/sensor.h"

void init_sensors(uint32_t pin)
{
    /*Init sensors 
    * Analog pin soil sensor
    * Analog pin tempurature sensor
    * 
    * */
}

static float get_moisture_soil(void) 
{

    return SIMULATED_MOISTURE_SOIL / AVERAGE_DATA_MOISTURE;
}

static float get_enviroment_tempurature(void)
{
    return  SIMLUATED_ENVIROMENT_TEMPURATURE / AVERAGE_DATA_TEMPURATURE;
}

void read_sensors(sensor_data_t *sensor_data){
    sensor_data->env_tempurature_c = get_enviroment_tempurature();
    sensor_data->soil_moisture_percent = get_moisture_soil();
}