#include <Arduino.h>

const int batteryPin = A0; // Change A0 to the analog pin connected to the voltage divider output

const float minBatteryVoltage = 3.0; // Minimum battery voltage considered 0% (replace with your values)
const float maxBatteryVoltage = 4.2; // Maximum battery voltage considered 100% (replace with your values)

const float R1 = 10000.0; // Resistance of R1 in Ohms
const float R2 = 10000.0; // Resistance of R2 in Ohms

void setup() {
  Serial.begin(115200);
}

void loop() {
  float batteryPercentage = readBatteryPercentage();
  float batteryVoltage = readBatteryVoltage();

  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage);
  Serial.print("V, Battery Percentage: ");
  Serial.print(batteryPercentage);
  Serial.println("%");

  delay(1000);
}

float readBatteryVoltage() {
  float voltage = analogRead(batteryPin) * (5.0 / 1023.0);
  float batteryVoltage = voltage * (R1 + R2) / R2;
  return batteryVoltage;
}

float readBatteryPercentage() {
  float batteryVoltage = readBatteryVoltage();
  float batteryPercentage = (batteryVoltage - minBatteryVoltage) * 100 / (maxBatteryVoltage - minBatteryVoltage);
  return constrain(batteryPercentage, 0, 100);
}
