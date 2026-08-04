#ifndef SENSOR_H
#define SENSOR_H
#include <DHT.h>

void initializeSensor(int pin);
bool readInsideTemp(float &insideTemp);

#endif