#include "pump.h"
#include "stdio.h" 
#include "config.h"

void pump_init(void) 
{
    printf("[HAL] Actuators Initialized\n");
}

void pump_on(void) {
    printf("[ACTUATOR] BOM BAT\n");
}

void pump_off(void) {
    printf("[ACTUATOR] BOM TAT\n");
}

void led_state (led_state_t state) {
    switch(state) {
        case LED_NORMAL:
            printf("[LED]: GREEN\n");
            break;
        case LED_WATERING:
            printf("[LED]: YELLOW\n");
            break;
        case LED_ERROR:
            printf("[LED]: RED\n");
            break;
        default:
            printf("[LED]: OFF\n");
            break;
    }
}

