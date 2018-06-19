const int SONAR_TRIG_FRENTE = 9;
const int SONAR_ECHO_FRENTE = A2;

const int SONAR_TRIG_DIREITA = 8;
const int SONAR_ECHO_DIREITA = A3;

const int SONAR_TRIG_ESQUERDA = 5;
const int SONAR_ECHO_ESQUERDA = A4;


const int MOTOR_A_DIR = 12;
const int MOTOR_B_DIR = 13;

const int MOTOR_A_PWM = 3;
const int MOTOR_B_PWM = 11;

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0,1); // RX, TX

double frenteVal, esquerdaVal, direitaVal, distanciaVal,cronometro=0;
int duracao, count = 0, motorAspeed, motorBspeed, estado=1;
int andaFrente = 0;
int andaEsquerda = 0 ;
int andaDireita = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Bluetooth.begin(9600);
  pinMode(SONAR_TRIG_FRENTE, OUTPUT);
  pinMode(SONAR_ECHO_FRENTE, INPUT);
  
  pinMode(SONAR_TRIG_ESQUERDA, OUTPUT);
  pinMode(SONAR_ECHO_ESQUERDA, INPUT);

  //Sonar direita
  pinMode(SONAR_TRIG_DIREITA, OUTPUT);
  pinMode(SONAR_ECHO_DIREITA, INPUT);

  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
}

void frente(int motorAspeed, int motorBspeed) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorAspeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorBspeed);

  //delay(duracao);
}

void frenteComDuracao(int motorAspeed, int motorBspeed,int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorAspeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorBspeed);

  delay(duracao);
}

void tras(int motorAspeed, int motorBspeed, int duracao) {
  
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorAspeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorBspeed);

  delay(duracao);
}

void esquerda(int motorAspeed, int motorBspeed, int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorAspeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorBspeed);

  delay(duracao);
}

void direita(int motorAspeed, int motorBspeed, int duracao) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorAspeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorBspeed);

  delay(duracao);
}


void roda180(int motorAspeed, int motorBspeed) {

  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorAspeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorBspeed);
}

double lerSonar(int sonarTrig, int sonarEcho) {
  //Limpa o trigger
  digitalWrite(sonarTrig, LOW);
  delayMicroseconds(2);

  //Liga o trigger por 10 milisegundos
  digitalWrite(sonarTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonarTrig, LOW);

  //Recebe a informação (eccho)
  distanciaVal = pulseIn(sonarEcho, HIGH) * 0.034 / 2;
  
  return distanciaVal;
}


void loop() {
  // put your main code here, to run repeatedly:
  
  switch(estado){
    case 1:
    frente(255,255);
     do{
      andaFrente = lerSonar(SONAR_TRIG_FRENTE,SONAR_ECHO_FRENTE);
      //andaEsquerda = lerSonar(SONAR_TRIG_ESQUERDA,SONAR_ECHO_ESQUERDA);
      //andaDireita = lerSonar(SONAR_TRIG_DIREITA,SONAR_ECHO_DIREITA);
     }while(andaFrente>15);

     roboPara();
     andaFrente = lerSonar(SONAR_TRIG_FRENTE,SONAR_ECHO_FRENTE);
     //andaEsquerda = lerSonar(SONAR_TRIG_ESQUERDA,SONAR_ECHO_ESQUERDA);
     //andaDireita = lerSonar(SONAR_TRIG_DIREITA,SONAR_ECHO_DIREITA);


     if(andaFrente<15){
      estado = 4;
     }/*else if(andaDireita>60 || andaEsquerda>60){
      estado = 4;
     }*/
     break;
    case 2:
      roboPara();
      direita(175,250,1250);
      frenteComDuracao(150,150,1000);
      estado = 1;
      break;
    case 3:
      roboPara();
      esquerda(250,175,1250);
      frenteComDuracao(225,225,1000);
      estado = 1;
      break;
    case 4:
    roboPara();
    andaDireita = lerSonar(SONAR_TRIG_DIREITA,SONAR_ECHO_DIREITA);
    roboPara();
    andaEsquerda = lerSonar(SONAR_TRIG_ESQUERDA,SONAR_ECHO_ESQUERDA);
     if(andaDireita<andaEsquerda){
        estado = 3;
      }else{
        estado = 2;
      }
      break;
  }
    Serial.println("Distancia: \t Frente \t Esquerda \t Direita");  
    Serial.print("\t \t");
    Serial.print(lerSonar(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE));
    Serial.print("\t \t");
    Serial.print(lerSonar(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA));
    Serial.print("\t \t");
    Serial.println(lerSonar(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA));
    Bluetooth.println("Distancia: \t Frente \t Esquerda \t Direita");
    Bluetooth.print("\t \t");
    Bluetooth.print(lerSonar(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE));
    Bluetooth.print("\t \t");
    Bluetooth.print(lerSonar(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA));
    Bluetooth.print("\t \t");
    Bluetooth.println(lerSonar(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA));
    Serial.print("Estado de Robo: ");
    Serial.println(estado);
}


void roboPara() {
  //Motor A
    analogWrite(MOTOR_A_PWM, 0);
  //Motor B
    analogWrite(MOTOR_B_PWM, 0);

  delay(1000);
}

void roboParaD(){
  analogWrite(MOTOR_A_PWM,0);
  analogWrite(MOTOR_B_PWM,0);
  delay(5000);
}

