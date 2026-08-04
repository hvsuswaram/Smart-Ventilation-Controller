/* Sensor.cpp initializes the DHT11 temperature sensor
  - provides validated indoor temperature readings 
  - communicates with the sensor
*/
 
 #include "Sensor.h" 
#include <Arduino.h>
#include <DHT.h>
#include "Controller.h" //needed to call checkInside from Controller module

// local object for the entire module to access
static DHT sensor(0, DHT11);

void initializeSensor(int pin) {
  if (pin<0 || pin>13) { // if the pin is not in the range of possible Arduino digital pins, it is invalid
    Serial.println("Error: Invalid pin.");
    return;
  }
  sensor = DHT(pin, DHT11);
  sensor.begin();
}

bool readInsideTemp(float &insideTemp) {
  insideTemp = sensor.readTemperature();
  if (!checkInside(insideTemp)) {
    return false;
  }
  return true;
}
