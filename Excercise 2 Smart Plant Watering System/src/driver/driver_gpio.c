#include "include/driver_gpio.h"
#include "stdio.h" 

#define MAX_PIN 32U
#define PIN_AVALAIBLE(n)      ((n)<MAX_PIN)

void init_gpio(gpio_port_t gpio_port)
{
    switch (gpio_port)
    {
    case IP_PORTA:
        printf("Enabled IP_PORTA");
        break;
    case IP_PORTB:
        printf("Enabled IP_PORTA");
        break;
    case IP_PORTC:
        printf("Enabled IP_PORTA");
        break;
    case IP_PORTD:
        printf("Enabled IP_PORTA");
        break;
    case IP_PORTE:
        printf("Enabled IP_PORTA");
        break;
    default:
        printf("PORT NOT FOUND!!");
        break;
    }
}

void setup_gpio(uint32_t pin,gpio_direction_t gpio_direction)
{
    if (PIN_AVALAIBLE(pin))
    {
        
    } else {
        printf("NO PIN AVALAIBLE"); 
    }
    
}
