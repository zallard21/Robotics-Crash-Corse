#include <motor_control.h>

void setup() {
  moveMotor(200);
}

void loop() {
  
}

void moveMotor(int val) {
  double scaling_factor=1.1;
  raw_motor_control(scaling_factor*val,val);
}
