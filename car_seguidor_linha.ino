//Definição dos pinos dos sensores
#define pinSensorD 2
#define pinSensorE 3

//Definição dos pinis dos motores
//Motor 1
#define pinMotorD1 7
#define pinMotorD2 6
//Motor 2
#define pinMotorE1 5
#define pinMotorE2 4

//Definição da variável de velocidade
#define velocidade 70

void setup() {
  //Os pinos dos sensonres apontados como ENTRADA
  pinMode(pinSensorD, INPUT);
  pinMode(pinSensorE, INPUT);

  //Os pinos de controle do motor apontados como SAÍDA
  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);
}

void loop() {
  // Leitura dos sensores infravermelhos
  int leitorE = digitalRead(pinSensorE);
  int leitorD = digitalRead(pinSensorD);

  //Caso os dois sensores de linha detectem a linha (ambos os sensores na linha)
  if (leitorE && leitorD) {
    //motor 1
    digitalWrite(pinMotorD1, velocidade);
    digitalWrite(pinMotorD2, LOW);
    //motor 2
    digitalWrite(pinMotorE1, velocidade);
    digitalWrite(pinMotorE2, LOW);
  }
  //Caso Caso o sensor da esquerda detecte a linha (ajustar para a esquerda)
  else if (leitorE && leitorD) {
    //motor 1
    digitalWrite(pinMotorD1, LOW);
    digitalWrite(pinMotorD2, velocidade);
    //motor 2
    digitalWrite(pinMotorE1, velocidade);
    digitalWrite(pinMotorE2, LOW);
  }
  // Caso o sensor da direita detecte a linha (ajustar para a direita)
  else if (leitorE && leitorD) {
    //motor 1
    digitalWrite(pinMotorD1, velocidade);
    digitalWrite(pinMotorD2, LOW);
    //motor 2
    digitalWrite(pinMotorE1, LOW);
    digitalWrite(pinMotorE2, velocidade);
  }
  // Caso nenhum sensor detecte a linha (parar ou tomar uma ação específica)
  else {
    //motor 1
    digitalWrite(pinMotorD1, LOW);
    digitalWrite(pinMotorD2, LOW);
    //motor 2
    digitalWrite(pinMotorE1, LOW);
    digitalWrite(pinMotorE2, LOW);
  }
}