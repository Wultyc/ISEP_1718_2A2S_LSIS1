#include "params.h" //Parametros de configuração
#include "debug.h" //Funções de debug
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
  
  //Atua mediante o estado
  switch(state){
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

  return servo_enabled;
}
