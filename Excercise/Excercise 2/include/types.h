/**
 * @file types.h
 * @author duong nguyen nguyen (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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
} system_mode;

/**
 * @brief pump's state
 * 
 */
typedef enum 
{
    PUMP_ON,
    PUMP_OFF,
} pump_state;

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
} led_state;

/**
 * @brief moisture in Percent and tempurature in Celcius
 * 
 */
typedef struct 
{
    float soi_moisture_percent;
    float tempurature_c;
} sensor_data;

/**
 * @brief Data decide on operating mode for Pump, Sensor cycle
 * 
 */
typedef struct 
{
    float moisture_threhold_low;
    float moisture_threhold_high;
    uint32_t watering_max_ms;
    uint32_t sensor_cycles_ms;
    uint32_t min_interval_between_watering_ms;
    pump_state;
} system_config;


#endif // TYPES_H