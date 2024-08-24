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


extern I2C left;
extern I2C right;

/*
 *  Read ambient light values and return its values thorugh a pointer
 *  
 *  Retruns:
 *      0  - On PASS
 *      0< - On FAIL
*/
static int read_als(I2C *i2c, uint16_t *dest);

/*
 *  Inti given sensor
 *
 *  Retruns:
 *      0  - On PASS
 *      0< - On FAIL
 */
int ap3216_init();

int read_left_sensor(uint16_t* lt_val);
int read_right_sensor(uint16_t* rt_val);

#endif //AP3216_DRV_H