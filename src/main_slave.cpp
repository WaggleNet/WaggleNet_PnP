#include <Arduino.h>
#include <Wire.h>
#include "sensor/pnpsensor.h"

PnPSensor sensor;

int analogReading = 0;
uint8_t constant = 42;
uint32_t currTime = millis()/1000;

void getAnalogReading() {
  analogReading = analogRead(A0);
}

void getCurrTime() {
  currTime = millis() / 1000;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Sensor is setting up");
  sensor.type = 0x1234L;
  sensor.addAutoEntry(analogReading, getAnalogReading);
  sensor.addAutoEntry(currTime, getCurrTime);
  sensor.addEntry(constant);
  Serial.println("Sensor has started");
  sensor.begin(0x67);
  StartSensor(sensor);
}

void loop() {
  sensor.update();
}
