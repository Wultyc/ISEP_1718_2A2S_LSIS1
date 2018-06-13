#include "params.h" //Parametros de configuração
void debug_main(bool sendHeader, int rActivate, int rActivate_ll, int rState, int angle_chama, int angle_servo, int incrm_servo, int servo_enabled){
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

