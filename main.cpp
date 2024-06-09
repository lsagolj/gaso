#include "EventQueue.h"
#include "ThisThread.h"
#include "ap3216_drv.h"
#include "regulator.h"

InterruptIn button(PC_13); 

DigitalOut usr_led(D13);
Thread err_thrd;
Timer debounce;

volatile bool err = false;
volatile bool active = false;

bool jedan = false;
bool dva = false;
bool button_pressed = false; 

void err_led()
{
    Timer timer;

    while (true) {
        if (err) {
            timer.start();

            while (timer.read_ms() < 1000) {
                usr_led = !usr_led;
                ThisThread::sleep_for(50);
            }
            timer.stop();
            timer.reset();
            err = false;
        } else
            usr_led = 1;
    }
}

void tgl_on_off()
{
   if (!button_pressed) {
        active = !active;  // Toggle LED if button is pressed and debounce time has passed
        button_pressed = true;  // Set button pressed flag
        debounce.reset(); // Reset debounce timer
        debounce.start(); // Start debounce timer
    }
}

void debounce_cbf()
{
    if (debounce.read_ms() >= 50) {
        button_pressed = false;  // Reset button pressed flag after debounce time
        debounce.stop();   // Stop debounce timer
    }
}

int main()
{
    int ret;
    uint16_t lt_val, rt_val;

    err_thrd.start(err_led);

    I2C left(PB_9, PB_8); // SDA: PB_9, SCL: PB_8
    left.frequency(100000); // Set I2C bus speed (100kHz)

    I2C right(PB_3, PB_10); // SDA: PB_3, SCL: PB_10
    right.frequency(100000); // Set I2C bus speed (100kHz)

    ap3216_init(&left);
    ap3216_init(&right);

    
    debounce.start();
    //button.fall([&debounce]() { tgl_on_off(debounce);}); //Lambda funkcija
    button.fall(&tgl_on_off);
    button.rise(&debounce_cbf);

    while (true) {
        /*ret = read_als(&left, &lt_val);
        if (ret)
            err = true;

        ret = read_als(&right, &rt_val);
        if (ret)
            err = true;

        printf("lt: %hu\n", lt_val);
        printf("rt: %hu\n", rt_val);

        ThisThread::sleep_for(500);*/

        if (active) {
            printf("gas\n");
        }
        ThisThread::sleep_for(5);
    }

    return 0;
}

