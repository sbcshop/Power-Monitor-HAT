#include <Wire.h>
#include "Adafruit_INA219.h"

Adafruit_INA219 ina1(0x40);
Adafruit_INA219 ina2(0x41);
Adafruit_INA219 ina3(0x42);

void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  ina1.begin();
  ina2.begin();
  ina3.begin();
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  Serial.println("Measuring voltage and current with Power Monitor HAT ...");
}

void loop(void) 
{
  float shuntvoltage1 = 0;
  float busvoltage1 = 0;
  float current_mA1 = 0;
  float loadvoltage1 = 0;
  float power_mW1 = 0;

  float shuntvoltage2 = 0;
  float busvoltage2 = 0;
  float current_mA2 = 0;
  float loadvoltage2 = 0;
  float power_mW2 = 0;

  float shuntvoltage3 = 0;
  float busvoltage3 = 0;
  float current_mA3 = 0;
  float loadvoltage3 = 0;
  float power_mW3 = 0;

  
  shuntvoltage1 = ina1.getShuntVoltage_mV();
  busvoltage1 = ina1.getBusVoltage_V();
  current_mA1 = ina1.getCurrent_mA();
  power_mW1 = ina1.getPower_mW();
  loadvoltage1 = busvoltage1 + (shuntvoltage1 / 1000);
  
  Serial.print("Bus Voltage:"); Serial.print(busvoltage1); Serial.print("V   ");
  Serial.print("Shunt Voltage:"); Serial.print(shuntvoltage1); Serial.print("mV   ");
  Serial.print("Load Voltage:"); Serial.print(loadvoltage1); Serial.print("V   ");
  Serial.print("Current:"); Serial.print(current_mA1); Serial.print("mA   ");
  Serial.print("Power:"); Serial.print(power_mW1); Serial.print("mW");
  Serial.println("");

  shuntvoltage2 = ina2.getShuntVoltage_mV();
  busvoltage2 = ina2.getBusVoltage_V();
  current_mA2 = ina2.getCurrent_mA();
  power_mW2 = ina2.getPower_mW();
  loadvoltage2 = busvoltage2 + (shuntvoltage2 / 1000);
  
  Serial.print("Bus Voltage:"); Serial.print(busvoltage2); Serial.print("V   ");
  Serial.print("Shunt Voltage:"); Serial.print(shuntvoltage2); Serial.print("mV   ");
  Serial.print("Load Voltage:"); Serial.print(loadvoltage2); Serial.print("V   ");
  Serial.print("Current:"); Serial.print(current_mA2); Serial.print("mA   ");
  Serial.print("Power:"); Serial.print(power_mW2); Serial.print("mW");
  Serial.println("");

  shuntvoltage3 = ina3.getShuntVoltage_mV();
  busvoltage3 = ina3.getBusVoltage_V();
  current_mA3 = ina3.getCurrent_mA();
  power_mW3 = ina3.getPower_mW();
  loadvoltage3 = busvoltage3 + (shuntvoltage3 / 1000);
  
  Serial.print("Bus Voltage:"); Serial.print(busvoltage3); Serial.print("V   ");
  Serial.print("Shunt Voltage:"); Serial.print(shuntvoltage3); Serial.print("mV   ");
  Serial.print("Load Voltage:"); Serial.print(loadvoltage3); Serial.print("V   ");
  Serial.print("Current:"); Serial.print(current_mA3); Serial.print("mA   ");
  Serial.print("Power:"); Serial.print(power_mW3); Serial.print("mW");
  Serial.println("");

  Serial.println("");
  Serial.println("");
  delay(1000);
}
