#include "config.h" 
#include "spws_controller.h"
#include "stdbool.h" 
#include "pump.h"
#include "stdio.h"

static system_config_t system_settings;
static system_state_t system_states;
static sensor_data_t sensor_data;

static bool is_watering = false;
static uint32_t manual_watering_start   = 0;

extern uint32_t system_was_work_s;
/**
 * @brief init Smart Plant Watering System by default value. 
 * 
 */
void spws_init(void)
{
    system_settings.min_interval_between_watering_ms    = DEFAULT_MIN_INTERVAL_MS;
    system_settings.moisture_threhold_high              = DEFAULT_MOISTURE_HIGH;
    system_settings.moisture_threhold_low               = DEFAULT_MOISTURE_LOW;
    system_settings.sensor_cycles_ms                    = DEFAULT_SENSOR_CYCLE_MS;
    system_settings.watering_max_ms                     = DEFAULT_WATERING_MAX_MS;

    sensor_data.env_tempurature_c                       = TEMPURATURE_VALUE_INIT;
    sensor_data.soil_moisture_percent                   = SOIL_VALUE_INIT;
    
    system_states.pump_state                            = PUMP_OFF;
    system_states.led_state                             = LED_NORMAL;
    system_states.system_mode                           = MODE_AUTO;

    printf("[SPWS]: Initialized. Mode=AUTO\n");
}

void swps_pump_turn_on(void) 
{
    if (PUMP_ON == system_states.pump_state)
    {
        pump_on();
        
        system_states.pump_state = PUMP_ON;
        system_states.led_state = LED_WATERING;
        
        printf("[SYSTEM]: Start Watering\n");
    } else {
        /* DO NOTHING */
    }
    
}

void swps_pump_turn_off(void)
{
    if (PUMP_OFF == system_states.pump_state)
    {
        pump_off();
        
        system_states.pump_state = PUMP_OFF;
        system_states.led_state = LED_NORMAL;
        
        printf("[SYSTEM]: Pump Off\n");
    } else {
        /* DO NOTHING */
    }
}

void swps_toggle_mode(void)
{
    if (MODE_AUTO == system_states.system_mode)
    {
        system_states.system_mode = MODE_MANUAL;

        if (PUMP_ON == system_states.pump_state)
        {
            pump_off();
        } else {
            /* DO NOTTHING */
        } 
        
        printf("[MODE]: System converted MANUAL \n");
        
    } else {
        system_states.system_mode = MODE_AUTO;
        printf("[MODE]: System converted AUTO\n");
    }
}

void swps_manual_watering(void)
{
    if (MODE_MANUAL != system_states.system_mode || is_watering) 
    {
        return;
    } else {
        /* DO NOTTHING */
    }

    is_watering = true;
    pump_on();
    system_states.pump_state = PUMP_ON;
    system_states.led_state  = LED_WATERING;
    printf("[MANUAL]: Start watering manual\n");
    
}

void swps_auto_mode(void)
{
    if (PUMP_OFF == system_states.pump_state )
    {
        if (sensor_data.soil_moisture_percent < system_settings.moisture_threhold_low)
        {
            pump_on();
            
            system_states.led_state     = LED_WATERING;
            system_states.pump_state    = PUMP_ON;

            printf("[AUTO]: Pump is ON",sensor_data.env_tempurature_c,sensor_data.env_tempurature_c);
        } else {
            /* DO NOTTHING */
        }
        
    } else 
    {
        if (sensor_data.soil_moisture_percent > system_settings.moisture_threhold_high )
        {
            pump_off();
            
            system_states.led_state     = LED_NORMAL;
            system_states.pump_state    = PUMP_OFF;
            
            printf("[AUTO]: Pump is OFF ( Moisture: %u%% > %u%%)\n",sensor_data.soil_moisture_percent , system_settings.moisture_threhold_high);
        } else {
            /* Function check time was watering*/
        }
    }
    
}

void swps_mannual_mode(void) 
{
    if (is_watering && (system_was_work_s - manual_watering_start) >= system_settings.watering_max_ms)
    {
        pump_off();
        
        system_states.led_state = LED_NORMAL;
        system_states.pump_state = PUMP_OFF;

        is_watering = false;
        printf("[MANUAL]: Ket thuc tuoi thu cong\n");
    }
    

}