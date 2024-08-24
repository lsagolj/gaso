#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "mbed.h"

extern PwmOut pwm_L;
extern PwmOut pwm_D;

void set_motor_speed(double left_speed, double right_speed);

void init_motor_control(float period);

#endif // MOTOR_CONTROL_H