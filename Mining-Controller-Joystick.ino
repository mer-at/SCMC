#include <Joystick.h>
int LED=9;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK,3,0,
 true, false, false,     // X and Y, but no Z Axis
 false, false, false,   // No Rx, Ry, or Rz
  false, false, false,          // No rudder or throttle
  false, false);  // No accelerator, brake, or steering

  float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
  
void setup() {
  Joystick.begin();
  Joystick.setZAxisRange(0, 1023);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

}

int ButtonState[6] = {0,0,0};
int ButtonStateDelayed[6] = {0,0,0};

void thread_axis_x()
{
    Joystick.setXAxis(analogRead(A0));
    analogWrite(LED, analogRead(A0)/4 );
}

void buttons()
{
  for (int index = 0; index < 3; index++)
  { ButtonState[index] = !digitalRead(index + 2); }
  
  delay (10);

    for (int index = 0; index < 3; index++)
  { 
    ButtonStateDelayed[index] = !digitalRead(index + 2);
    if ( ButtonStateDelayed[index] == ButtonState[index] )
  {
     Joystick.setButton(index, ButtonState[index]);
  }
 }
}

void loop() {
  thread_axis_x();
  buttons();
}
