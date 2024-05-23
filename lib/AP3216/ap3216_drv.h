/*
 *  Driver for communication and setup of 
 *  AP3216 light and proximity sensor.
 *
 *  NOTE:
 *  Not all functions of the sensor have been
 *  utilized, mostly the proximity detection functions.
 */

#ifndef AP3216_DRV_H
#define AP3216_DRV_H

#include <mbed.h>

#define addr (0x1E << 1) //7-bit address shifted <- once

/*
 *  Read ambient light values and return its values thorugh a pointer
 *  
 *  Retruns:
 *      0  - On PASS
 *      0< - On FAIL
*/
int read_als(I2C *i2c, uint16_t *dest);

/*

    BLA BLA

*/
int ap3216_init(I2C *i2c);

#endif //AP3216_DRV_H