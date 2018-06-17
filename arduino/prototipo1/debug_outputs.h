void debug_outputs(bool sendHeader, int dirM, int velM, int velV){
  if(sendHeader == true){
    Serial.print("Direção Motores\tVelocidade Motores\tVelocidade Ventoinha\n");
  }
  Serial.print(dirM);
  Serial.print("\t");
  Serial.print(velM);
  Serial.print("\t");
  Serial.print(velV);
  Serial.print("\n");
}
