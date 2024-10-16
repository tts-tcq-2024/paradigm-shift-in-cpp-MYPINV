#ifndef PARAMETERCHECKER_H
#define PARAMETERCHECKER_H

#include <functional>
#include <string>

// Function declaration for generic parameter check
bool checkParameter(float value, const std::function<bool(float)>& isOutOfRange, const std::function<void(float)>& displayWarning);

#endif // PARAMETERCHECKER_H
