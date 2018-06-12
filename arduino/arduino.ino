#include <Servo.h>
#include <SoftwareSerial.h>

//Parametrizacao

//Motores (A: Esquerda | B: Direita)
#define MOTOR_A_DIR 12
#define MOTOR_B_DIR 13
#define MOTOR_A_PWM 3
#define MOTOR_B_PWM 11
//#define MOTOR_A_BRK 9
//#define MOTOR_B_BRK 8
#define MOTOR_A_CS A0
#define MOTOR_B_CS A1
#define MOTOR_MOVE_STOP 0  //Constantes de apoio
#define MOTOR_MOVE_FORWARD 1
#define MOTOR_MOVE_BACKWARD 2
#define MOTOR_MOVE_RIGHT 3
#define MOTOR_MOVE_LEFT 4
#define MOTOR_VEL 128

//Sonares
#define SONAR_TRIG 5
#define SONAR_ECHO_FRENTE A2
#define SONAR_ECHO_DIREITA A3
#define SONAR_ECHO_ESQUERDA A4
#define SONAR_DIST 5 //distancia do robot em cm

//Propeller
#define VENTOINHA_INA 6

//Servomotor
#define SERVO_PIN 10
#define SERVO_DELAY 25
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_ANGLE 0

//Sensor de Chama
#define CHAMA_PIN A5
#define CHAMA_LED 7
#define CHAMA_PARAM 200

//Bluetooth
#define BT_RX 8
#define BT_TX 9

//Botões de Ativação
#define BOTAO_START 4
#define BOTAO_INTRP 2

Servo servo;  //Objeto de controlo do servo
SoftwareSerial BTserial(BT_RX, BT_TX); //Definição do Bluetooth

int rActivate = 0;    //Estado de ativação
int rActivate_ll = 0; //Indica o estado de ativação antes da ultima alteração
int rState = -1;      //Estado

//Distancia
float distanceF = 0;
float distanceD = 0;
float distanceE = 0;

//Duração
long durationF = 0;
long durationD = 0;
long durationE = 0;

int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_enabled = 0;

void changeRobotActivationState(){
  Serial.print("Interrupt ");
  Serial.print(digitalRead(BOTAO_START));
  Serial.print("\n");
  if(digitalRead(BOTAO_START) == HIGH){
    rActivate_ll = rActivate; //Preserva o estado atual de ativação
    rActivate = 1;            //Altera o estado de ativação
  } else {
    rActivate_ll = rActivate;
    rActivate = 0;
  }
}

//Determina a distancia dos sonares aos objetos
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

//Atribui as velocidades
void setSpeeds(int dir, int vel){
  int a, b;
  //Desliga os motores
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  
  switch(dir){
    case MOTOR_MOVE_FORWARD:
      a = HIGH;
      b = HIGH;
      break;
    case MOTOR_MOVE_BACKWARD:
      a = LOW;
      b = LOW;
      break;
    case MOTOR_MOVE_RIGHT:
      a = LOW;
      b = HIGH;
      break;
    case MOTOR_MOVE_LEFT:
      a = HIGH;
      b = LOW;
      break;
  }
  //Direciona os motores
  digitalWrite(MOTOR_A_DIR, a);
  digitalWrite(MOTOR_B_DIR, b);
  
  //Liga novamente os motores
  analogWrite(MOTOR_A_PWM, vel);
  analogWrite(MOTOR_B_PWM, vel);
}

int define_state(){ //Determina o estado mais adequado
  int state;
  getDistances();

  if(rActivate == -1){
    state = -1;
  } else if(rActivate == 1 && rActivate_ll != rActivate){
    rActivate_ll = rActivate; //mesmo que carreguem de novo no botão verde ele não volta a este estado
    state = 0;
  } else if(distanceE <= SONAR_DIST && distanceD <= SONAR_DIST){
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

void send_state(){ //Envia o estado por BT
  BTserial.write(rState);
}

void send_state_byUSB(bool sendHeader){ //Envia o estado por BT
  if(sendHeader == true){
    Serial.print("rState\trActivate\trActivate_ll\tdurationF\tdurationD\tdurationE\tangle_chama\tangle_servo\tincrm_servo\tservo_enabled\tA desativar\tD E\tF D E\tF E\tF D\tchama\n");
  }
  Serial.print(rState);
  Serial.print("\t");
  Serial.print(rActivate);
  Serial.print("\t");
  Serial.print(rActivate_ll);
  Serial.print("\t");
  Serial.print(durationF);
  Serial.print("\t");
  Serial.print(durationD);
  Serial.print("\t");
  Serial.print(durationE);
  Serial.print("\t");
  Serial.print(angle_chama);
  Serial.print("\t");
  Serial.print(angle_servo);
  Serial.print("\t");
  Serial.print(incrm_servo);
  Serial.print("\t");
  Serial.print(servo_enabled);
  Serial.print("\t");
  Serial.print((rActivate == 1 && rActivate_ll != rActivate));
  Serial.print("\t");
  Serial.print((distanceE <= SONAR_DIST && distanceD <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((distanceF <= SONAR_DIST && distanceD <= SONAR_DIST && distanceE <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((distanceF <= SONAR_DIST && distanceE <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((distanceF <= SONAR_DIST && distanceD <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((analogRead(A0) >= CHAMA_PARAM));
  Serial.print("\n");

}

void operations(){ //Atua perante o estado
  //Atua mediante o estado
  switch(rState){
    case -1: //Desativado
      setSpeeds(MOTOR_MOVE_FORWARD, 0); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 0;
      break;
    case 0: //Parado
      setSpeeds(MOTOR_MOVE_FORWARD, 0); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 0;
      break;
    case 1: //Andar para a Frente
      setSpeeds(MOTOR_MOVE_FORWARD, MOTOR_VEL); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 1;
      break;
    case 2: //Andar para a Trás
      setSpeeds(MOTOR_MOVE_BACKWARD, MOTOR_VEL); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 1;
      break;
    case 3: //Rodar para a direita
      setSpeeds(MOTOR_MOVE_RIGHT, MOTOR_VEL); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 1;
      break;
    case 4: //Rodar para a esquerda
      setSpeeds(MOTOR_MOVE_LEFT, MOTOR_VEL); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 1;
      break;
    case 5: //Apagar a chama
      setSpeeds(MOTOR_MOVE_FORWARD, 0); //Desliga Motores
      digitalWrite(VENTOINHA_INA, HIGH);
      servo_enabled = 1;
      break;
    default:
      setSpeeds(MOTOR_MOVE_FORWARD, 0); //Desliga Motores
      digitalWrite(VENTOINHA_INA, LOW);
      servo_enabled = 0;
      break;
  }
}

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  BTserial.begin(38400); 
  Serial.begin(9600);
  
  //Função de interrupção
  attachInterrupt(digitalPinToInterrupt(BOTAO_INTRP), changeRobotActivationState, CHANGE);

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
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(CHAMA_PIN, INPUT);
  pinMode(CHAMA_LED, OUTPUT);
  pinMode(BOTAO_START, INPUT);
  pinMode(BOTAO_INTRP, INPUT);
  
  //Definição do estado inicial do robot
  int rActivate = -1;
  int rActivate_ll = -1;

  //Angulo Inicial do Servo
  angle_servo = 90;

  //Config Servo
  servo.attach(SERVO_PIN);
  servo.write(angle_servo);
  
  send_state_byUSB(true); //Envia o estado atual para o SI
}

void loop() {
  rState = define_state();//Determina o estado adequado
  operations(); //Define o movimento do robot
  send_state(); //Envia o estado atual para o SI
  send_state_byUSB(false); //Envia o estado atual para o SI

  if(servo_enabled == 1){
    //Evita rotações não possiveis
    incrm_servo = (angle_servo == SERVO_MAX_ANGLE) ? -1 : incrm_servo;
    incrm_servo = (angle_servo == SERVO_MIN_ANGLE) ? 1 : incrm_servo;

    angle_servo += incrm_servo; //Define o angulo
    servo.write(angle_servo); //Roda o servo
  }



  
  
  
}
