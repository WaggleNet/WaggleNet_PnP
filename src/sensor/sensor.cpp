#include "./sensor.h"

Sensor::Sensor (): Sensor(0) {}

Sensor::Sensor (uint8_t max_size):size_(0), max_size_(0) {
    if (max_size == 0) {
        data_ = NULL;
        lengths_ = NULL;
    } else {
        changeSize(max_size_);
    }
}

void Sensor::changeSize (uint8_t new_max_size) {
    // First just add new arrays
    void** new_data_ = new void*[new_max_size];
    uint8_t* new_lengths_ = new uint8_t[new_max_size];
    for (uint8_t i = 0; i < new_max_size; i++) {
        new_data_[i] = NULL;
        new_lengths_[i] = 0;
    }
    // If there was old data, migrate the data
    if (max_size_ > 0) {
        for (uint8_t i = 0; i < (max_size_ < new_max_size ? max_size_ : new_max_size); i++) {
            new_data_[i] = data_[i];
            new_lengths_[i] = lengths_[i];
        }
        delete[] data_;
        delete[] lengths_;
    }
    // Commit transition
    max_size_ = new_max_size;
    data_ = new_data_;
    lengths_ = new_lengths_;
}

/**
 * Adds data to the internal data list.
 * @param location pointer to the variable casted as void*
 * @param length size of the variable.
 * @return: Index to the data.
 */
uint8_t Sensor::addData (void* location, uint8_t length) {
    // First check if the data array has ever been initialized.
    if (size_ == max_size_) changeSize(max_size_ + 1);
    // Insert data at last location
    data_[size_] = location;
    lengths_[size_] = length;
    // Incement size
    size_ ++;
    return size_ - 1;
}

uint8_t Sensor::getLength (uint8_t index) {
    if (index > size_) return 0;
    return lengths_[index];
}

uint8_t* Sensor::getData (uint8_t index) {
    if (index > size_) return NULL;
    return (uint8_t*) data_[index];
}

uint8_t Sensor::getSize () {
    return size_;
}