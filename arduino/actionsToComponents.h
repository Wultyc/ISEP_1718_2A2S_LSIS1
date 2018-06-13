#include "params.h" //Parametros de configuração
#include "debug_outputs.h" //Funções de debug

//Atribui as velocidades
void setSpeeds(int dir, int vel){
  int a, b;
  //Desliga os motores
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  
  switch(dir){
    case 1:
      a = HIGH;
      b = HIGH;
      break;
    case 2:
      a = LOW;
      b = LOW;
      break;
    case 3:
      a = LOW;
      b = HIGH;
      break;
    case 4:
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

int setDefaultOutput(){
  //Direciona os motores
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  
  //Liga novamente os motores
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);

  //Desliga o Propeler
  digitalWrite(VENTOINHA_INA, LOW);

  //retorna o valor para o servo
  return 0;
}

/*********************************************************************************************/
int operations(int state){ //Atua perante o estado
  
  int servo_enabled = 0; //Variavel que vai contrlar o servo no loop()
  int velM, dirM, velV;
  
  //Atua mediante o estado
  switch(state){
    case -1: //Desativado
      dirM = MOTOR_MOVE_FORWARD;
      velM =0;
      velV = LOW;
      servo_enabled = 0;
      break;
    case 0: //Parado
      dirM = MOTOR_MOVE_FORWARD;
      velM =0;
      velV = LOW;
      servo_enabled = 0;
      break;
    case 1: //Andar para a Frente
      dirM = MOTOR_MOVE_FORWARD;
      velM = MOTOR_VEL;
      velV = LOW;
      servo_enabled = 0;
      break;
    case 2: //Andar para a Trás
      dirM = MOTOR_MOVE_BACKWARD;
      velM = MOTOR_VEL;
      velV = LOW;
      servo_enabled = 0;
      break;
    case 3: //Rodar para a direita
      dirM = MOTOR_MOVE_RIGHT;
      velM =MOTOR_VEL;
      velV = LOW;
      servo_enabled = 1;
      break;
    case 4: //Rodar para a esquerda
      dirM = MOTOR_MOVE_LEFT;
      velM =MOTOR_VEL;
      velV = LOW;
      servo_enabled = 1;
      break;
    case 5: //Apagar a chama
      dirM = MOTOR_MOVE_FORWARD;
      velM =0;
      velV = HIGH;
      servo_enabled = 1;
      break;
    default:
      dirM = MOTOR_MOVE_FORWARD;
      velM =0;
      velV = LOW;
      servo_enabled = 1;
      break;
  }
  //debug_outputs(false, dirM, velM, velV);

  //Escreve as alterações nos pinos
  setSpeeds(dirM, velM);
  digitalWrite(VENTOINHA_INA, velV);

  return servo_enabled;
}
