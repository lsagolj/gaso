#include "button_debounce.h"

InterruptIn button(D2);
Timer debounce;
volatile bool active = false;
volatile bool button_pressed = false;

void tgl_on_off() {
    if (!button_pressed) {
        active = !active;
        button_pressed = true;
        debounce.reset();
        debounce.start();
    }
}

void debounce_cbf() {
    if (debounce.read_ms() >= 50) {
        button_pressed = false;
        debounce.stop();
    }
}

void button_init() //button.fall([&debounce]() { tgl_on_off(debounce);}); //Lambda funkcija
{
    button.mode(PullUp);
    debounce.start();
    button.fall(&tgl_on_off);
    button.rise(&debounce_cbf);
}