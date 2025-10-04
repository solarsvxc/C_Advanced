#include <stdio.h>
#include "sensor.h"
#include "config.h"
#include "types.h"

#define SENSOR_SOIL_MOISTURE_PIN 1
#define SENSOR_TEMPURATURE_PIN   2 
#define PUMP_WATER               3 

void System_init(void){
    init_sensors();
    
}


int main(int argc, int argv[]){
    
    while (1){  } 

}