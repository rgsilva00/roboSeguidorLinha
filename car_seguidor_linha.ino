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
#define velocidade_reta 70   //Velocidade em linha reta
#define velocidade_curva 35  //Velocidade em curvas
#define velocidade_min 15     //Velocidade mínima para curvas fechadas

void setup() {
  //Os pinos dos sensonres apontados como ENTRADA
  pinMode(pinSensorD, INPUT);
  pinMode(pinSensorE, INPUT);

  //Os pinos de controle do motor apontados como SAÍDA
  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);

  // Inicializa a comunicação serial para debug
  Serial.begin(9600);
}

void loop() {
  // Leitura dos sensores infravermelhos
  int leitorE = digitalRead(pinSensorE);
  int leitorD = digitalRead(pinSensorD);

  //Lógica de controle do robô
  if (leitorE && leitorD) {
    //Ambos os sensores detectam a linha branca (seguir em frente)
    //motor 1
    analogWrite(pinMotorD1, velocidade_reta);
    analogWrite(pinMotorD2, 0);
    //motor 2
    analogWrite(pinMotorE1, velocidade_reta);
    analogWrite(pinMotorE2, 0);
  }
  else if (leitorE && leitorD) {
    //Sensor da esquerda detecta a linha preta (virar à esquerda)
    //motor 1
    analogWrite(pinMotorD1, velocidade_curva);
    analogWrite(pinMotorD2, 0);
    //motor 2
    analogWrite(pinMotorE1, velocidade_min);
    analogWrite(pinMotorE2, 0);
  }
  else if (leitorE && leitorD) {
    //Sensor da direita detecta a linha preta (virar à direita)
    //motor 1
    analogWrite(pinMotorD1, velocidade_min);
    analogWrite(pinMotorD2, 0);
    //motor 2
    analogWrite(pinMotorE1, velocidade_curva);
    analogWrite(pinMotorE2, 0);
  }
  else {
    //Ambos os sensores detectam a linha preta (parar)
    //motor 1
    analogWrite(pinMotorD1, 0);
    analogWrite(pinMotorD2, 0);
    //motor 2
    analogWrite(pinMotorE1, 0);
    analogWrite(pinMotorE2, 0);
  }
}