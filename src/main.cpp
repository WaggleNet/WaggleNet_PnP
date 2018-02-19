#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();// put your setup code here, to run once:
}

int main() {
  setup();
}
