#include "main.h"
#include "drive.hpp"

//bool twice = false;
bool flip = true;
int clawOn = 0;
int flip_const = 0;
int max_standard_rpm = 200;
int max_high_rpm = 600;
int left = 0;
int right = 0;
int shoot_speed = 0;
int inTake = 0;
int timer_set = millis();

int claw_rev_count1 = 2;
int claw_speed = max_standard_rpm;
int claw_tar = claw.get_position();
int claw_angle1 = 90;
int claw_angle2 = 90;

int FW_Speed_Difference = 15;
int FW_Speed_1 = max_standard_rpm;
int FW_Speed_2 = max_standard_rpm - FW_Speed_Difference;
int FW_Speed_3 = max_standard_rpm - (2 * FW_Speed_Difference);

int liftSpeed = 0; //lift shall be coded in stages
double lift_tar1 = topFlywheel.get_position();
double lift_tar2 = bottomFlywheel.get_position();

void left_motors_go(int rpm)
{
  leftFront = rpm;
  leftMiddle = rpm;
  leftBack = rpm;
}

void right_motors_go(int rpm)
{
  rightFront = rpm;
  rightMiddle = rpm;
  rightBack = rpm;
}

void run_intake()
{
  if (master.get_digital(DIGITAL_L1) == 1)
  {
    inTake = -max_standard_rpm;
  }
  else if (master.get_digital(DIGITAL_L2) == 1)
  {
    inTake = max_standard_rpm;
  }
  else
  {
    inTake = 0;
  }
  intake.move_velocity(inTake);
}

void run_flywheel()
{
  if (master.get_digital(DIGITAL_LEFT) == 1)
  {
    shoot_speed = FW_Speed_1;
  }
  // else if (master.get_digital(DIGITAL_RIGHT) == 1)
  // {
  //   shoot_speed = FW_Speed_2;
  // }
  // else if (master.get_digital(DIGITAL_DOWN) == 1)
  // {
  //   shoot_speed = FW_Speed_3;
  // }
  else if (master.get_digital(DIGITAL_DOWN) == 1)
  {
    shoot_speed = 0;
  }
  topFlywheel.move_velocity(shoot_speed);
  bottomFlywheel.move_velocity(shoot_speed);
}

void run_lift()
{
  if (master.get_digital(DIGITAL_R1) == 1) //&& degrees
  {
    rightLift.move_velocity(max_standard_rpm);
    leftLift.move_velocity(max_standard_rpm);
    lift_tar1 = rightLift.get_position();
    lift_tar2 = leftLift.get_position();
  }
  else if (master.get_digital(DIGITAL_R2) == 1 )
  {
    rightLift.move_velocity(-max_standard_rpm);
    leftLift.move_velocity(-max_standard_rpm);
    lift_tar1 = rightLift.get_position();
    lift_tar2 = leftLift.get_position();
  }
  else
  {
    rightLift.move_absolute(lift_tar1, liftSpeed);
    leftLift.move_absolute(lift_tar2, liftSpeed);
  }
}

void run_claw()
{
  if(master.get_digital(DIGITAL_B) && (flip = true) && ((millis() - timer_set) > 200))
  {
    flip_const = -360;
    flip = false;
    timer_set = millis();
  }
  else if(master.get_digital(DIGITAL_B) && (flip = false) && ((millis() - timer_set) > 200))
  {
    flip_const = 0;
    flip = true;
    timer_set = millis();
  }
  if (master.get_digital(DIGITAL_A) && ((millis() - timer_set) > 200))
  {
    timer_set = millis();
    if (clawOn == 1)
    {
      pneu.set_value(1);
      clawOn = 0;
    }
    else
    {
      pneu.set_value(0);
      clawOn = 1;
    }
  }
}

void move_Chassis()
{
  left_motors_go(master.get_analog(ANALOG_LEFT_Y));
  right_motors_go(master.get_analog(ANALOG_RIGHT_Y));

}

void run_drive_control()
{
  while(true)
  {
    run_intake();
    run_flywheel();
    run_lift();
    run_claw();
    move_Chassis();

    pros::delay(20);
  }
}
