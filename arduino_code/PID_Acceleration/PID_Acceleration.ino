#include <Servo.h>
#include <motor_control.h>
#include <HC_SR04.h>
#include <MPU6050.h>
#include <Timer.h>
#include <PID_v1.h>

#define ECHO_PIN 2
#define TRIG_PIN 10
#define ECHO_INT 0
#define SDA 4
#define SCL 5

Servo servo1;
HC_SR04 distance_sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
MPU6050 sensor(SDA, SCL);
Timer timer1(1000);

double input, output, setpoint=0.1, kp=1500, ki=0, kd=0;
PID controller(&input, &output, &setpoint, kp, ki, kd, DIRECT);

void setup() {
  Serial.begin(9600);

  servo1.attach(9);
  servo1.write(90);

  distance_sensor.begin();
  distance_sensor.start();

  sensor.initialize();
  sensor.calibrate();

  timer1.start();
  
  controller.SetSampleTime(25);
  controller.SetOutputLimits(-255,255);
  controller.SetMode(1);
}

void loop() {
  if(timer1.is_finished()) {
    setpoint *= -1;
    timer1.start();
  }
  
  sensor.update();
  input = sensor.get_accel('x');
  
  controller.Compute();
  moveRobot(-output);
}

void moveRobot(int num) {
  raw_motor_control(1.1*num,num);
}
