#include "lib/AP3216/ap3216_drv.h"
#include "pid.h"

int main()
{
    int ret;
    uint16_t lt_val, rt_val;

    I2C left(PB_9, PB_8); // SDA: PB_9, SCL: PB_8
    left.frequency(100000); // Set I2C bus speed (100kHz)

    I2C right(PB_3, PB_10); // SDA: PB_3, SCL: PB_10
    right.frequency(100000); // Set I2C bus speed (100kHz)

    ap3216_init(&left);
    ap3216_init(&right);

    while (true) {
        ret = read_als(&left, &lt);
        ret = read_als(&right, &rt);

        printf("lt: %hu\n", lt);
        printf("rt: %hu\n", rt);

        ThisThread:ThisThread::sleep_for(500);
    }
}

