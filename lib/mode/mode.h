/*
 *  Driver for communication and setup of 
 *  AP3216 light and proximity sensor.
 *
 *  NOTE:
 *  Not all functions of the sensor have been
 *  utilized, mostly the proximity detection functions.
 */

#ifndef MODE_H
#define MODE_H
/*
    MODE 0 = chase light
    MOde 1 = chase dark
*/
int get_mode();

#endif //MODE_H