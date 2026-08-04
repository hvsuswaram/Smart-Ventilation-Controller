/* Output.cpp controls the simulated ventilation output
- initializes the LED
- updates LED state to indicate whether ventilation is enabled
*/

#include "Output.h"
#include <Arduino.h>

// stores the Arduino pin used to control the ventilation LED
static int ledPin;

void initializeOutput(int pin) {
  if (pin<0 || pin>13) { // if the pin is not in the range of possible Arduino digital pins, it is invalid
    Serial.println("Error: Invalid pin.");
    return;
  }
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

// turn the ventilation system on or off
void setVentilation(bool enabled) {
  if (enabled) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}