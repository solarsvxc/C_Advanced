#include <stdio.h>
#include "include/config.h"

void sensors_init(void)
{
    printf("<! SENSORS INITIALIZED");
}

/**
 * @brief Read the data pin of sensor connected to MCU, protocol must in analog if use ADC in board or digital protocol(I2C or SPI).
 * 
 * @return float 
 * The results are averaged over about four[default settings] measurements.
 */
float moisture_soil_get(void) 
{
    return SIMULATED_MOISTURE_SOIL / AVERAGE_DATA_MOISTURE;
}

/**
 * @brief Read the data pin of sensor connected to MCU, protocol must in analog if use ADC in board or digital protocol(I2C or SPI).
 * 
 * @return float 
 * The results are averaged over four[default settings] measurements.
 */
float enviroment_tempurature_get(void)
{
    return  SIMLUATED_ENVIROMENT_TEMPURATURE / AVERAGE_DATA_TEMPURATURE;
}