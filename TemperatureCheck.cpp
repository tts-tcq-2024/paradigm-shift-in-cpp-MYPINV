#include "BatteryChecks.hpp"
#include <iostream>
using namespace std;

void displayTemperatureWarning(float temperature, float tempLower, float tempUpper, float tempTolerance) {
    if (temperature <= tempLower + tempTolerance) {
        cout << "Warning: Approaching low temperature!" << endl;
    } 
    else if (temperature >= tempUpper - tempTolerance) {
        cout << "Warning: Approaching high temperature!" << endl;
    }
}

void checkTemperature(float temperature) {
    float tempLower = 0.0, tempUpper = 45.0;
    float tempTolerance = tempUpper * 0.05;

    // Check if temperature is out of range and display warnings
    if (temperature < tempLower || temperature > tempUpper) {
        cout << "Temperature out of range!" << endl;
    } else {
        displayTemperatureWarning(temperature, tempLower, tempUpper, tempTolerance);
    }
}
