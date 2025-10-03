#include <stdint.h>

typedef enum 
{
    GPIO_INPUT,
    GPIO_OUTPUT,
} gpio_direction_t;

typedef enum{
    IP_PORTA,
    IP_PORTB,
    IP_PORTC,
    IP_PORTD,
    IP_PORTE,
}gpio_port_t;

void init_port(gpio_port_t gpio_port);
void setup_gpio(uint32_t pin,gpio_direction_t gpio_direction);