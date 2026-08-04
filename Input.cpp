/* Input.cpp works with user input
  - converts String user input to a float value
  - validates the outside temperature value entered by user
*/

#include "Input.h"
#include <Arduino.h>
#include "Controller.h" // "Controller.h" included to allow for checkOutside function to be called
 
// helper function used only within this module
static bool isValidNumber(const String &input); 
/*isValidNumber determines whether or not a string is a valid number or not. 
- takes a const String address so that a copy of the string isn't made and the original string isn't modified.
- a valid number must contain only digits, but there are some exceptions:
      -may contain one negative sign at the 0th index.
      -may contain one decimal, but cannot contain any more.*/

static bool isValidNumber(const String &input) { 
  int decimalsFound=0;
  bool digitsFound = false; // tracks whether the input contains at least one digit
  for (int i=0; i<input.length(); i++) { 
    char c = input[i];
    if (isDigit(c)) { 
      digitsFound = true;
    }
    if (c == '-' && i>0) {
      return false;
    }
    if (c == '.') {
      decimalsFound++;  
    }
    if (!isDigit(c)) { 
      if (c == '.' || c == '-') { // . and - are the only nondigit characters allowed
        continue;
      } else {
        return false; //return false if it is not . or -
      }
    }
  }
  if (decimalsFound > 1) { 
    return false;
  }
  return digitsFound; //if there were no digits at all, this would return false.
}

/* readOutsideTemp() reads and validates the outside temperature entered by the user.
  - it reads one line of user input, verifies if it is a valid number, converts the String input to a float,
    and makes sure that the temperature is within a realistic range.
    returns true if the temperature is valid.
*/
bool readOutsideTemp(float &outsideTemp) {
  if (Serial.available() == 0) {
    return false;
  }
  String input = Serial.readStringUntil('\n');
  input.trim();
  if (!isValidNumber(input)) {
    Serial.println("Invalid Outside Temperature. Try again.");
    delay(1000);
    Serial.println("Enter outside temperature, in Celsius: ");
    return false;
  }
  outsideTemp = input.toFloat();
  if (!checkOutside(outsideTemp)) {
    Serial.println("Outside Temperature is unrealistic. Try again.");
    return false;
  }
  return true;
}
