#include "params.h" //Parametros de configuração
/*void send_state_byUSB(bool sendHeader, int rActivate = -1;    //Estado de ativação
int rActivate_ll = -1; //Indica o estado de ativação antes da ultima alteração
int rState = -1, int durationF, int durationD, durationE, int angle_chama, int angle_servo, int incrm_servo, int servo_enabled){ //Envia o estado por BT
  if(sendHeader == true){
    Serial.print("rState\trActivate\trActivate_ll\tdistanceF\tdistanceD\tdistanceE\tangle_chama\tangle_servo\tincrm_servo\tservo_enabled\tA desativar\tD E\tF D E\tF E\tF D\tchama\n");
  }
  Serial.print(rState);
  Serial.print("\t");
  Serial.print(rActivate);
  Serial.print("\t");
  Serial.print(rActivate_ll);
  Serial.print("\t");
  Serial.print(distanceF);
  Serial.print("\t");
  Serial.print(distanceD);
  Serial.print("\t");
  Serial.print(distanceE);
  Serial.print("\t");
  Serial.print(angle_chama);
  Serial.print("\t");
  Serial.print(angle_servo);
  Serial.print("\t");
  Serial.print(incrm_servo);
  Serial.print("\t");
  Serial.print(servo_enabled);
  Serial.print("\t");
  Serial.print((rActivate == 1 && rActivate_ll != rActivate));
  Serial.print("\t");
  Serial.print((distanceE <= SONAR_DIST && distanceD <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((distanceF <= SONAR_DIST && distanceD <= SONAR_DIST && distanceE <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((distanceF <= SONAR_DIST && distanceE <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((distanceF <= SONAR_DIST && distanceD <= SONAR_DIST));
  Serial.print("\t");
  Serial.print((analogRead(A0) >= CHAMA_PARAM));
  Serial.print("\n");
}*/
