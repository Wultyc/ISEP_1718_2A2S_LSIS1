#include <Servo.h>

//Parametrizacao
#define MOTOR_A_DIR 12
#define MOTOR_B_DIR 13
#define MOTOR_A_PWM 3
#define MOTOR_B_PWM 11
//#define MOTOR_A_BRK 9
//#define MOTOR_B_BRK 8
#define MOTOR_A_CS A0
#define MOTOR_B_CS A1

#define SONAR_TRIG 2
#define SONAR_ECHO_FRENTE A2
#define SONAR_ECHO_DIREITA A3
#define SONAR_ECHO_ESQUERDA A4
#define SONAR_DIST 5

#define VENTOINHA_INA 6

#define SERVO_MOTOR 10
#define SERVO_DELAY 25
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_ANGLE 0

#define CHAMA_PIN A5
#define CHAMA_LED 7
#define CHAMA_PARAM 200

#define BT_RX 8
#define BT_TX 9

#define BOTAO_VERDE 4
#define BOTAO_VERML 2

Servo servo;

int rActivate = 0;
int rActivate_ll = 0; //antes da modificação como estava?
int rState = -1;

//Distancia
float distanceF = 0;
float distanceD = 0;
float distanceE = 0;

//Duração
long durationF = 0;
long durationD = 0;
long durationE = 0;

int angle_chama = 0;
int angle_servo = 0;
int incrm_servo = 1;

void changeRobotActivationState(){
  if(digitalRead(BOTAO_VERDE) == HIGH){
    rActivate_ll = rActivate; //Preserva o estado atual de ativação
    rActivate = 1;            //Altera o estado de ativação
  } else {
    rActivate_ll = rActivate;
    rActivate = 0;
  }
}

void getDistances(){
  //Limpeza do Pino Trig
  digitalWrite(SONAR_TRIG, LOW);
  delayMicroseconds(2);
  
  //Ativa o Pin Trig por 10 microsegundos
  digitalWrite(SONAR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG, LOW);
  
  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  durationF = pulseIn(SONAR_ECHO_FRENTE, HIGH);
  durationD = pulseIn(SONAR_ECHO_DIREITA, HIGH);
  durationE = pulseIn(SONAR_ECHO_ESQUERDA, HIGH);
  
  //Calculo da distancia
  distanceF = durationF*0.034/2;
  distanceD = durationD*0.034/2;
  distanceE = durationE*0.034/2;
}

void setSpeeds(int f, int d, int e){
  
}

void setDirs(int f, int d, int e){
  
}

int define_state(){ //Determina o estado mais adquado
  int state;
  getDistances();

  if(rActivate == 0){
    state = -1;
  } else if(rActivate == 1 && rActivate_ll != rActivate){
    rActivate_ll = rActivate; //mesmo que carregem de novo no botão verde ele não volta a este estado
    state = 0;
  } else if(distanceD <= SONAR_DIST && distanceD <= SONAR_DIST){
    state = 1;
  } else if(distanceF <= SONAR_DIST && distanceD <= SONAR_DIST && distanceE <= SONAR_DIST){
    state = 2;
  } else if(distanceF <= SONAR_DIST && distanceE <= SONAR_DIST){
    state = 3;
  } else if(distanceF <= SONAR_DIST && distanceD <= SONAR_DIST){
    state = 4;
  } else if(analogRead(A0) >= CHAMA_PARAM){
    state = 5;
  } else{
    state = 1;
  }
  
  return state;
}

bool send_state(int state){ //Envia o estado por BT
  return true;
}

void operations(int state){ //Atua perante o estado
  //Atua mediante o estado
  switch(rState){
    case -1: //Desativado
      break;
    case 0: //Parado
      break;
    case 1: //Andar para a Frente
      break;
    case 2: //Andar para a Trás
      break;
    case 3: //Rodar para a direita
      break;
    case 4: //Rodar para a esquerda
      break;
    case 5: //Apagar a chama
      break;
  }
}

void setup() {
  //Função de interrupção
  attachInterrupt(digitalPinToInterrupt(BOTAO_VERML), changeRobotActivationState, CHANGE);

  //PinModes
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
  pinMode(MOTOR_A_CS, OUTPUT);
  pinMode(MOTOR_B_CS, OUTPUT);
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(SONAR_ECHO_FRENTE, INPUT);
  pinMode(SONAR_ECHO_DIREITA, INPUT);
  pinMode(SONAR_ECHO_ESQUERDA, INPUT);
  pinMode(VENTOINHA_INA, OUTPUT);
  pinMode(SERVO_MOTOR, OUTPUT);
  pinMode(CHAMA_PIN, INPUT);
  pinMode(CHAMA_LED, OUTPUT);
  pinMode(BOTAO_VERDE, INPUT);
  pinMode(BOTAO_VERML, INPUT);
  
  //Definição do estado inicial do robot
  int rActivate = -1;
  int rActivate_ll = -1;

  //Angulo Inicial do Servo
  angle_servo = 90;

  //Config Servo
  servo.attach(SERVO_MOTOR);
  servo.write(angle_servo);
}

void loop() {
  servo.write(angle_servo); //Roda o servo
  rState = define_state();//Determina o estado adequado
  operations(rState); //Define o movimento do robot
  send_state(rState); //Envia o estado atual para o SI

  //Evita rotações não possiveis
  if(angle_servo == SERVO_MAX_ANGLE){
    incrm_servo = -1;
  }else if (angle_servo == SERVO_MIN_ANGLE){
    incrm_servo = 1;
  }

  //Define o angulo do prox loop
  angle_servo += incrm_servo;
  
}
