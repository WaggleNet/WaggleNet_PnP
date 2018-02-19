#pragma once
#include "../sensor/sensor.h"

// #ifndef ARDUINO
// #error "This file requires arduino."
// #endif

#ifdef __AVR_ARCH__
    // C Stdlib for AVR
    #include <stdint.h>
    #include <math.h>
#else
    // When testing this on a computer
    #include <cstdint>
    #include <cmath>
    
    using namespace std;
#endif

class SensorManager {
    public:
    // Constructor
    SensorManager();
    // Managing sensors
    uint8_t deleteByAddress(uint8_t address);
    Sensor& getSensorByIndex(uint8_t index);
    Sensor& getSensorByAddress(uint8_t address);
    Sensor* sensors_;
    uint8_t getSensorCount();
    private:
    uint8_t count_;
};
