#include "error_handling.h"

DigitalOut usr_led(D12);
volatile bool err = false;

void err_led() {
    Timer timer;

    while (true) {
        if (err) {
            timer.start();
            while (timer.read_ms() < 1000) {
                usr_led = !usr_led;
                ThisThread::sleep_for(50ms);
            }
            timer.stop();
            timer.reset();
            err = false;
        } else {
            usr_led = 1;
        }
    }
}
