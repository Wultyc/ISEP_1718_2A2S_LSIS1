#include "params.h" //Parametros de configuração
void send_state_byUSB(bool sendHeader, int rActivate, int rActivate_ll, int rState, int angle_chama, int angle_servo, int incrm_servo, int servo_enabled){ //Envia o estado por BT
  if(sendHeader == true){
    Serial.print("rActivate\trActivate_ll\trState\tangle_chama\tangle_servo\tincrm_servo\tservo_enabled\n");
  }
  Serial.print(rActivate);
  Serial.print("\t");
  Serial.print(rActivate_ll);
  Serial.print("\t");
  Serial.print(rState);
  Serial.print("\t");
  Serial.print(angle_chama);
  Serial.print("\t");
  Serial.print(angle_servo);
  Serial.print("\t");
  Serial.print(incrm_servo);
  Serial.print("\t");
  Serial.print(servo_enabled);
  Serial.print("\n");
}

void debug_inputs(bool sendHeader, int distance[], int chama){
  if(sendHeader == true){
    Serial.print("Frente\tDireita\tEsquerda\tChama\n");
  }
  Serial.print(distance[0]);
  Serial.print("\t");
  Serial.print(distance[1]);
  Serial.print("\t");
  Serial.print(distance[3]);
  Serial.print("\t");
  Serial.print(chama);
  Serial.print("\n");
}

void debug_outputs(){
  
}

