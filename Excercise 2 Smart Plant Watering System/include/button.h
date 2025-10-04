#ifndef BUTTON_H
#define BUTTON_H

#include "stdbool.h"

void button_init(void);

/* Simulation: set a press event that will be returned once on next poll */
bool button1_pressed(void);
bool button2_pressed(void);

#endif // BUTTON_H