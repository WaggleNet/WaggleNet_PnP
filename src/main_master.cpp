#include <Arduino.h>
#include "sensor/sensor.h"
#include "sensor/manager.h"

SensorManager manager;

void setup() {
  Serial.begin(115200);
  manager.begin();
}

void loop() {
  manager.collect(0);
  manager.dumpToSerial(0);
  delay(5000);
}
