#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

char bt = 'S';

void setup()
{
  Serial.begin(9600);

  motor1.setSpeed(50);
  motor2.setSpeed(50);
  Stop();
}


void loop() {
  bt = Serial.read();
  
  Serial.println(bt);

  if (bt == 'F')
  {
    forward();
  }

  if (bt == 'B')
  {
    backward();
  }

  if (bt == 'L')
  {
    left();
  }

  if (bt == 'R')
  {
    right();
  }

  if (bt == 'S')
  {
    Stop();
  }

}
void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}
void left()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
void right()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
