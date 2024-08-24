#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "mbed.h"

extern DigitalOut usr_led;
extern volatile bool err;

void err_led();

#endif // ERROR_HANDLING_H
