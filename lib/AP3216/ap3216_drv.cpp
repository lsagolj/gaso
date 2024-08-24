#include "ap3216_drv.h"

I2C left(PB_9, PB_8); // SDA: PB_9, SCL: PB_8
I2C right(PB_3, PB_10); // SDA: PB_3, SCL: PB_10

int ap3216_init()
{
    int ret;
    char config_regs[] = {0x00, 0x01};

    left.frequency(100000); // Set I2C bus speed (100kHz)
    right.frequency(100000); // Set I2C bus speed (100kHz)

    ret = left.write(addr, config_regs, 2); //Turn on ALS
    if (ret)
        return ret;

    ret = right.write(addr, config_regs, 2); //Turn on ALS
    if (ret)
        return ret;

    return ret;
}

static int read_als(I2C *i2c, uint16_t *dest)
{
    int ret, atmp;

    char als_regs[] = {0x0D, 0x0C};
    char als_data[2];

    ret = i2c->write(addr, &als_regs[0], 1); // High address register
    if (ret)
       goto error;

    ret = i2c->read(addr, &als_data[0], 1); // Read high register
    if (ret)
        goto error;

    ret = i2c->write(addr, &als_regs[1], 1); // Low address register
    if (ret)
        goto error;

    ret = i2c->read(addr, &als_data[1], 1); // Read low register
    if (ret)
        goto error;


    *dest = (als_data[0] << 8) | als_data[1];

error:
    return ret;
}

int read_left_sensor(uint16_t* lt_val) 
{
    return read_als(&left, lt_val);
}

int read_right_sensor(uint16_t* rt_val) 
{
    return read_als(&right, rt_val);
}