
#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define DEFAULT_MOISTURE_LOW 30.0f
#define DEFAULT_MOISTURE_HIGH 45.0f
#define DEFAULT_WATERING_MAX_MS (30 * 1000) // 30s
#define DEFAULT_SENSOR_CYCLE_MS (5 * 60 * 1000) // 5 minutes
#define DEFAULT_MIN_INTERVAL_MS (10 * 60 * 1000) // 10 minutes

#define SOIL_VALUE_INIT 0.0f
#define TEMPURATURE_VALUE_INIT 0.0f

/*<! Value for Simulate */

#define SIMULATED_MOISTURE_SOIL  40.0f
#define SIMLUATED_ENVIROMENT_TEMPURATURE 30.0f

#define AVERAGE_DATA_MOISTURE 4
#define AVERAGE_DATA_TEMPURATURE 4



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
} system_config_t;

/**
 * @brief struct data of system
 * 
 */
typedef struct 
{
    system_mode_t system_mode;
    pump_state_t pump_state;
    led_state_t led_state; 
}system_state_t;

#endif // CONFIG_H

