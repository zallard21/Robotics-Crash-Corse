// This will demonstrate the HC_SR04 & Servo
// The car will check the distance of objects in front of it.
// If an object is within DESIRED_DISTANCE, then the car will stop.

#include <Servo.h>
#include <HC_SR04.h>
#include <motor_control.h>

#define SERVO_PIN 9
#define TRIG_PIN 10
#define ECHO_PIN 2
#define ECHO_INT 0
#define CENTER 90
#define DESIRED_DISTANCE 30

Servo actuator;
HC_SR04 dist_sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
// Current distance to closest object
int distance; 

void setup() {
  Serial.begin(9600);

  //Attach servo to servo pin, and rotate to point sensor forward
  actuator.attach(SERVO_PIN);
  actuator.write(90);

  //Initialize distance sensor and start pinging for distances
  dist_sensor.begin();
  dist_sensor.start();

}

int error, kP = 20, motorPower;
void loop() {
  // Gets distance
  if(dist_sensor.isFinished()) {
    distance = dist_sensor.getRange();
    dist_sensor.start();
  }

  

  error = distance-DESIRED_DISTANCE;
  motorPower = error*kP;
  if(motorPower>255) {
    motorPower = 255;
  }
  if(motorPower<-255) {
    motorPower = -255;
  }
  moveRobot(motorPower);
  Serial.println(motorPower);
}

void moveRobot(int num) {
  raw_motor_control(1.1*num,num);
}
