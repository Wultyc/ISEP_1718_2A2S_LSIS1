#include <Servo.h>
#include <SoftwareSerial.h>

#include "param.h" //Parametros de configuração

Servo servo;  //Objeto de controlo do servo
SoftwareSerial Bluetooth(BT_RX, BT_TX); //Definição do Bluetooth

int estado = 0; //Estado do robot
int desativa_robot = 0; //mantem o robot desativado
int btnStart = 0, btnStop = 0; //Valor dos botões de Start e Stop
int distF = 0, distD = 0, distE = 0, chama = 0; //Valores de Input
int velA = 0, velB = 0, dirA = 0, dirB = 0, velProp = 0, dalayRobot = 0; //Valores de output
int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_enabled = 0; //Define se o servo roda ou não

int velP = 128; int delayP = 100; int delayS = 1250; 

String estados[7] = {"Desat","Fente","Tras","Direita","Esquerda","Chama"};

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  Bluetooth.begin(9600);
  Serial.begin(9600);

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
  btnStop = digitalRead(BOTAO_STOP);
  
  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  distF = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
  distD = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);
  distE = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);

  //Lê o sensor de chama;
  chama = analogRead(CHAMA_PIN);

  if(desativa_robot == 0){
    estado = 0;
    
  } else if (chama >= CHAMA_PARAM){ estado = 5;}
  else if(distF > SONAR_DIST_MIN){ estado = 1;}
  else if (distF <= SONAR_DIST_MIN || distD <= SONAR_DIST_MIN || distE <= SONAR_DIST_MIN){estado = 2;}
  else if ( (distD > distE*1.10 || distD >= SONAR_ROOM) && distF <= SONAR_ROOM_FRENTE){estado = 3;}
  else if ( (distE > distD*1.10 || distE >= SONAR_ROOM) && distF <= SONAR_ROOM_FRENTE){estado = 4;}
  
  //Atua mediante o estado
  switch(estado){
    case 0: //Desativado
      if(btnStart == HIGH){
        estado = 1;
        desativa_robot = 1;
      } else {
        roboPara(delayS);
        estado = 0;
        servo_enabled = 0;
      }
      break;
    case 1: //Andar em Frente
      roboPara(delayS);
      frente(delayP);
      velProp = VENTOINHA_MIN; velProp = 255; analogWrite(VENTOINHA_INA, velProp);
      servo_enabled = 1;
      break;
    case 2: //Andar para tras
      roboPara(delayS);
      direita(delayP*2); //Roda 2x 90º
      frente(delayP);
      velProp = VENTOINHA_MIN; velProp = 255; analogWrite(VENTOINHA_INA, velProp);
      servo_enabled = 1;
      break;
    case 3: //Rodar à direita
      roboPara(delayS);
      direita(delayP);
      frente(delayP);
      velProp = VENTOINHA_MIN; velProp = 255; analogWrite(VENTOINHA_INA, velProp);
      servo_enabled = 1;
      break;
    case 4: //Rodar à equerda
      roboPara(delayS);
      esquerda(delayP);
      frente(delayP);
      velProp = VENTOINHA_MIN; velProp = 255; analogWrite(VENTOINHA_INA, velProp);
      servo_enabled = 1;
      break;
    case 5: //Apagar a chama
      roboPara(0);
      velProp = VENTOINHA_MAX; analogWrite(VENTOINHA_INA, velProp);
      servo_enabled = 1;
      break;
  }    

  //Roda o Servo
  if(servo_enabled == 1){
    //Evita rotações não possiveis
    /*incrm_servo = (angle_servo == SERVO_MAX_ANGLE) ? -10 : incrm_servo;
    incrm_servo = (angle_servo == SERVO_MIN_ANGLE) ? 10 : incrm_servo;
    angle_servo += incrm_servo; //Define o angulo*/

    for(angle_servo = SERVO_MIN_ANGLE; angle_servo <= SERVO_MAX_ANGLE; angle_servo ++){
      servo.write(angle_servo); //Roda o servo
      delay(20);
    }
    for(angle_servo = SERVO_MAX_ANGLE; angle_servo <= SERVO_MIN_ANGLE; angle_servo ++){
      servo.write(angle_servo); //Roda o servo
      delay(20);
    }

  }

  //Envia a informação
  //Bluetooth.println(estado);
  Bluetooth.println("Estato\tFrente\t Esquerda\tDireita");  
  Bluetooth.println("" + (String)estado + "\t" + (String)distF + "\t" + (String)distE + "\t" + (String)distD + "\t");

  Serial.println("Estato\tFrente\tEsq\tDireita\tServo\tAngulo");  
  Serial.println(estados[estado] + "\t" + (String)distF + "\t" + (String)distE + "\t" + (String)distD + "\t" + (String) servo_enabled +  "\t" + (String) angle_servo);
}

int getDistance(int trig, int echo){
  //Limpeza do Pino Trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  //Ativa o Pin Trig por 10 microsegundos
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  int dist = pulseIn(echo, HIGH)*0.034/2;
  return dist;
}

void roboPara(int duracao){
  //Motor A
  analogWrite(MOTOR_A_PWM, 0);
  //Motor B
  analogWrite(MOTOR_B_PWM, 0);
  //delay
  delay(duracao);
}
void frente(int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, velP);
  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, velP);
  //delay
  delay(duracao);
}

void tras(int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, velP);
  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, velP);
  //delay
  delay(duracao);
}

void esquerda(int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, velP);
  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, velP);
  //delay
  delay(duracao);
}

void direita(int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, velP);
  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, velP);
  //delay
  delay(duracao);
}
