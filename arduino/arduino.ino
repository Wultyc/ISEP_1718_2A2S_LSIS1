#include <Servo.h>
#include <SoftwareSerial.h>

#include "params.h" //Parametros de configuração
#include "debug.h" //Funções de debug

#include "actionsToComponents.h" //Funções de modificação de estado dos componentes
#include "infoFromSensores.h" //Funções de obtenção de informação dos sensores

Servo servo;  //Objeto de controlo do servo
SoftwareSerial BTserial(BT_RX, BT_TX); //Definição do Bluetooth

int rActivate = 0;    //Estado de ativação
int rActivate_ll = 0; //Indica o estado de ativação antes da ultima alteração
int rState = -1;      //Estado

int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_enabled = 0;

//Envia o estado por BT
void send_state(int state){ 
  BTserial.write(state);
}

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  BTserial.begin(38400); 
  Serial.begin(9600);

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
  //pinMode(VENTOINHA_INA, OUTPUT);
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(CHAMA_PIN, INPUT);
  pinMode(CHAMA_LED, OUTPUT);
  pinMode(BOTAO_START, INPUT);
  pinMode(BOTAO_INTRP, INPUT);
  
  //Definição do estado inicial do robot
  rActivate = 0;
  rActivate_ll = 0;
  setDefaultOutput();
  
  //Config Servo
  servo.attach(SERVO_PIN);
  servo.write(angle_servo);
  angle_servo = 90;
  servo_enabled = 1;

  //Debug
  //debug_main(true, rActivate, rActivate_ll, rState, angle_chama, angle_servo, incrm_servo, servo_enabled); //Debug dos estados
}

void loop() {

  if(digitalRead(BOTAO_START) == HIGH){
    rActivate_ll = rActivate; //Preserva o estado atual de ativação
    rActivate = 1;            //Altera o estado de ativação
    Serial.print("Ativa");
  } else if(digitalRead(BOTAO_INTRP) == HIGH){
    rActivate_ll = rActivate;
    rActivate = 0;
  }
  
  rState = define_state(rActivate, rActivate_ll);//Determina o estado adequado
  servo_enabled = operations(rState); //Define o movimento do robot
  send_state(rState); //Envia o estado atual para o SI
  
  //debug_main(false, rActivate, rActivate_ll, rState, angle_chama, angle_servo, incrm_servo, servo_enabled);

  if(servo_enabled == 1){
    //Evita rotações não possiveis
    incrm_servo = (angle_servo == SERVO_MAX_ANGLE) ? -1 : incrm_servo;
    incrm_servo = (angle_servo == SERVO_MIN_ANGLE) ? 1 : incrm_servo;

    angle_servo += incrm_servo; //Define o angulo
    servo.write(angle_servo); //Roda o servo
  }

  rActivate_ll = rActivate;  

  delay(REACT_TIME);
  
}

 

