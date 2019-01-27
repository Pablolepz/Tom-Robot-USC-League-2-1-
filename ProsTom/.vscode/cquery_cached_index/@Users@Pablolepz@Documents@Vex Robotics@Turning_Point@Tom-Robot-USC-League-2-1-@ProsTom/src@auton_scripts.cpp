#include "main.h"
#include "auton_scripts.hpp"
//#include "brain_screen.hpp"
//fork at 90 degrees is -1000
//fork at bottom is


void run_auton()
{

  //NEW_red_auton_one();
  //auton_tester();
  //red_auton_one();
  //red_auton_two();
  //red_auton_three();
  blue_auton_one();
  /*switch(choice)
    case 1:
      blue_auton_one();
      break;
    case 2:
      blue_auton_two();
      break;
    case 3:
      red_auton_one();
      break;
    case 4:
      red_auton_two();
      break;
      */
}

void auton_tester()
{
  //shoot_ball_test();
  //draw_test_screen();

}

// void red_auton_one()
// {
//   //By Pablo Lepe **********
//   // turn_left(90);
//   move_forward(30, 90);
//   move_fork(-1600, 100);
//   shoot_ball();
//   delay(1000);
//   move_forward(25, 170);
// }

// void red_auton_two()
// {
//   //by Turtle
//   move_fork(-1600, 100);
//   shoot_ball(195);
//   delay(2000);
//   shoot_ball(180);
//
//
//
// }
//
// void red_auton_three()
// {
//   //
//   shoot_ball(200);
//   delay(2000);
//   if (abs(get_flywheel_avg_rpm()) > 200)
//   {
//     intake_in();
//   }
// }


//##########################################################################################
void NEW_red_auton_one()
{
  delay(20);
  flywheel_set(200);
  delay(20);
  move_forward(5,40);
  delay(3000);
  intake_in();
  delay(1500);
  intake_stop();
  delay(20);
  turn_left(4, 90);
  delay(20);
  move_forward(50, 100);
  flywheel_set(0);
  //===========================
  // move_forward(10, 100);
  // delay(1000);
  // move_forward(45, 200);
  // delay(1000);
  // intake_in();
  // delay(1000);
  // intake_stop();
  // move_backward(65, 110);
  // delay(3000);
  // move_forward(1,30);
  // delay(1000);
  // turn_left(93, 100);
  // delay(1000);
  // flywheel_set(200);
  // move_forward(5, 40);
  // delay(1000);
  // turn_right(4, 40);
  // delay(1000);
  // intake_in();
  // delay(2000);
  // intake_stop();
  // flywheel_set(0);
  // delay(20);
  // move_forward(60, 200);
  // delay(1000);
  // while (get_curr_dist_trvld() < 30)
  // {
  // }
  // intake_in();
  // delay(2000);
  // intake_out();
  // move_backward(6, 90);
  // intake_stop();
  //  delay(3000);


}
//##########################################################################################

void blue_auton_one()
{
  flywheel_set(200);
  delay(20);
  move_forward(5,40);
  delay(3000);
  intake_in();
  delay(1500);
  intake_stop();
  delay(20);
  intake_stop();
  delay(20);
  turn_right(4, 90);
  delay(20);
  move_forward(50, 100);
}

void blue_auton_two()
{

}
