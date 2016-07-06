#include <Arduino.h>
#include "Motor.h"

Motor::Motor(const int& _motorPin1, const int& _motorPin2)
:motorPin1(_motorPin1), motorPin2(_motorPin2)
{
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
}

void Motor::pwm(const int& motorPin, const int& velocidade) const
{
  analogWrite(motorPin, velocidade);
}
