#include "mbed.h"
#include "mode.h"

DigitalIn usr_mode(D11);

int get_mode()
{
    usr_mode.mode(PullUp);

    return usr_mode.read();
}