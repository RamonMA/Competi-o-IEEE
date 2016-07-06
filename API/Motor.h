/**
 * @author GIM
 * @brief  Esta classe serve para controlar o motor através  da PWM.
 * @date   26 de maio, 2016.
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor{
private:
  byte const motorPin1;
  byte const motorPin2;

public:

  Motor(const int& _motorPin1, const int& _motorPin2);
  /**
  * @brief Controla a velocidade do motor através do uso da PWM.
  * @param velocidade valor inteiro da velocidade entre 0 e 255.
  */
  void pwm(const int& motorPin,const int& velocidade) const;
};

#endif
