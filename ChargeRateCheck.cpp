#include "BatteryChecks.hpp"
#include <iostream>
using namespace std;

void checkChargeRate(float chargeRate) {
  // Charge rate parameters
  float chargeRateUpper = 0.8;
  float chargeRateTolerance = chargeRateUpper * 0.05;

  // Check if charge rate is out of range
  auto isChargeRateOutOfRange = [chargeRateUpper](float chargeRate) {
    if (chargeRate > chargeRateUpper) {
      cout << "Charge rate out of range!" << endl;
      return true;
    }
    return false;
  };

  // Display charge rate warnings
  auto displayChargeRateWarning = [chargeRateUpper, chargeRateTolerance](float chargeRate) {
    if (chargeRate >= chargeRateUpper - chargeRateTolerance) {
      cout << "Warning: Approaching charge rate peak!" << endl;
    }
  };

  checkParameter(chargeRate, isChargeRateOutOfRange, displayChargeRateWarning);
}
