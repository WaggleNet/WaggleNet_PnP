#include <Arduino.h>
#include "sensor.h"
#include "pnpmanager.h"

SensorManager manager;

void setup() {
  Serial.begin(9600);
  manager.begin();
}

void loop() {
  manager.collect(0);
  manager.dumpToSerial(0);
  delay(5000);
}
