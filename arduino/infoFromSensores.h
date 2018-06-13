#include "params.h" //Parametros de configuração
//Determina a distancia dos sonares aos objetos

void getDistances(int distance[]){
  //Limpeza do Pino Trig
  digitalWrite(SONAR_TRIG, LOW);
  delayMicroseconds(2);
  
  //Ativa o Pin Trig por 10 microsegundos
  digitalWrite(SONAR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG, LOW);
  
  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  int durationF = pulseIn(SONAR_ECHO_FRENTE, HIGH);
  int durationD = pulseIn(SONAR_ECHO_DIREITA, HIGH);
  int durationE = pulseIn(SONAR_ECHO_ESQUERDA, HIGH);
  
  //Calculo da distancia
  distance[0] = durationF*0.034/2;
  distance[1] = durationD*0.034/2;
  distance[2] = durationE*0.034/2;
}

/*************************************************************************************/

int define_state(int rActivate, int rActivate_ll){ //Determina o estado mais adequado
  int state;
  int distances[3] = {0,0,0};
  getDistances(distances);

  if(rActivate == -1){
    state = -1;
  } else if(rActivate == 1 && rActivate_ll != rActivate){
    state = 0;
  } else if(distances[2] <= SONAR_DIST && distances[1] <= SONAR_DIST){
    state = 1;
  } else if(distances[0] <= SONAR_DIST && distances[1] <= SONAR_DIST && distances[2] <= SONAR_DIST){
    state = 2;
  } else if(distances[0] <= SONAR_DIST && distances[4] <= SONAR_DIST){
    state = 3;
  } else if(distances[0] <= SONAR_DIST && distances[3] <= SONAR_DIST){
    state = 4;
  } else if(analogRead(CHAMA_PIN) >= CHAMA_PARAM){
    state = 5;
  } else{
    state = 1;
  }
  
  return state;
}
