#include "led_driver.h"

static uint32_t *g_ptr_led_buffer = NULL;
static unsigned int g_num_pixels;

int led_init(uint32_t num_pixels)
{
    if (0 != logger_init(LOG_DEBUG,"log.txt"))
    {
        printf("Cant open log file.");
        return ERROR;
    } else
    {
        /* DO NOTTHING */
    }
    logger_set_level(LOG_DEBUG);

    if (g_ptr_led_buffer != NULL)
    {
        led_shutdown();
    } else
    {
        /* DO NOTTHING */
    }
    
    g_ptr_led_buffer = (uint32_t *)calloc(num_pixels,sizeof(uint32_t));

    if (g_ptr_led_buffer == NULL)
    {
        log_message(LOG_ERROR,"LED located memory fail.!!");
        return ERROR;
    } else
    {
        /* DO NOTTHING */
    }
        
    g_num_pixels = num_pixels;

    log_message(LOG_DEBUG,"LED init success.");
    
    return SUCCESS;
}

void led_shutdown(void)
{
    free(g_ptr_led_buffer);
    g_ptr_led_buffer = NULL;
    log_message(LOG_INFO,"LED shutdown.");

}


void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b)
{
    if ( 0 > index && index > g_num_pixels - 1 )
    {
        log_message(LOG_ERROR,"Numbers of index is out of range, please set index of pixels in range: 0 < index < number-of-pixel.!");
        return ERROR;
    } else
    {
        /* DO NOTTHING */
    }
    
    g_ptr_led_buffer[index] = ((uint32_t)g<<16) | ((uint32_t)r<<8) | b;
    log_message(LOG_INFO,"Set pixel color success.!!");
}

void led_fill(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t clr_cal = ((uint32_t)g<<16) | ((uint32_t)r<<8) | b;
    
    for (int i = 0; i < g_num_pixels; i++)
    {
        g_ptr_led_buffer[i] = clr_cal;
    }
    log_message(LOG_INFO,"LED fill success.");
}

void led_clear(void)
{
    led_fill(0,0,0);
    log_message(LOG_INFO,"Fill all pixels to Black success.");
}

void led_buff_check(void)
{
    for (size_t i = 0; i < g_num_pixels; i++)
    {
        printf("%d",g_ptr_led_buffer[i]);
    }
}