#include "main.h"
#include "auton_commands.hpp"
#include "drive.hpp"

//#################Variables###########################
//Please add variables in your spaces for easy identification.

int wheelRadius = 2;
int tarDeg;
int testRatio = 5; //
double avg_dist;

int inches_to_degrees(int inches)
{
  inches = inches + 2; //(2 inches is a constant error)
  int result = (360 * inches)/(wheelRadius * 3.14);
  return result;
}

int degrees_to_inches(double degrees)
{
  //TODO
  //round the doubles to integers.

  int result = wheelRadius * 3.14 * ((int)degrees)/360;
}

int get_curr_dist_trvld ()
{
  double total = rightFront.get_position();
  total = total + rightMiddle.get_position();
  total = total + rightBack.get_position();
  total = total + leftFront.get_position();
  total = total + leftMiddle.get_position();
  total = total + leftBack.get_position();

  avg_dist = total/6;

  return degrees_to_inches(avg_dist);
}
//################Manipulators##########################

void move_lift_to(int deg)
{
  /*This method moves the manipulator (or in this scenerio, lift), to a certain degree.
  Make sure it stops when it runs out of space for the gears or it will start to fight
  and the gears will get damaged. */

}

//################End Effectors##########################

void move_fork(int deg, int rpm)
{
  /*Move fork to a certain degree. Make sure it stops when it runs out of
  space for the gears or it will start to fight and the gears will get damaged.
  */
  // while(endEff_motor.is_stopped() != 1)
  // {
    claw.move_absolute(deg, rpm);
  // }
  // endEff_motor.move(0);


}
void intake_stop()
{
  intake.move_velocity(0);
}

void intake_in()
{
  /*Turn the intake on to take in balls.
  */
  intake.move_velocity(-200);
}

void intake_out()
{
  /*Turn the intake on to take out balls.
  */
  intake.move_velocity(200);

}

void find_flag()
{
  /* This code will have the robot look for a flag using the pixy camera.
  */
}

void shoot_ball()
{
  /*When using this method, the flywheel starts, waits for max rpm, and shoots.
  optimum flywheel control might be found by changing the pid values
  however, it doesnt have to be changed for it to be used. Driver control's
  way of starting the flywheel is a good way of showing how the flywheel works
  in a basic way.
  Once its done shooting, the flywheel should be reduced to 0 rpm or to some minimum speed
  such as 100 as an idle mode. Low rpm = low motor usage = more battery life.
  */
  topFlywheel.move_velocity(200);
  bottomFlywheel.move_velocity(200);
  delay(3200);
  intake_in();
  delay(500);
  intake_stop();
  topFlywheel.move(0);
  bottomFlywheel.move(0);
}
void shoot_ball(int speed)
{
  topFlywheel.move_velocity(speed);
  bottomFlywheel.move_velocity(speed);
  delay(3200);
  intake_in();
  delay(500);
  intake_stop();
  topFlywheel.move(0);
  bottomFlywheel.move(0);
}

void tester_print_screen(int switcher, int speed)
{
  if (switcher == 1)
  {
    //print red when PROS has it available
    lcd::clear();
    pros::lcd::print(1, "Speed at:", speed);
  }
  else
  {
    //print black when PROS has it available
    lcd::clear();
    pros::lcd::print(2, "Speed at:", speed);
  }
}

void shoot_ball_test()
{
  bool next = true;
  int rpm = 200;
  topFlywheel.move_velocity(rpm);
  bottomFlywheel.move_velocity(rpm);
  delay(3200);
  intake_in();
  for(int c = 0; c < 13; c++)
  {

    topFlywheel.move_velocity(rpm - (c * testRatio));
    bottomFlywheel.move_velocity(rpm - (c * testRatio));
    delay(2000);
    // if (next == true)
    // {
    //   tester_print_screen(1, rpm);
    // }
    // else
    // {
    //   tester_print_screen(0, rpm);
    // }
    intake_in();
    delay(1000);
    intake_stop();
    next = !next;
  }
  topFlywheel.move(0);
  bottomFlywheel.move(0);
}

void flywheel_set(int rpm)
{
  topFlywheel.move_velocity(rpm);
  bottomFlywheel.move_velocity(rpm);
}

//################ Movement##########################

void reset_chassis_encoders()
{
  // left_motor1.set_zero_position(left_motor1.get_position());
  // left_motor2.set_zero_position(left_motor2.get_position());
  // left_motor3.set_zero_position(left_motor3.get_position());
  // right_motor1.set_zero_position(right_motor1.get_position());
  // right_motor2.set_zero_position(right_motor2.get_position());
  // right_motor3.set_zero_position(right_motor3.get_position());
  leftFront.set_zero_position(0);
  leftMiddle.set_zero_position(0);
  leftBack.set_zero_position(0);
  rightFront.set_zero_position(0);
  rightMiddle.set_zero_position(0);
  rightBack.set_zero_position(0);
}

void move_forward(int inch)
{
  // reset_chassis_encoders();
  //moves at a default rpm, Id suggest 200 (or max of gearset).

}

void move_backward(int inch)
{
  //moves at a default rpm, Id suggest -200 (or max of gearset).

}

void move_forward(int inch, int rpm)
{
  reset_chassis_encoders();
  //same as move_forward but user can include the rpm
  delay(2);
  tarDeg = inches_to_degrees(inch);
  rightFront.move_absolute(tarDeg, rpm);
  rightMiddle.move_absolute(tarDeg, rpm);
  rightBack.move_absolute(tarDeg, rpm);
  leftFront.move_absolute(tarDeg, rpm);
  leftMiddle.move_absolute(tarDeg, rpm);
  leftBack.move_absolute(tarDeg, rpm);

}

void move_backward(int inch, int rpm)
{
  //same as move_forward but user can include the rpm
  reset_chassis_encoders();
  delay(2);
  tarDeg = inches_to_degrees(inch);
  rightFront.move_absolute(-tarDeg, rpm);
  rightMiddle.move_absolute(-tarDeg, rpm);
  rightBack.move_absolute(-tarDeg, rpm);
  leftFront.move_absolute(-tarDeg, rpm);
  leftMiddle.move_absolute(-tarDeg, rpm);
  leftBack.move_absolute(-tarDeg, rpm);

}

void turn_left(int deg)
{

}

void turn_right(int deg)
{
  //turns the bot right

}
