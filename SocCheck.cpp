#include "BatteryChecks.hpp"
#include <iostream>
using namespace std;

void displaySocWarning(float soc, float socLower, float socUpper, float socTolerance) {
    if (soc <= socLower + socTolerance) {
        cout << "Warning: Approaching discharge!" << endl;
    } 
    else if (soc >= socUpper - socTolerance) {
        cout << "Warning: Approaching charge-peak!" << endl;
    }
}

void checkSoc(float soc) {
    float socLower = 20.0, socUpper = 80.0;
    float socTolerance = socUpper * 0.05;

    // Check if state of charge is out of range and display warnings
    if (soc < socLower || soc > socUpper) {
        cout << "State of Charge out of range!" << endl;
    } else {
        displaySocWarning(soc, socLower, socUpper, socTolerance);
    }
}
