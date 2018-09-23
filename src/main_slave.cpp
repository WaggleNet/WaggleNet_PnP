#include <Arduino.h>
#include <Wire.h>
#include "sensor/pnpsensor.h"

PnPSensor sensor;

void setup() {
  Serial.begin(9600);
  sensor.begin(0x67);
  StartSensor(sensor);
}

void loop() {
  sensor.update();
}
