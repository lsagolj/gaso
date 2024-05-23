#include "mbed.h"
#include "lib/AP3216/ap3216_drv.h"

int main()
{
    int ret;
    uint16_t res;

    I2C i2c(PB_9, PB_8); // SDA: PB_9, SCL: PB_8
    i2c.frequency(100000); // Set I2C bus speed (100kHz)

    ap3216_init(&i2c);

    while (true) {
        ret = read_als(&i2c, &res);

        printf("Res: %hu\n", res);

        ThisThread:ThisThread::sleep_for(2000);
    }
}

