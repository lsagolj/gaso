#ifndef BUTTON_DEBOUNCE_H
#define BUTTON_DEBOUNCE_H

#include "mbed.h"

extern InterruptIn button;
extern Timer debounce;
extern volatile bool active;
extern volatile bool button_pressed;

void button_init();
void tgl_on_off();
void debounce_cbf();

#endif // BUTTON_DEBOUNCE_H
