#ifndef BATTERYCHECKS_HPP
#define BATTERYCHECKS_HPP

#include <functional>

// Function declarations for parameter checking
bool checkParameter(float value, const std::function<bool(float)>& isOutOfRange, const std::function<void(float)>& displayWarning);

// Temperature checks
void checkTemperature(float temperature);

// State of charge checks
void checkSoc(float soc);

// Charge rate checks
void checkChargeRate(float chargeRate);

// Battery check
void checkBatteryParameters();

#endif // BATTERYCHECKS_HPP
