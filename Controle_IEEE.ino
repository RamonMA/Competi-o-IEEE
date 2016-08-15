#include <Robo.h>

Robo robo(2,3,4,5,8,9);
char buffer[18];

void setup() {
  Serial.begin(9600);
  Serial.flush();
}
void loop() {
  if (Serial.available() > 0) {
    int index = 0;
    delay(100); // deixe o buffer encher
    int numChar = Serial.available();
    if (numChar > 15) {
      numChar = 15;
    }
    while (numChar--) {
      buffer[index++] = Serial.read();
    }
    splitString(buffer);
  }
}

void splitString(char* data) {
  Serial.print("Data entered: ");
  Serial.println(data);
  char* parameter;
  parameter = strtok (data, " ,");
  while (parameter != NULL) {
    setRotacionar(parameter);
    setFrente(parameter);
    setTras(parameter);
    setParar(parameter);
    sensor(parameter);
    parameter = strtok(NULL, " ,");
  }
  // Limpa o texto e os buffers seriais
  for (int x = 0; x < 16; x++) {
    buffer[x] = '\0';
  }
  Serial.flush();
}

//Rotaciona o robo com uma certa suavidade 
//Ex: r100 o360
void setRotacionar(char* data) {
  int velocidade;
  int grau;
  if ((data[0] == 'r') || (data[0] == 'R')) {
    velocidade = strtol(data + 1, NULL, 10);
    velocidade = constrain(velocidade, 0, 255);
    Serial.print("Rotacionar - velocidade: ");
    Serial.println(velocidade);
  }
  if ((data[0] == 'o') || (data[0] == 'O')) {
    grau = strtol(data + 1, NULL, 10);
    grau = constrain(grau, -360, 360);
    Serial.print("Grau: ");
    Serial.println(grau);
  }
  robo.rotacionar(grau,velocidade);
}

//Ex f100
void setFrente(char* data){
  int velocidade;
  if ((data[0] == 'f') || (data[0] == 'F')) {
    velocidade = strtol(data + 1, NULL, 10);
    velocidade = constrain(velocidade, 0, 255);
    Serial.print("Frente - velocidade: ");
    Serial.println(velocidade);
  }
  robo.frente(velocidade);
}

//Ex: p
void setParar(char* data){
  int velocidade;
  if ((data[0] == 'p') || (data[0] == 'P')) {
    velocidade = strtol(data + 1, NULL, 10);
    Serial.print("Parado");
  }
  robo.parar();
}

//Ex: T100
void setTras(char* data){
  int velocidade;
  if ((data[0] == 't') || (data[0] == 'T')) {
    velocidade = strtol(data + 1, NULL, 10);
    velocidade = constrain(velocidade, 0, 255);
    Serial.print("Tras - velocidade: ");
    Serial.println(velocidade);
  }
  robo.tras(velocidade);
}

void sensor(char* data){
  int sensorData;
  int limite = 30;
  if ((data[0] == 's') || (data[0] == 'S')) {
    sensorData = strtol(data + 1, NULL, 10);
    sensorData = constrain(sensorData, 0, limite);
    Serial.print("sensor: ");
    //Serial.println(sensorData);
    Serial.println(robo.range(limite)); 
  }
}

