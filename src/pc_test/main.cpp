#ifdef __AVR_ARCH__
#error "This file is meant to be run on the computer."
#endif

#include <iostream>
#include "../../lib/sensor/sensor.h"

using namespace std;

void test_simple_dut() {
    int test_int = 4;
    double test_double = 12.0;
    uint8_t test_byte = 37;

    Sensor dut;
    dut.type = 125;
    uint8_t int_index = dut.addEntry(test_int);
    uint8_t float_index = dut.addEntry(test_double);
    uint8_t byte_index = dut.addEntry(test_byte);
    cout << "Current size (expected 3): " << (unsigned)dut.getSize() << endl;
    cout << "Int length (expected " << sizeof(int) << "): " << (unsigned)dut.getLength(int_index) << endl;
    cout << "Float length (expected " << sizeof(double) << "): " << (unsigned)dut.getLength(float_index) << endl;
    cout << "Byte length (expected " << sizeof(uint8_t) << "): " << (unsigned)dut.getLength(byte_index) << endl;
    cout << "----REGISTER MAP----" << endl;
    cout << "MAR\tSIZE\tMDR" << endl;
    for (int i = 0; i < 4*4; i++) {
        cout << dec << i << '\t' << (int)dut.getRegisterSize(i) << '\t';
        auto mdr = dut.getRegister(i);
        for (int j = dut.getRegisterSize(i)-1; j>=0; j--) {
            cout << "0x" << hex << (int)mdr[j] << " ";
        }
        cout << endl;
    }
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