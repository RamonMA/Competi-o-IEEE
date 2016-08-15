#include "Robo.h"

Robo::Robo(const int& motor1Pin1, const int& motor1Pin2, const int& motor2Pin1, const int& motor2Pin2,
           const int& trig, const int& echo)
:motor1(motor1Pin1,motor1Pin2),motor2(motor2Pin1,motor2Pin2)
{
  this->motor1Pin1 = motor1Pin1;
  this->motor1Pin2 = motor1Pin2;
  this->motor2Pin1 = motor2Pin1;
  this->motor2Pin2 = motor2Pin2;

  this->trig = trig;
  this->echo = echo;
  count = 0;
}

void Robo::frente(const int& pwm) const
{
  motor1.pwm(motor1Pin1,pwm);
  motor1.pwm(motor1Pin2,0);
  motor2.pwm(motor2Pin1,pwm);
  motor2.pwm(motor2Pin2,0);
}

void Robo::tras(const int& pwm) const
{
  motor1.pwm(motor1Pin1,0);
  motor1.pwm(motor1Pin2,pwm);
  motor2.pwm(motor2Pin1,0);
  motor2.pwm(motor2Pin2,pwm);
}

void Robo::rotacionar(const float& angulo, const int& pwm)
{
  float rads = abs(angulo*PI/180);
  rads *= pwm;
  while(count <= rads){
    if(angulo > 0){
      motor1.pwm(motor1Pin1,pwm);
      motor1.pwm(motor1Pin2,0);
      motor2.pwm(motor2Pin1,200);
      motor2.pwm(motor2Pin2,0);
    }
    else{
      motor1.pwm(motor1Pin1,200);
      motor1.pwm(motor1Pin2,0);
      motor2.pwm(motor2Pin1,pwm);
      motor2.pwm(motor2Pin2,0);
    }
    count++;
  }
  count = 0;
  delay(1000);
}

void Robo::parar() const
{
  motor1.pwm(motor1Pin1,0);
  motor1.pwm(motor1Pin2,0);
  motor2.pwm(motor2Pin1,0);
  motor2.pwm(motor2Pin2,0);
}

float Robo::range(const float& limite) const
{
  Ultrasonic ultrasonic(this->trig, this->echo);
  long microsec = ultrasonic.timing();
  float distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  if(distancia <= limite)
    return distancia;
  else
    return -1;
}
