#include <stdbool.h>

static int btn1_event = 0;
static int btn2_event = 0;

void button_init(void)
{
    printf("[BUTTON] Buttons initialized\n");
}

bool button1_pressed(void)
{
    btn1_event++;
    if (btn1_event == 1) 
    {
        btn1_event = 0;
        printf("[BUTTON1] Pressed (Toggle Auto/Manual)\n");
        
        return true;
    }
        return false;
}

bool button2_pressed(void)
{
    btn2_event++;
    if (btn2_event == 2) 
    { 
        btn2_event = 0;
        printf("[BUTTON2] Pressed (Manual Water)\n");

        return true;
    }
        return false;
}
