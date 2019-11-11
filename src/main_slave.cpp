#include <Arduino.h>
#include <Wire.h>
#include "pnpsensor.h"

PnPSensor sensor;

int analogReading = 0;
float constant = 42;
uint32_t currTime = millis()/1000;

void getAnalogReading() {
  analogReading = analogRead(A0);
}

void getCurrTime() {
  currTime = millis() / 1000;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Sensor is setting up");
  sensor.type = 0x1234L;
  sensor.addAutoIntEntry(analogReading, getAnalogReading);
  sensor.addAutoUintEntry(currTime, getCurrTime);
  sensor.addFloatEntry(constant);
  Serial.println("Sensor has started");
  sensor.begin(0x28);
  StartSensor(sensor);
}

void loop() {
  sensor.update();
}
