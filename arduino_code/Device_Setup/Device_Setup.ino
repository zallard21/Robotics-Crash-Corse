#include <Servo.h>
#include <motor_control.h>
#include <HC_SR04.h>
#include <MPU6050.h>

#define ECHO_PIN 2
#define TRIG_PIN 10
#define ECHO_INT 0
#define SDA 4
#define SCL 5

Servo servo1;
HC_SR04 distance_sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
MPU6050 sensor(SDA, SCL);

void setup() {
  Serial.begin(9600);

  servo1.attach(9);
  servo1.write(90);

  distance_sensor.begin();
  distance_sensor.start();

  sensor.initialize();
  sensor.calibrate();
}

void loop() {
  

}
