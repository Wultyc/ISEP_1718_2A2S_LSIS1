#include <Servo.h>
#include <SoftwareSerial.h>

#include "param.h" //Parametros de configuração

Servo servo;  //Objeto de controlo do servo
SoftwareSerial Bluetooth(BT_RX, BT_TX); //Definição do Bluetooth

int estado = 0; //Estado do robot
int desativa_robot = 0; //mantem o robot desativado
int btnStart = 0, btnStop = 0; //Valor dos botões de Start e Stop
int chama = 0; //Valores do sensor de chama
int velA = 0, velB = 0, dirA = 0, dirB = 0, velProp = 0, dalayRobot = 0; //Valores de output
int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_enabled = 0; //Define se o servo roda ou não

int velP = 128; int delayP = 1250; int delayS = 100;

int andaFrente = 0;
int andaEsquerda = 0 ;
int andaDireita = 0;

String estados[7] = {"Desat", "Frente", "Direita", "Esq", "Chama"};

void desativa() {

  desativa_robot = 0;
  estado = 0;
  servo_enabled = 0;
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(VENTOINHA_INA, VENTOINHA_MIN);
  servo.write(90);

}

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  Bluetooth.begin(38400);
  Serial.begin(9600);

  //Função de interrupção
  attachInterrupt(digitalPinToInterrupt(2), desativa, RISING);

  //Output inicial
  velA = 0; velB = 0;
  dirA = 0; dirB = 0;
  velProp = 0; dalayRobot = 0;
  servo_enabled = 0;

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

  estado = 0;

  //Config Servo
  servo.attach(SERVO_PIN);
  angle_servo = 90;
  servo.write(angle_servo);

  Serial.println("Fim Setup");
}

void loop() {
  //Lê os inputs
  btnStart = digitalRead(BOTAO_START);

  if (desativa_robot == 0) {
    estado = 0;
    servo_enabled = 0;
    if (btnStart == HIGH) {
      estado = 0;
      desativa_robot = 1;
    }
  } else {

    servo_enabled = 1;

    switch (estado) {
      case 1:
        frente(velP, 0);

        do {
          andaFrente = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
          andaEsquerda = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
          andaDireita = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);
          delay(delayS);
        } while (andaFrente > SONAR_DIST_MIN && andaDireita < SONAR_ROOM && andaEsquerda < SONAR_ROOM);

        roboPara(delayS);
        andaFrente = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
        andaEsquerda = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
        andaDireita = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);

        if (andaFrente < SONAR_DIST_MIN || andaDireita > SONAR_ROOM || andaEsquerda > SONAR_ROOM) {

          roboPara(delayS);
          andaDireita = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);
          andaEsquerda = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);

          if (andaDireita < andaEsquerda) {
            estado = 3;
          } else if (andaDireita > andaEsquerda) {
            estado = 2;
          } else {
            estado = 1;
          }
        }
        roboPara(0);
        break;
      case 2:
        roboPara(delayS);
        direita(velP, delayP);
        roboPara(delayS);
        while (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) > SONAR_ROOM) { //Confirmar se é mesmo 60
          frente(velP, delayS);
        }
        roboPara(delayS);
        estado = 1;
        break;
      case 3:
        roboPara(delayS);
        esquerda(velP, delayP);
        roboPara(delayS);
        while (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) > SONAR_ROOM) { //Confirmar se é mesmo 60
          frente(velP, delayS);
        }
        roboPara(delayS);
        estado = 1;
        break;
      default:
        estado = 1;
    }
  }

  //Roda o Servo
  if (servo_enabled == 1) {

    for (angle_servo = SERVO_MIN_ANGLE; angle_servo <= SERVO_MAX_ANGLE; angle_servo ++) {
      servo.write(angle_servo); //Roda o servo
      delay(20);

      if (analogRead(CHAMA_PIN) >= CHAMA_PARAM) {
        apagarChama(angle_servo);
      }

    }
    for (angle_servo = SERVO_MAX_ANGLE; angle_servo >= SERVO_MIN_ANGLE; angle_servo --) {
      servo.write(angle_servo); //Roda o servo
      delay(20);

      if (analogRead(CHAMA_PIN) >= CHAMA_PARAM) {
        apagarChama(angle_servo);
      }

    }

  }

  //Envia a informação
  //Serial.println(estado);
  //Bluetooth.println(estado);
  Serial.println("Estato\tFrente\tEsq\tDir\tServo\tAngulo");
  Serial.println(estados[estado] + "\t" + (String)getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) + "\t" + (String)getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA) + "\t" + (String)getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA) + "\t" + (String) servo_enabled +  "\t" + (String) angle_servo);

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

void frente(int motorSpeed, int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  delay(duracao);
}

void tras(int motorSpeed, int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  delay(duracao);
}

void esquerda(int motorSpeed, int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  delay(duracao);
}

void direita(int motorSpeed, int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorSpeed);

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

void roda180(int motorSpeed) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed);
}

void apagarChama(int angle) {

}
