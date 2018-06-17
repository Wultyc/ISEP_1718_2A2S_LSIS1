#include <Servo.h>
#include <SoftwareSerial.h>

#include "param.h" //Parametros de configuração

Servo servo;  //Objeto de controlo do servo
SoftwareSerial Bluetooth(BT_RX, BT_TX); //Definição do Bluetooth

int estado = 0; //Estado do robot
int btnStart = 0, btnStop = 0; //Valor dos botões de Start e Stop
int distF = 0, distD = 0, distE = 0, chama = 0; //Valores de Input
int velA = 0, velB = 0, dirA = 0, dirB = 0, velProp = 0, dalayRobot = 0; //Valores de output
int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_enabled = 0; //Define se o servo roda ou não

String estados[7] = {"Desativado","Parado","Fente","Tras","Direita","Esquerda","Apagar Chama"};

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  Bluetooth.begin(9600);
  Serial.begin(9600);

  /*//PinModes
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
  pinMode(BOTAO_INTRP, INPUT);*/

  estado = 0;

  //Config Servo
  servo.attach(SERVO_PIN);
  angle_servo = 90;
  servo.write(angle_servo);

}

void loop() {
  //Lê os inputs
  btnStart = digitalRead(BOTAO_START);
  btnStop = digitalRead(BOTAO_STOP);
  
  //Limpeza do Pino Trig
  digitalWrite(SONAR_TRIG, LOW);
  delayMicroseconds(2);
  
  //Ativa o Pin Trig por 10 microsegundos
  digitalWrite(SONAR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG, LOW);
  
  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  distF = pulseIn(SONAR_ECHO_FRENTE, HIGH)*0.034/2;
  distD = pulseIn(SONAR_ECHO_DIREITA, HIGH)*0.034/2;
  distE = pulseIn(SONAR_ECHO_ESQUERDA, HIGH)*0.034/2;

  //Lê o sensor de chama;
  chama = analogRead(CHAMA_PIN);

  //Atua mediante o estado
  switch(estado){
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
  }

  //Aplica outputs

  //Roda o Servo
  if(servo_enabled == 1){
    //Evita rotações não possiveis
    incrm_servo = (angle_servo == SERVO_MAX_ANGLE) ? -1 : incrm_servo;
    incrm_servo = (angle_servo == SERVO_MIN_ANGLE) ? 1 : incrm_servo;

    angle_servo += incrm_servo; //Define o angulo
    servo.write(angle_servo); //Roda o servo
  }

  //Envia a informação
  Bluetooth.println(estado);
  Serial.println(estados[estado]);

  //Aplica o delay
  delay(dalayRobot);
}
