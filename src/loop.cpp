#include <Arduino.h>
#include <loop.h>
#include <Wire,h>

struct channel{
  uint8_t numebr;
  uint8_t size
  int *d
  *d = & data ;
}


unit16_t x0
unit16_t x1
void print_data(x0,x1,sensor_id,internal_add1,internal_add2) {
  Wire.beginTransmission(sensor_id);
  Wire.write(internal_add1);
  Wire.write(internal_add2);
  Wire.endTransmission();
  Wire.requestForm(sensor_id,2);

  if(Wire.available(),<=2) {
    x0 = Wire.read();
    x2 = Wire.read();
  }//put your main code here, to run repeatedly:
}
