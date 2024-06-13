#include "motor_control.h"

PwmOut pwm_L(D10);
PwmOut pwm_D(D8);

void set_motor_speed(double left_speed, double right_speed) {
    pwm_L.write(left_speed);
    pwm_D.write(right_speed);
}

void init_motor_control(float period) {
    pwm_L.period(period);
    pwm_D.period(period);
}