/* SmartVentilation.ino is the main application for the Smart Ventilation Controller
 - coordinates user input, sensor readings, control logic, and hardware output
*/

// Include project modules, each responsible for a single part of the program:

#include "Sensor.h"
#include "Controller.h"
#include "Output.h"
#include "Input.h"
#include <Arduino.h>

// stores temperature readings
float insideTemp = 0.0;
float outsideTemp = 0.0;

// hardware pin assignments 
const int LED_PIN = 5;  
const int DHT_PIN = 12;

void setup() {
  Serial.begin(9600);
  
  // initialize the LED and Sensor
  initializeSensor(DHT_PIN);
  initializeOutput(LED_PIN);
  Serial.println("Enter outside temperature, in Celsius: ");
}

void loop() {

  // read and validate the outside temperature entered by the user
  if (!readOutsideTemp(outsideTemp)) {
    return;
  }

  // read the current inside temperature detected by the DHT11 sensor
  if (!readInsideTemp(insideTemp)) {
    return;
  }

  // compare inside and outside temperatures, display them, and update ventilation accordingly
  bool ventilationOn = controlVentilation(outsideTemp, insideTemp);

  Serial.println();
  Serial.println(" Smart Ventilation Controller");

  Serial.print("Outside Temperature: ");
  Serial.print(outsideTemp);
  Serial.println(" C");

  Serial.print("Inside Temperature: ");
  Serial.print(insideTemp);
  Serial.println(" C");

  Serial.print("Ventilation: ");

  if (ventilationOn) {
    Serial.println("ON");
  }
  else {
    Serial.println("OFF");
  }

  Serial.println();
  Serial.println("Enter outside temperature, in Celsius: ");
}
