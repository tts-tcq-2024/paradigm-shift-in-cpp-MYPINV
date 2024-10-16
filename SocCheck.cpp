#include "BatteryChecks.hpp"
#include <iostream>
using namespace std;

void checkSoc(float soc) {
  // SoC parameters
  float socLower = 20.0, socUpper = 80.0;
  float socTolerance = socUpper * 0.05;

  // Check if state of charge is out of range
  auto isSocOutOfRange = [socLower, socUpper](float soc) {
    if (soc < socLower || soc > socUpper) {
      cout << "State of Charge out of range!" << endl;
      return true;
    }
    return false;
  };

  // Display state of charge warnings
  auto displaySocWarning = [socLower, socUpper, socTolerance](float soc) {
    if (soc <= socLower + socTolerance) {
      cout << "Warning: Approaching discharge!" << endl;
    }
    if (soc >= socUpper - socTolerance) {
      cout << "Warning: Approaching charge-peak!" << endl;
    }
  };

  checkParameter(soc, isSocOutOfRange, displaySocWarning);
}
