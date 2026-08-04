/* Controller.cpp provides the decision-making logic for the Smart Ventilation Controller
  - provides temperature validation and ventilation control
*/

#include "Controller.h"
#include <Arduino.h>
#include "Output.h"

bool checkInside (float insideTemp) {
  if (isnan(insideTemp)) { //if sensor fails to detect real temperature
    Serial.println("ERROR: Failed to read temperature sensor."); 
    setVentilation(false); //if sensor isn't working, turn LED off
    delay(1000); //retries once per second to avoid error messages blowing up the serial monitor
    return false; //stop this iteration of loop. arduino will call it again and try to detect a real temperature.
  }
  return true;
}

bool checkOutside(float outsideTemp) {
  if (isnan(outsideTemp) || outsideTemp > 60 || outsideTemp < -40) { //if outsideTemp is not a real number or is outside realistic temperature range
      return false;
    }
    return true;
}

bool controlVentilation(float outsideTemp, float insideTemp) {
  if (outsideTemp < insideTemp) {
     setVentilation(true);
     return true;
    }
    else {
      setVentilation(false);
      return false;
    }
}