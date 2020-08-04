#include <MPU6050.h>

#define SDA 4
#define SCL 5

MPU6050 sensor(SDA, SCL);

void setup() {
  Serial.begin(9600);

  sensor.initialize();
  sensor.update();
}

void loop() {

  sensor.update();
  Serial.println(10.0*sensor.get_accel('x'));
}
