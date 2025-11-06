#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BLACK 0
typedef enum {
    ERROR = -1,
    SUCCESS = 0,
}status_t;

/* R G B values is an interger from 0 to 255 */
/* 
Initializes a buffer for the LED strip with the given number of pixels.
Returns 0 on success, -1 on failure (e.g., memory allocation failed).
 * Color init is [Black]
 */
int led_init(uint32_t num_pixels);

/* Free memory from developer located memory */
void led_shutdown();

/*
Sets the color of a specific pixel at the given 'index'.
Uses 3 separate 8-bit values for Red, Green, and Blue.
[31:24]----[23:16]-[15:8]--[7:0]
[Reversed]-[Green]-[Red]---[Blue]
*/
void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);

/*
Fills the entire strip with a single color.
*/
void led_fill(uint8_t r, uint8_t g, uint8_t b);

/*
Turns off all pixels (by setting their color to black).
*/
void led_clear();

/* Gets a constant (read-only) pointer to the data buffer, ready to be "sent" out.
   This function is used for testing purposes in this exercise. */
const uint32_t* led_get_buffer();

/* Gets the number of pixels on the LED strip. */
size_t led_get_pixel_count();

#ifdef __cplusplus
}
#endif

#endif /* LED_DRIVER_H */