#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "main.h"

extern Controller master;
extern Motor rightFront;
extern Motor rightMiddle;
extern Motor rightBack;
extern Motor leftFront;
extern Motor leftMiddle;
extern Motor leftBack;
extern Motor intake;
extern Motor topFlywheel;
extern Motor bottomFlywheel;
extern Motor rightLift;
extern Motor leftLift;
extern Motor claw;
extern ADIDigitalOut pneu;
extern ADIGyro gyroSens;

extern void setup_bot();
extern int get_flywheel_avg_rpm();
extern int get_flywheel_target_rpm();
extern int get_FW_KF();
extern int get_FW_KP();
extern int get_FW_KI();
extern int get_FW_KD();
extern void set_gyro_tar(int val);
extern void set_gyro_val(int val);
extern int get_gyro_val();
extern int get_gyro_target();

#endif
