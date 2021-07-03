#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1); // DC motor on M1
AF_DCMotor motor2(2); // DC motor on M2

void setup() {
  Serial.begin(9600);
  Serial.println("Motor party!");

  // turn on motor #1
  motor1.setSpeed(100);
  motor1.run(RELEASE);

  // turn on motor #2
  motor2.setSpeed(200);
  motor2.run(RELEASE);
}

void loop() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(3000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(3000);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(3000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(3000);
}
