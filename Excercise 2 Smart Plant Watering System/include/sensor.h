/* === file: sensors.h === */
#ifndef SENSORS_H
#define SENSORS_H

#include "include/config.h"

void sensors_init(void);
float moisture_soil_get(void);
float enviroment_tempurature_get(void);

#endif // SENSORS_H