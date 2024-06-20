#include "mbed.h"
#include "HS4001.hpp"
#define HS4001Address 0b01010100 << 1

HS4001::HS4001(mbed::I2C &i2c) : _i2c(i2c)
//_alert(PC_12, PinMode::PullNone),

// interrupt_triggered(true),//true
// high_limit_reached(false)
{
}

// bool HS4001::readRegister(int regAddress, uint16_t &regValue)
// {
//     int registerAddress = static_cast<int>(regAddress);
//     char readCommand=0xA7;
//     char data[2];
//     int rc = _i2c.write(HS4001Address, &readCommand, 1, false); 
//     rc=_i2c.write(registerAddress);
//     if (rc != 0)
//     {
//         printf("Failed i2c write\r\n");
//         return false;
//     }
//     rc = _i2c.read(HS4001Address, data, 1);
//     if (rc != 0)
//     {
//         printf("Failed i2c read\r\n");
//         return false;
//     }

//     uint16_t value = data[1];
//     value = value | (data[0] << 8);
//     regValue = value;

//     return true;
// }

// bool HS4001::writeRegister(HS4001::Register reg, uint16_t regValue)
// {
//     char writeCommand=0xA6;
//     char data[2];
//     data[0] = (uint8_t)reg;
//     // data[1] = (char)(regValue >> 8);
//     data[1] = (char)regValue;

//     int rc = _i2c.write(address, &writeCommand, 1);
//     rc=_i2c.write(data[0]);
//     rc=_i2c.write(data[1]);
//     if (rc != 0)
//     {
//         printf("Failed i2c write");
//         return false;
//     }
//     return true;
// }

// Public Methods

bool HS4001::getManufacturerId()
{
    // int registerAddress = ;
    char readCommand=0xD7;
    char data[4];
    // int rc = _i2c.write(HS4001Address, &readCommand, 1, false); 
    int rc = _i2c.write(HS4001Address, &readCommand, 1, false); 
    // rc=_i2c.write(registerAddress);
    if (rc != 0)
    {
        printf("Failed i2c write\r\n");
        // return false;
    }
    rc = _i2c.read(HS4001Address, data, 4);
    if (rc != 0)
    {
        printf("Failed i2c read\r\n");
        return false;
    }

    uint32_t value = (int)(data);
    // value = value | (data[2] << 8);
    // regValue = value;
    printf("Sensor id is %d\n",value);
    return true;
}