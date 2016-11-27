#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
EnergyMonitor emon2;

void setup()
{ 

  analogReadResolution(ADC_BITS);
  Serial.begin(9600);
  
  emon1.current(A0, 111.1);             // Current: input pin, calibration.
  emon2.current(A1, 111.1);
}

void loop()
{
  double Irms = emon1.calcIrms(20000) - 0.06;  // Calculate Irms only
  double Irms2 = emon2.calcIrms(20000) - 0.06;

  Serial.print("Meter 1:  ");
  Serial.print(Irms*122.0);         // Apparent power
  Serial.print("W ");
  Serial.print(Irms);          // Irms
  Serial.print("A      Meter 2:  ");
  
  Serial.print(Irms2*122.0);         // Apparent power
  Serial.print("W ");
  Serial.println(Irms2);          // Irms
  
}
