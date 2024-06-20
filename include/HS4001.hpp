#ifndef HS4001_HPP
#define HS4001_HPP

#include <stdio.h>
#include "InterruptIn.h"
#include "mbed.h"
#include "I2C.h"

class HS4001
{
    // static constexpr uint8_t address = 0b01010100 << 1;

public:
    

    HS4001(mbed::I2C& i2c);
    bool getManufacturerId();

private:    

    mbed::I2C& _i2c;
    
};

#endif