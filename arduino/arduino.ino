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
#define BOTAO_VERML = 2;

int rActivate = 0;
int rActivate_ll = 0; //antes da modificação como estava?
int rState = -1;

void changeRobotActivationState(){
  if(digitalRead(BOTAO_VERDE) == HIGH){
    rActivate_ll = rActivate; //Preserva o estado atual de ativação
    rActivate = 1;            //Altera o estado de ativação
  } else {
    rActivate_ll = rActivate;
    rActivate = 0;
  }
}

int define_state(){ //Determina o estado mais adquado
  return 0;
}

bool send_state(int state){ //Envia o estado por BT
  return true;
}

void operations(int state){ //Atua perante o estado
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

void setup() {
  //Função de interrupção
  attachInterrupt(digitalPinToInterrupt(BOTAO_VERML), changeRobotActivationState, CHANGE);

  //PinModes
  pinMode(MOTOR_A_DIR, OUTPUT)
  pinMode(MOTOR_B_DIR, OUTPUT)
  pinMode(MOTOR_A_PWM, OUTPUT)
  pinMode(MOTOR_B_PWM, OUTPUT)
  pinMode(MOTOR_A_CS, OUTPUT)
  pinMode(MOTOR_B_CS, OUTPUT)
  pinMode(SONAR_TRIG, OUTPUT)
  pinMode(SONAR_ECHO_FRENTE, INPUT)
  pinMode(SONAR_ECHO_DIREITA, INPUT)
  pinMode(SONAR_ECHO_ESQUERDA, INPUT)
  pinMode(VENTOINHA_INA, OUTPUT)
  pinMode(SERVO_MOTOR, OUTPUT)
  pinMode(CHAMA_PIN, INPUT)
  pinMode(CHAMA_LED, OUTPUT)
  //pinMode(BT_RX, )
  //pinMode(BT_TX, )
  pinMode(BOTAO_VERDE, INPUT)
  pinMode(BOTAO_VERML, INPUT)
  //Definição do estado inicial do robot
  int rActivate = 0;
  int rActivate_ll = 0;
}

void loop() {

  if(rActivate == 1){ //Robot ativo
    
    rState = define_state();//Determina o estado adequado
    operations(rState); //Executa a operação associa ao estado rState
    
  } else if(rActivate == 0 && rActivate_ll != rActivate){ //Robot recem inativado
    
    //Desliga todo o movimento
    /*
    * Código de desativação
    */
    rState = -1;//Define o estado para -1
    rActivate_ll == rActivate //Iguala os estados
    
  } else{ //O robot já está inativo à pelo meno um ciclo
    
    rState = -1;//Define o estado para -1
    
  }
  
  send_state(rState); //Envia o estado atual para o SI
  
}
