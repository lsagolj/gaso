#include "lib/AP3216/ap3216_drv.h"

int ap3216_init(I2C *i2c)
{
    char config_regs[] = {0x00, 0x01};

    return i2c->write(addr, config_regs, 2); //Turn on ALS
}

int read_als(I2C *i2c, uint16_t *dest)
{
    int ret, atmp;

    char als_regs[] = {0x0D, 0x0C};
    char als_data[2];

    ret = ap3216_init(i2c);
    if (ret)
        goto error;

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