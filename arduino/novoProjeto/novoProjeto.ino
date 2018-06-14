const int SONAR_TRIG = 5;
const int SONAR_ECHO_FRENTE = A2;
const int SONAR_ECHO_DIREITA = A3;
const int SONAR_ECHO_ESQUERDA = A4;


const int MOTOR_A_DIR = 12;
const int MOTOR_B_DIR = 13;
const int MOTOR_A_PWM = 3;
const int MOTOR_B_PWM = 11;



double frenteVal, esquerdaVal, direitaVal, distanciaVal,cronometro=0;
int duracao, count = 0, motorAspeed, motorBspeed, estado=1;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(SONAR_ECHO_FRENTE, INPUT);
  
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(SONAR_ECHO_ESQUERDA, INPUT);

  //Sonar direita
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(SONAR_ECHO_DIREITA, INPUT);

  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
}

void frente(int motorAspeed, int motorBspeed, int duracao) {

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
      frente(80,80,1250);
      Serial.println(distanciaVal);
      if(lerSonar(SONAR_TRIG,SONAR_ECHO_FRENTE)<20){
        estado = 2;
      }else{
        estado = 1;
      }
      break;
    case 2:
      delay(250);
      if(lerSonar(SONAR_TRIG,SONAR_ECHO_DIREITA)<20){
        Serial.println("Vou virar Esquerda");
        Serial.println(distanciaVal);
        estado = 3 ;
      }else{
        Serial.println("Vou virar Direita");
        Serial.println(distanciaVal);
        estado = 4 ;
      }
      break;
    case 3:
      delay(250);
      if(lerSonar(SONAR_TRIG,SONAR_ECHO_ESQUERDA)<20){
        Serial.println("Vou andar para Tras");
        tras(80,80,1250);
      }else{
        estado = 5;
      }
      break;
    case 4:
      roboPara();
      direita(100,100,1250);
      estado = 1;
      delay(250);
      break;
    case 5:
      roboPara();
      esquerda(100,100,1250);
      estado = 1;
      delay(1000);
      break;
  }  
}


void roboPara() {
  //Motor A
    analogWrite(MOTOR_A_PWM, 0);
  //Motor B
    analogWrite(MOTOR_B_PWM, 0);

  delay(1000);
}
