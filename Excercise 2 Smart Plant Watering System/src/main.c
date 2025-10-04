#include <stdio.h>
#include "config.h"
#include "pump.h"
#include "sensor.h"
#include "spws_controller.h"
#include "button.h"

#define SENSOR_SOIL_MOISTURE_PIN 1
#define SENSOR_TEMPURATURE_PIN   2 
#define PUMP_WATER               3 

uint32_t system_was_work_s = 0;

system_config_t     system_config;
system_state_t      system_state;
sensor_data_t       sensors_data;

void delay_ms(uint32_t ms) {
        for (int i = 0; i < ms; i++){}   
}
void system_init(void)
{
    button_init();
    sensors_init();
    pump_init();
    spws_init();
    
    printf("[SYSTEM]: System initialized. Mode: AUTO, Pump: OFF\n");
}

int main(int argc, int argv[])
{
    uint32_t sensors_read_last = 0;
    system_init();
    
    while (1)
    {   
        system_was_work_s += 1; 
        /* Check current state button is pressed or not */
        if (button1_pressed())
        {
            swps_toggle_mode();
        } else
        {
            swps_manual_watering();
        }

        /* Logic check sensor data of Moisture sensor and Tempurature sensor */
        if (system_was_work_s - sensors_read_last >= system_config.sensor_cycles_ms)
        {
            sensors_data.env_tempurature_c  = enviroment_tempurature_get();
            sensors_data.soil_moisture_percent  = moisture_soil_get();
            printf("[SENSOR] Soil: %u%%, Temp: %.1fC\n",  sensors_data.soil_moisture_percent, sensors_data.env_tempurature_c);
            sensors_read_last = system_was_work_s;
        }
        
        /*  */
        if (MODE_AUTO == system_state.system_mode)
        {
            swps_auto_mode();
        } else {
            swps_mannual_mode();
        }
        
        led_state(system_state.led_state);
        delay_ms(5000);
    } 

}