#include "main.h"
#include "gyroscope.hpp"

int KP = 1;
int KI = 0;
int KD = 0;
int tolorence = 10;
int minspeed = 5;
int timeout = 3;
int totalerror;
int prop_error;
int int_error;
int der_error;
int prev_error;
int output_val;


void run_gyro()
{
  //--------Proportional---------
  prop_error = (get_gyro_target()/10) - (get_gyro_val()/10);
  //--------Integral---------
  if (prop_error < 1)
  {
    totalerror = 0;
  }
  int_error = totalerror + (prop_error * 0.002);
  //--------Derivative---------
  der_error = (prop_error - prev_error)/0.002;
  prev_error = prop_error;
  //--------Output----------------------------------------
  output_val = KP * prop_error + KI * int_error + KD * der_error;
  //----------------------------------------------------------------------------------
  if (get_gyro_val() > 359)
  {
    set_gyro_val(0);
  }
  if (get_gyro_val() < 0)
  {
    set_gyro_val(359);
  }
}

void gyro_PID(void* gyro_controller)
{
  while(true)
  {
    run_gyro();
    delay(2);
  }
}

int get_gyro_output()
{
  return output_val;
}
