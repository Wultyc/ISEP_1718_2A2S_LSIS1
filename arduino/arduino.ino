//Parametrizacao
#define MOTOR_A_DIR = 12;
#define MOTOR_B_DIR = 13;
#define MOTOR_A_PWM = 3;
#define MOTOR_B_PWM = 11;
//#define MOTOR_A_BRK = 9;
//#define MOTOR_B_BRK = 8;
#define MOTOR_A_CS = "A0";
#define MOTOR_B_CS = "A1";

#define SONAR_TRIG = 2;
#define SONAR_ECHO_FRENTE = "A2";
#define SONAR_ECHO_DIREITA = "A3";
#define SONAR_ECHO_ESQUERDA = "A4";
#define SONAR_DIST = 7;

#define VENTOINHA_INA = 6;

#define SERVO_MOTOR = 10;
#define SERVO_DELAY = 25;

#define CHAMA_PIN = "A5";
#define CHAMA_LED = 7;

#define BT_RX = 8;
#define BT_TX = 9;

#define BOTAO_VERDE = 4;
#define BOTAO_VERML = 5;

int rActivate = 0;
int rState = -1;

int define_state(){
  return 0;
}

bool send_state(int state){
  return true;
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //Determina o estado adequado
  rState = define_state();

  //Envia ao Sistema de Informação
  send_state(rState);

  //Atua mediante o estado
  switch(rState){
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
