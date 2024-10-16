#include "TemperatureCheck.h"
#include "ParameterChecker.h"
#include <iostream>
using namespace std;

void checkTemperature(float temperature) {
  // Temperature parameters
  float tempLower = 0.0, tempUpper = 45.0;
  float tempTolerance = tempUpper * 0.05;

  // Check if temperature is out of range
  auto isTemperatureOutOfRange = [tempLower, tempUpper](float temp) {
    if (temp < tempLower || temp > tempUpper) {
      cout << "Temperature out of range!" << endl;
      return true;
    }
    return false;
  };

  // Display temperature warnings
  auto displayTemperatureWarning = [tempLower, tempUpper, tempTolerance](float temp) {
    if (temp <= tempLower + tempTolerance) {
      cout << "Warning: Approaching low temperature!" << endl;
    }
    if (temp >= tempUpper - tempTolerance) {
      cout << "Warning: Approaching high temperature!" << endl;
    }
  };

  checkParameter(temperature, isTemperatureOutOfRange, displayTemperatureWarning);
}
