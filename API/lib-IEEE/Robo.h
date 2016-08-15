/**
 * @author GIM
 * @brief  Controlar um robo com dois motores.
 * @date   26 de maio, 2016
 */

#ifndef ROBO_H
#define ROBO_H

#include <Arduino.h>
#include <Ultrasonic.h>
#include "Motor.h"

class Robo{
private:
  //**Motor esquerdo*/
  Motor motor1;
  /**Motor direito*/
  Motor motor2;

  /**Entrada 1 do motor 1*/
  byte motor1Pin1;
  /**Entrada 2 do motor 1*/
  byte motor1Pin2;
  /**Entrada 1 do motor 2*/
  byte motor2Pin1;
  /**Entrada 2 do motor 2*/
  byte motor2Pin2;
  /**Contador para rotacionar*/

  /**Entrada trig do ultrassom*/
  byte trig;
  /**Entrada echo do ultrassom*/
  byte echo;

  int count;

public:
  /**
  * @brief Cria um robo de dois motores
  * @param motorPin1 Motor esquerdo do Robô
  * @param motorPin2 Motor direito do Robô
  */
  Robo(const int& motor1Pin1, const int& motor1Pin2, const int& motor2Pin1, const int& motor2Pin2,
       const int& trig, const int& echo);
  /**
  * @brief O robo anda para frente.
  * @param pwm Seta a velocidade de ambos os motores.
  * @see parar()
  * @see tras()
  */
  void frente(const int& pwm) const;
  /**
  * @brief O robo anda para trás.
  * @param pwm Seta a velocidade de ambos os motores.
  * @see parar()
  * @see frente()
  */
  void tras(const int& pwm) const;
  /**
  * @brief Rotaciona a direção do robo para esquerda ou direita.
  * @param angulo Se o ângulo for positovo vira para direita,
  *               se for negativo vira para direita.
  * @param pwm Velocidade de um dos motores com o qual o robo está rotacionando.
  */
  void rotacionar(const float& angulo, const int& pwm);
  /**
  * @brief Para o robo.
  * @see frente()
  * @see tras()
  */
  void parar() const;
  /**
  * @brief Mostra a distancia apartir de um certo limite.
  * @param limite Distância mínima.
  */
  float range(const float& limite) const;

};

#endif
