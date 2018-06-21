#include <Servo.h>
#include <SoftwareSerial.h>

#include "param.h" //Parametros de configuração

Servo servo;  //Objeto de controlo do servo
SoftwareSerial Bluetooth(BT_RX, BT_TX); //Definição do Bluetooth

int desativa_robot = 0; //mantem o robot desativado
int ultimo_estado = -1; //ultimo estado enviado

int btnStart = 0, btnStop = 0; //Valor dos botões de Start e Stop

int chama = 0; //Valores do sensor de chama
int chama_param = 0;

int velA = 0, velB = 0, dirA = 0, dirB = 0, velProp = 0, dalayRobot = 0; //Valores de output

int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_return = 0; //Define o sentido de rotação (1: sentido positivo | -1: sentido negativo)
int servoFlag = 0;  //Determina o numero de passagem nos 90º

int velP = 255; int delayP = 750; int delayS = 100;

int distF = 0, distE = 0, distD = 0, distE2 = 0, distD2 = 0;
bool validaF = false, validaE = false, validaD = false;

long time_after_rot = 0;

void desativa() {
  desativa_robot = 0;
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(VENTOINHA_INA, VENTOINHA_MIN);
  servo.write(90);
}

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  Bluetooth.begin(9600);
  Serial.begin(9600);

  //Função de interrupção
  attachInterrupt(digitalPinToInterrupt(2), desativa, RISING);

  //Output inicial
  velA = 0; velB = 0;
  dirA = 0; dirB = 0;
  velProp = 0; dalayRobot = 0;

  //PinModes e valor padrão
  pinMode(MOTOR_A_CS, OUTPUT);
  pinMode(MOTOR_B_CS, OUTPUT);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);

  pinMode(SONAR_TRIG_FRENTE, OUTPUT);
  pinMode(SONAR_TRIG_DIREITA, OUTPUT);
  pinMode(SONAR_TRIG_ESQUERDA, OUTPUT);
  pinMode(SONAR_ECHO_FRENTE, INPUT);
  pinMode(SONAR_ECHO_DIREITA, INPUT);
  pinMode(SONAR_ECHO_ESQUERDA, INPUT);

  pinMode(VENTOINHA_INA, OUTPUT);
  analogWrite(VENTOINHA_INA, VENTOINHA_MIN);

  pinMode(SERVO_PIN, OUTPUT);

  pinMode(CHAMA_PIN, INPUT);
  pinMode(CHAMA_LED, OUTPUT);

  pinMode(BOTAO_START, INPUT);
  pinMode(BOTAO_STOP, INPUT);

  ultimo_estado = -1;

  //Config Servo
  servo.attach(SERVO_PIN);
  angle_servo = 90;
  servo.write(angle_servo);

  chama_param = 800; //analogRead(CHAMA_PIN) * 1.20;
}

void loop() {
  //Lê os inputs
  btnStart = digitalRead(BOTAO_START);

  if (desativa_robot == 0) {
    if (btnStart == HIGH) {
      desativa_robot = 1;
    }
    Serial.println(1);
    Bluetooth.println(1);

  } else {
    //Calcula distancias
    distF = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
    distE = distE2 = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
    distD = distD2 = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);

    //Aplica movimento
    frente(velP, 0); //Anda em frente
    do {
      //Valida as medidas
      validaF = distF >= SONAR_DIST_MIN;
      validaD = distD >= distD2 * 0.90 || distD <= distD2 * 1.10;
      validaE = distE >= distE2 * 0.90 || distE <= distE2 * 1.10;

      //guarda as medidas atuais
      distE2 = distE;
      distD2 = distD;

    } while (validaF == true && validaD == true && validaE == true);

    roboPara(delayS); //para o robot

    if (distF <= SONAR_DIST_MIN && distD <= SONAR_ROT_180 && distE <= SONAR_ROT_180) {

      roda180(delayP * 3); //roda o robot 180º
      roboPara(delayS); // para o robot

    } else if (distD >= SONAR_DIST_ROOM || distD > distE) && (rotD < RotMax || distE < SONAR_DIST_MIN) { //Roda para a direita

      //Atualiza as variaveis de rotação
      rotD ++;
      rotE = 0;

      //Roda para a direita
      direita(velP, delayP * 2);

      time_after_rot = millis() + delayP; // Calcula o tempo máximo para andar em frente
      frente(velP, delayS); //Liga os motores

      while (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) > SONAR_DIST_MIN || millis() >= time_after_rot); //faz um compasso de espera
        roboPara(delayS); // para o robot

    } else if (distE >= SONAR_DIST_ROOM || distE > distD) && (rotE < RotMax || distD < SONAR_DIST_MIN) { //Roda para a esquerda

      //Atualiza as variaveis de rotação
      rotE ++;
      rotD = 0;

      //Roda para a esquerda
      esquerda(velP, delayP * 2);

      time_after_rot = millis() + delayP; // Calcula o tempo máximo para andar em frente
      frente(velP, delayS); //Liga os motores

      while (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) > SONAR_DIST_MIN || millis() >= time_after_rot); //faz um compasso de espera
        roboPara(delayS); // para o robot

    }

    //Roda o servo
    servo_return = 1;
    angle_servo = SERVO_MIN_ANGLE;
    servoFlag = 0;

    do {
      servo.write(angle_servo); //Roda o servo
      chama = analogRead(CHAMA_PIN);

      if (chama >= chama_param) {
        apagarChama(angle_servo);
      }

      delay(SERVO_DELAY);

      servo_return = (angle_servo == SERVO_MAX_ANGLE) ? -1 : servo_return; //Inverte o sentido de rotação quando chegar-mos ao angulo máximo

      angle_servo += SERVO_INCREMENTO * servo_return; //Muda o angulo do servo para a próxima rotação

      servoFlag += (angle_servo == 90) ? 1 : 0; //Incrementa a flag apenas se o angulo for 90º

    } while (servoFlag < 2);
  }
}

int getDistance(int trig, int echo) {
  //Limpeza do Pino Trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  //Ativa o Pin Trig por 10 microsegundos
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  int dist = pulseIn(echo, HIGH) * 0.034 / 2;
  return dist;
}

void enviarEstado(int estado) {
  //Apenas envia se o estado for diferente
  if (ultimo_estado != estado) {
    Serial.println(estado);
    Bluetooth.println(estado);
    ultimo_estado = estado;
  }
}

void frente(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  enviarEstado(1); //Enviar o estado

  delay(duracao);
}

void tras(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  enviarEstado(2); //Enviar o estado

  delay(duracao);
}

void direita(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorSpeed / 2);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  enviarEstado(3); //Enviar o estado

  delay(duracao);
}

void esquerda(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed / 2);

  enviarEstado(4); //Enviar o estado

  delay(duracao);
}

void roboPara(int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, 0);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, 0);

  delay(duracao);
}

void roda180(int motorSpeed, int duracao) {
  if (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) < SONAR_DIST_MIN) {
    tras(velP, delayP / 2); //Não há condições para rodar, recua um pouco
  }

  if (getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA) > SONAR_DIST_MIN) {
    direita(motorSpeed, duracao); //Temos condições para rodar à direita
  } else {
    esquerda(motorSpeed, duracao);
  }
}

void apagarChama(int angle) {
  int dirA, dirB;
  
  enviarEstado(5); //Enviar o estado

  //Avisa que detetou o a chama
  for (int i = 0; i < 3; i++) {
    digitalWrite(CHAMA_LED, HIGH);
    delay(500);
    digitalWrite(CHAMA_LED, LOW);
    delay(500);
  }

  servo.write(90); //Roda o servo

  //Define para onde se roda
  if (angle > 95) {
    while (analogRead(CHAMA_PIN) <= chama_param) { //Roda ate detetar a chama
      esquerda(velP, delayS);
    }
  } else if (angle < 85) {
    while (analogRead(CHAMA_PIN) <= chama_param) { //Roda ate detetar a chama
      direita(velP / 2, delayS / 2);
    }
  }

  if (angle > 95) {
    esquerda(velP / 2, delayS / 2);
  } else {
    direita(velP / 2, delayS / 2);
  }

  roboPara(0);
  frente(velP, delayS);
  while (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) > SONAR_DIST_MIN * 1.20); // Vai ate à chama
  roboPara(0);

  while (analogRead(CHAMA_PIN) >= chama_param) { //Enquanto há chama mantem o propeller a trabalhar
    analogWrite(VENTOINHA_INA, VENTOINHA_MAX);
    delay(CHAMA_DELAY);
  }

  analogWrite(VENTOINHA_INA, VENTOINHA_MIN); //desliga o propeller
}
