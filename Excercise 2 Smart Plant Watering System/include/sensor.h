/* === file: sensors.h === */
#ifndef SENSORS_H
#define SENSORS_H

#include "types.h"
#include "include/config.h"

void init_sensors(void);
void read_sensors(sensor_data_t *sensor_data);

#endif // SENSORS_H