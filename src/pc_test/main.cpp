#ifdef __AVR_ARCH__
#error "This file is meant to be run on the computer."
#endif

#include <iostream>
#include "../sensor/sensor.h"

using namespace std;

void test_simple_dut() {
    int test_int = 4;
    double test_double = 12.0;

    Sensor dut;
    uint8_t int_index = dut.addEntry(test_int);
    uint8_t float_index = dut.addEntry(test_double);
    cout << "Current size (expected 2): " << (unsigned)dut.getSize() << endl;
    cout << "Int length (expected " << sizeof(int) << "): " << (unsigned)dut.getLength(int_index) << endl;
    cout << "Float length (expected " << sizeof(double) << "): " << (unsigned)dut.getLength(float_index) << endl;
}

int main() {
    cout << "=====SENSOR PROTOCOL TEST=====" << endl;
    // TEST: A simple dut works
    cout << "--------------------------------" << endl;
    cout << "Test: Simply adding data works" << endl;
    cout << "--------------------------------" << endl;
    test_simple_dut();
    return 0;
}