#include "BatteryChecks.hpp"
#include <iostream>

using namespace std;

// Function definition for the generic parameter check
bool checkParameter(float value, const std::function<bool(float)>& isOutOfRange, const std::function<void(float)>& displayWarning) {
  if (isOutOfRange(value)) {
    return false;
  }
  displayWarning(value);
  return true;
}
