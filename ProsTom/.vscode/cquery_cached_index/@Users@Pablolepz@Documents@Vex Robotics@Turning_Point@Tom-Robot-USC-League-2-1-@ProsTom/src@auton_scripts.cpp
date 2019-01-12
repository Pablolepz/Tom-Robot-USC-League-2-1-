#include "main.h"
#include "auton_scripts.hpp"
//#include "brain_screen.hpp"
//fork at 90 degrees is -1000
//fork at bottom is


void run_auton()
{

  NEW_red_auton_one();
  //auton_tester();
  //red_auton_one();
  //red_auton_two();
  //red_auton_three();
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
  move_forward(8, 90);
  delay(500);
  move_forward(55, 130);
  delay(1000);
  intake_in();
  delay(1000);
  intake_stop();
  move_backward(60, 110);
  delay(3000);
  move_forward(7,90);
  delay(1000);
  turn_left(90, 100);
  flywheel_set(200);
  delay(3000);
  flywheel_set(0);
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

}

void blue_auton_two()
{

}
