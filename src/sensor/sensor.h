#pragma once
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

#ifndef NULL
// REALLY you wanna do this to me?!
#define NULL 0x0
#endif

class Sensor {
    public:
        // Constructor
        Sensor(uint8_t max_size);
        Sensor();
        // Manipulating data
        uint8_t addData(void* location, uint8_t length);
        uint8_t getLength(uint8_t index);
        uint8_t* getData(uint8_t index);
        uint8_t getSize();
        #define addEntry(DATA) addData((void*)&DATA, sizeof(DATA))
    private:
        uint8_t size_;
        uint8_t max_size_;
        void** data_;
        uint8_t* lengths_;
        void changeSize(uint8_t new_max_size);
};
