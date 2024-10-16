#include <iostream>
#include <functional> // for std::function
using namespace std;

// Generic function to check value ranges and warnings
bool checkParameter(float value, const std::function<bool(float)>& isOutOfRange, const std::function<void(float)>& displayWarning) {
  if (isOutOfRange(value)) {
    return false;
  }
  displayWarning(value);
  return true;
}

int main() {
  // Temperature parameters
  float tempLower = 0.0, tempUpper = 45.0;
  float tempTolerance = tempUpper * 0.05;

  // SoC parameters
  float socLower = 20.0, socUpper = 80.0;
  float socTolerance = socUpper * 0.05;

  // Charge rate parameters
  float chargeRateUpper = 0.8;
  float chargeRateTolerance = chargeRateUpper * 0.05;

  // Check temperature
  auto isTemperatureOutOfRange = [tempLower, tempUpper](float temp) {
    if (temp < tempLower || temp > tempUpper) {
      cout << "Temperature out of range!" << endl;
      return true;
    }
    return false;
  };

  auto displayTemperatureWarning = [tempLower, tempUpper, tempTolerance](float temp) {
    if (temp <= tempLower + tempTolerance) {
      cout << "Warning: Approaching low temperature!" << endl;
    }
    if (temp >= tempUpper - tempTolerance) {
      cout << "Warning: Approaching high temperature!" << endl;
    }
  };

  // Check SoC
  auto isSocOutOfRange = [socLower, socUpper](float soc) {
    if (soc < socLower || soc > socUpper) {
      cout << "State of Charge out of range!" << endl;
      return true;
    }
    return false;
  };

  auto displaySocWarning = [socLower, socUpper, socTolerance](float soc) {
    if (soc <= socLower + socTolerance) {
      cout << "Warning: Approaching discharge!" << endl;
    }
    if (soc >= socUpper - socTolerance) {
      cout << "Warning: Approaching charge-peak!" << endl;
    }
  };

  // Check charge rate
  auto isChargeRateOutOfRange = [chargeRateUpper](float chargeRate) {
    if (chargeRate > chargeRateUpper) {
      cout << "Charge rate out of range!" << endl;
      return true;
    }
    return false;
  };

  auto displayChargeRateWarning = [chargeRateUpper, chargeRateTolerance](float chargeRate) {
    if (chargeRate >= chargeRateUpper - chargeRateTolerance) {
      cout << "Warning: Approaching charge rate peak!" << endl;
    }
  };

  // Battery check logic
  bool batteryIsOk = true;
  batteryIsOk &= checkParameter(43.0, isTemperatureOutOfRange, displayTemperatureWarning);
  batteryIsOk &= checkParameter(78.0, isSocOutOfRange, displaySocWarning);
  batteryIsOk &= checkParameter(0.79, isChargeRateOutOfRange, displayChargeRateWarning);

  if (batteryIsOk) {
    cout << "Battery is OK" << endl;
  }

  return 0;
}
