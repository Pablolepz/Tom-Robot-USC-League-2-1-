
#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "main.h"

extern void left_motors_go(int rpm);
extern void right_motors_go(int rpm);
extern void run_intake();
extern void run_flywheel();
extern void run_lift();
extern void run_claw();
extern void move_Chassis();
extern void run_drive_control();

#endif
