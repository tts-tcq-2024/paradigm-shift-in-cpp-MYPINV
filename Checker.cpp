#include <assert.h>
#include <iostream>
using namespace std;

bool isTemperatureOk(float temperature)
{
  return(temperature >= 0 && temperature <= 45);
}

bool isSocOk(float soc)
{
  return(soc >=20 && soc <=80);
}

bool isChargeRateOk(float chargeRate)
{
  return(chargeRate <= 0.8);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  bool tempOk = isTemperatureOk(temperature);
  bool socOk = isSocOk(soc);
  bool chargeRateOk = isChargeRateOk(chargeRate);

  if (tempOk && socOk && chargeRateOk)
  {
    return true;
  }    

  if(!tempOk)
  {
    cout << "Temperature out of range!" << endl;
  }

  if(!socOk)
  {
    cout << "State of Charge out of range!" << endl;
  }

  if(!chargeRateOk)
  {
    cout << "Charge rate out of range!" << endl;
  }

  return false;  
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
