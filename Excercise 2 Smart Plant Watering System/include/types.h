
#ifndef TYPES_H
#define TYPES_H

#include "stdint.h"

/**
 * @brief mode system
 * 
 */
typedef enum 
{
    MODE_AUTO,
    MODE_MANUAL,
} system_mode_t;

/**
 * @brief pump's state
 * 
 */
typedef enum 
{
    PUMP_ON,
    PUMP_OFF,
} pump_state_t;

/**
 * @brief led's state
 * 
 */
typedef enum 
{
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR,
} led_state_t;

/**
 * @brief struct to store data of moisture sensor, enviroment tempurature sensor.
 * 
 */
typedef struct 
{
    float soil_moisture_percent;
    float env_tempurature_c;
} sensor_data_t;

/**
 * @brief struct data for control pump, moisture at low and moisture at high
 * 
 */
typedef struct 
{
    float moisture_threhold_low;
    float moisture_threhold_high;
    uint32_t watering_max_ms;
    uint32_t sensor_cycles_ms;
    uint32_t min_interval_between_watering_ms;
    system_mode_t system_mode;
} system_config;





#endif // TYPES_H