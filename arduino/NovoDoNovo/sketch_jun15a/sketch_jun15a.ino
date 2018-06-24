//Botões de Ativação
#define BOTAO_START 4
#define BOTAO_STOP 2

int CHAMA_LED = 7;
int sensorChama = A5;

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

int fan = 6;

#include <Servo.h>
Servo servo;  //Objeto de controlo do servo

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(0, 1); // RX, TX

double distanciaVal;
int desativa_robot = 0; //mantem o robot desativado
int duracao, count = 0, motorAspeed, motorBspeed, estado = 0;
int andaFrente = 0;
int andaEsquerda = 0 ;
int andaDireita = 0;
int btnStart = 0, btnStop = 0; //Valor dos botões de Start e Stop

int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_return = 0; //Define o sentido de rotação (1: sentido positivo | -1: sentido negativo)
int servoFlag = 0;  //Determina o numero de passagem nos 90º

int chama = 0; //Valores do sensor de chama
int chama_param = 0;


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
  
  pinMode(CHAMA_LED, OUTPUT);
  pinMode(fan,OUTPUT);
  analogWrite(fan, 255);
  pinMode(BOTAO_START, INPUT);
  pinMode(BOTAO_STOP, INPUT);

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

void frenteComDuracao(int motorAspeed, int motorBspeed, int duracao) {

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

void detetaChama() {
  /*if (analogRead(sensorChama) > 500) {//se detetar valor acima de 600
    roboPara();//para o robo
    ledChama();//liga o led
    Serial.print("5"); //robot detetou chama
    do {

      digitalWrite(fan, HIGH);
      delay(3000);
    } while (analogRead(sensorChama) > 500);//enquanto detetar valor acima de 600,deixa a ventoinha ligada
    Serial.print("0"); //robot apagou a vela
  }
  else  if (analogRead(sensorChama) <= 500) {//senão ventoinha e led desligados
    digitalWrite(CHAMA_LED, LOW);//Led desliga
    digitalWrite(fan, LOW);//Fan desliga
  }*/
  roboPara();
  while (analogRead(sensorChama) >= 500) {
    ledChama();//Enquanto há chama mantem o propeller a trabalhar
    analogWrite(fan, 0);
    delay(4000);
  }

  analogWrite(fan,255); //desliga o propeller
  
}

void ledChama() {
  if (analogRead(sensorChama) > 500) {
    digitalWrite(CHAMA_LED, HIGH);
    delay(3000);
    digitalWrite(CHAMA_LED, LOW);

  }
}

void loop() {
  // put your main code here, to run repeatedly:

  switch (estado) {
   case 0:
    roboPara();
    while(digitalRead(BOTAO_START)==HIGH){
      estado = 1;
    }break;
    case 1:
      if(digitalRead(BOTAO_STOP)==HIGH){
        Serial.println("DESLIGUEI!");
        //roboParaD();
        estado = 0;
      }else{
        
        detetaChama();
        frente(175, 175);
        do {
          andaFrente = lerSonar(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
          andaEsquerda = lerSonar(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
          andaDireita = lerSonar(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);
        } while (andaFrente > 30 && andaDireita < 60 && andaEsquerda < 60);
  
        roboPara();
        andaFrente = lerSonar(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
        andaEsquerda = lerSonar(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
        andaDireita = lerSonar(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);
  
        if (andaFrente < 30) {
          estado = 4;
        } else if (andaDireita > 60 || andaEsquerda > 60) {
          estado = 4;
        }
      }
      break;
    case 2:
    roboPara();
      if(digitalRead(BOTAO_STOP)==HIGH){
        Serial.println("DESLIGUEI!");
          //roboParaD();
          estado = 0;
      }else{
        detetaChama();
        roboPara();
        frenteComDuracao(150,150,150);
        direita(125, 250, 1800);
        frenteComDuracao(150, 150, 500);
        andaFrente = lerSonar(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
        if (andaFrente > 70) {
          frenteComDuracao(150, 150, 3000);
        }
        estado = 1;
      }
      break;
    case 3:
    
      roboPara();
      btnStop = digitalRead(BOTAO_STOP) ;
      if(btnStop==HIGH){
        Serial.println("DESLIGUEI!");
          //roboParaD();
      }else{
        detetaChama();
        roboPara();
        frenteComDuracao(150,150,150);
        esquerda(250, 100, 1700);
        frenteComDuracao(150, 150, 750);
        andaFrente = lerSonar(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
        if (andaFrente > 70) {
          frenteComDuracao(150, 150, 3000);
        }
        estado = 1;
      }
      break;
    case 4:
    roboPara();
      if(digitalRead(BOTAO_STOP)==HIGH){
        Serial.println("DESLIGUEI!");
          //roboParaD();
          estado = 0;
      }else{
        roboPara();
        andaDireita = lerSonar(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);
        roboPara();
        andaEsquerda = lerSonar(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA) * 0.75;
        if (andaDireita < andaEsquerda) {
          estado = 3;
        } else {
          estado = 2;
        }
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

void roboParaD() {
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  delay(30000);
}

