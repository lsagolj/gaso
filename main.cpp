#include "ap3216_drv.h"
#include "button_debounce.h"
#include "regulator.h"
#include "mode.h"
#include "motor_control.h"
#include "button_debounce.h"
#include "error_handling.h"

#define RUN_TIME_S 30

Thread err_thrd;

int main()
{
    int ret;
    uint16_t lt_val, rt_val;
    uint8_t mode;

    err_thrd.start(err_led);
    button_init();
    init_motor_control(0.02);
    ap3216_init();
    mode = get_mode();

    while (true) {        
        if (active) {
            Timer run_timer;
            run_timer.start();
            
            while (run_timer.read() <= RUN_TIME_S && active) {
                
                ret = read_left_sensor(&lt_val);
                if (ret)
                    err = true;

                ret = read_right_sensor(&rt_val);
                if (ret)
                    err = true;

                ///printf("lt: %hu\n", lt_val);
                //printf("rt: %hu\n", rt_val);

                regulator_U.LIjevisenzor = (double)lt_val;
                regulator_U.Desnisenzor = (double)rt_val;
                regulator_step();
                
                if (!mode) {
                    set_motor_speed(regulator_Y.Lijevimotor, regulator_Y.Desnimotor);
                } else if (mode) {
                    set_motor_speed(regulator_Y.Desnimotor, regulator_Y.Lijevimotor);

                }
                //printf("regulator_Y.desni: %f\n", regulator_Y.Desnimotor);
                //printf("regulator_Y.lijev: %f\n", regulator_Y.Lijevimotor);
            }

            run_timer.stop();
            active = false;
        }
        set_motor_speed(0,0);
        //ThisThread::sleep_for(5);
    }

    return 0;
}

