#ifndef GYROSCOPE_HPP
#define GYROSCOPE_HPP

#include "main.h"

extern void run_gyro();
extern void gyro_PID(void* gyro_controller);
extern int get_gyro_output();

#endif
