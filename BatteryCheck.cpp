#include "BatteryChecks.hpp"
#include <iostream>
using namespace std;

void checkBatteryParameters() {
  // Check battery parameters
  cout << "Checking battery parameters...\n";
  checkTemperature(43.0);
  checkSoc(78.0);
  checkChargeRate(0.79);
}
