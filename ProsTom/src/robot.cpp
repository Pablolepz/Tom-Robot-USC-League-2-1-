#include "main.h"
#include "robot.hpp"

#define FW_KF 0
#define FW_KP 1.0f
#define FW_KI 0.0f
#define FW_KD 0.0f

Controller master(pros::E_CONTROLLER_MASTER);
Motor rightFront(10, true);
Motor rightMiddle(9, false);
Motor rightBack(8, true);
Motor leftFront(7, false);
Motor leftMiddle(6, true);
Motor leftBack(5, false);
Motor intake(11, false);
Motor topFlywheel(13, true);
Motor bottomFlywheel(12, false);
Motor rightLift(2, true);
Motor leftLift(14, false);
Motor claw(16, false);
ADIDigitalOut pneu('E', false);
ADIGyro gyroSens('G');
motor_pid_s_t pid1 = Motor::convert_pid(FW_KF, FW_KP, FW_KI, FW_KD);

void setup_bot()
{
  rightFront.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  rightMiddle.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  rightBack.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  leftFront.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  leftMiddle.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  leftBack.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  claw.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  rightLift.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  leftLift.set_encoder_units(E_MOTOR_ENCODER_DEGREES);
  claw.tare_position();
  rightLift.tare_position();
  leftLift.tare_position();
  // Right.set_pos_pid(pid1);
  // Right.set_pos_pid(pid1);
  // Right.set_pos_pid(pid1);
  // Left.set_pos_pid(pid1);
  // Left.set_pos_pid(pid1);
  // Left.set_pos_pid(pid1);
  topFlywheel.set_vel_pid(pid1);
  bottomFlywheel.set_vel_pid(pid1);

}

int get_flywheel_avg_rpm()
{
  return ((topFlywheel.get_actual_velocity() + bottomFlywheel.get_actual_velocity())/2);
}

int get_flywheel_target_rpm()
{
  return topFlywheel.get_target_velocity();
}
int get_FW_KF()
{
  return FW_KF;
}
int get_FW_KP()
{
  return FW_KP;
}
int get_FW_KI()
{
  return FW_KI;
}
int get_FW_KD()
{
  return FW_KD;
}

extern int get_gyro_val()
{
  return gyroSens.get_value();
}
