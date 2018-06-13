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
