#include <Servo.h>
#include <SoftwareSerial.h>

#include "param.h" //Parametros de configuração

Servo servo;  //Objeto de controlo do servo
SoftwareSerial Bluetooth(BT_RX, BT_TX); //Definição do Bluetooth

int desativa_robot = 0; //mantem o robot desativado
int ultimo_estado = -1; //ultimo estado enviado
int estado = 0;

int btnStart = 0, btnStop = 0; //Valor dos botões de Start e Stop

int chama = 0; //Valores do sensor de chama
int chama_param = 0;

int velA = 0, velB = 0, dirA = 0, dirB = 0, velProp = 0, dalayRobot = 0; //Valores de output

int angle_chama = 0;  //Angulo da chama em relação ao robot
int angle_servo = 0;  //Angulo atual do Servo
int incrm_servo = 1;  //Incremento do anglulo do servo
int servo_return = 0; //Define o sentido de rotação (1: sentido positivo | -1: sentido negativo)
int servoFlag = 0;    //Determina o numero de passagem nos 90º
int first_sprint = 0; //Primeira caminhada

int velP = 255; int delayP = 1000; int delayS = 100;

double distF = 0, distE = 0, distD = 0, distE2 = 0, distD2 = 0;
bool validaF = false, validaE = false, validaD = false;
int rotD = 0, rotE = 0;

void desativa() {
  desativa_robot = 0;
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(VENTOINHA_INA, VENTOINHA_MIN);
  servo.write(90);
}

void setup() {
  //Inicializa a comunicação Serial via Bluetooth
  Bluetooth.begin(9600);
  Serial.begin(9600);

  //Função de interrupção
  attachInterrupt(digitalPinToInterrupt(2), desativa, RISING);

  //Output inicial
  velA = 0; velB = 0;
  dirA = 0; dirB = 0;
  velProp = 0; dalayRobot = 0;

  //PinModes e valor padrão
  pinMode(MOTOR_A_CS, OUTPUT);
  pinMode(MOTOR_B_CS, OUTPUT);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);

  pinMode(SONAR_TRIG_FRENTE, OUTPUT);
  pinMode(SONAR_TRIG_DIREITA, OUTPUT);
  pinMode(SONAR_TRIG_ESQUERDA, OUTPUT);
  pinMode(SONAR_ECHO_FRENTE, INPUT);
  pinMode(SONAR_ECHO_DIREITA, INPUT);
  pinMode(SONAR_ECHO_ESQUERDA, INPUT);

  pinMode(VENTOINHA_INA, OUTPUT);
  analogWrite(VENTOINHA_INA, VENTOINHA_MIN);

  pinMode(SERVO_PIN, OUTPUT);

  pinMode(CHAMA_PIN, INPUT);
  pinMode(CHAMA_LED, OUTPUT);

  pinMode(BOTAO_START, INPUT);
  pinMode(BOTAO_STOP, INPUT);

  ultimo_estado = -1;
  first_sprint = 0;

  //Config Servo
  servo.attach(SERVO_PIN);
  angle_servo = 90;
  servo.write(angle_servo);

  chama_param = 800; //analogRead(CHAMA_PIN) * 3.00;
}

void loop() {
  if (desativa_robot == 0) {
    //Lê os inputs
    btnStart = digitalRead(BOTAO_START);
    
    if (btnStart == HIGH) {
      desativa_robot = 1;
      estado = 1;
    }else{
      estado = 0;
    }

  } else {
    switch (estado) {
      case 1: //frente
        enviarEstado(1);
        //Se for o primeiro sprint, anda um bocadinho a mais
        if (first_sprint == 0) {
          frente(velP, delayP * 1.5);
          robotPara(delayS);
          first_sprint = 1;
        }

        //Calcula distancias
        distF = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
        distE = distE2 = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
        distD = distD2 = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);

        frente(velP, 0); //Anda em frente

        //Aplica movimento
        do {
          //guarda as medidas atuais
          distE2 = distE;
          distD2 = distD;

          //Calcular as distancias novas
          distF = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
          distE = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
          distD = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);

          //Valida as medidas
          validaF = distF >= SONAR_DIST_MIN;
          validaD = distD <= SONAR_ROOM;
          validaE = distE <= SONAR_ROOM;
        
        } while (validaF == true && validaD == true && validaE == true);
        para(); //para o robot

        //Calcular as distancias novas
        distF = getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE);
        distE = getDistance(SONAR_TRIG_ESQUERDA, SONAR_ECHO_ESQUERDA);
        distD = getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA);

        if (distF <= SONAR_DIST_MIN && distD <= SONAR_DIST_MIN && distE <= SONAR_DIST_MIN) {
          estado = 5;
          Serial.println("IF A");
        }else if (distF <= SONAR_DIST_MIN && (distD <= SONAR_DIST_MIN || distE <= SONAR_DIST_MIN) && (distE <= SONAR_ROOM || distD <= SONAR_ROOM)) {
          estado = 5;
          Serial.println("IF B");
        } else if (distE >= distF * 1.25 && distE < distF * 2.00) {
          estado = 1;
          Serial.println("IF C");
        } else if (distD >= SONAR_ROOM && rotD < RotMax) { //direita
          estado = 3;
          Serial.println("IF D");
        } else if (distE >= SONAR_ROOM && rotE < RotMax) { //esquerda
          estado = 4;
          Serial.println("IF E");
        } else if (rotD >= RotMax && distE >= SONAR_DIST_MIN) {
          estado = 4;
          
          Serial.println("IF F");
        } else if (rotE >= RotMax && distD >= SONAR_DIST_MIN) {
          estado = 3;
          Serial.println("IF G");
        } else if (distF >= SONAR_DIST_MIN) {
          estado = 3;
          Serial.println("IF H");
        } else {
          estado = 5;
          Serial.println("IF I");
        }
        break;
      case 2: //trás
        enviarEstado(2);
        //Atualiza as variáveis de rotação
        rotD = 0;
        rotE = 0;
        //Anda para trás
        tras(velP, delayP);
        estado = 1;
        break;
      case 3: //direita
        enviarEstado(3);
        //Atualiza as variáveis de rotação
        //rotD ++;
        //rotE = 0;
        //Roda para a direita
        direita(velP, delayP * 2);
        frente(velP, delayP * 2); //Liga os motores
        robotPara(delayS); // para o robot
        estado = 1;
        break;
      case 4: //esquerda
        enviarEstado(4);
        //Atualiza as variaveis de rotação
        //rotE ++;
        //rotD = 0;
        //Roda para a esquerda
        esquerda(velP, delayP * 2);
        frente(velP, delayP * 2); //Liga os motores
        robotPara(delayS); // para o robot
        estado = 1;
        break;
      case 5: //180
        roda180(velP, delayP * 4); //roda o robot 180º
        robotPara(delayS); // para o robot

        estado = 1;

        break;
      default:
        estado = 1;
        Serial.println("Default");
    }

    //Roda o servo
    servo_return = 1;
    angle_servo = SERVO_MIN_ANGLE;
    servoFlag = 0;

    do {
      servo.write(angle_servo); //Roda o servo
      chama = analogRead(CHAMA_PIN);

      if (chama >= chama_param) {
        apagarChama(angle_servo);
      }

      delay(SERVO_DELAY);

      servo_return = (angle_servo == SERVO_MAX_ANGLE) ? -1 : servo_return; //Inverte o sentido de rotação quando chegar-mos ao angulo máximo

      angle_servo += SERVO_INCREMENTO * servo_return; //Muda o angulo do servo para a próxima rotação

      servoFlag += (angle_servo == 90) ? 1 : 0; //Incrementa a flag apenas se o angulo for 90º

    } while (servoFlag < 2);
  }
}

double getDistance(int trig, int echo) {
  //Limpeza do Pino Trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  //Ativa o Pin Trig por 10 microsegundos
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //Lê os Pin Echo e retorna o tempo de viagem da onda sonoar em microsegundos
  double dist = pulseIn(echo, HIGH) * 0.034 / 2;
  return dist;
}

void enviarEstado(int estado) {
  //Apenas envia se o estado for diferente
  //if (ultimo_estado != estado) {
    Serial.println(estado);
    Bluetooth.println(estado);
    ultimo_estado = estado;
  //}
  Serial.println("\tF: " + (String)distF + "\tD: " + (String)distD + "\tE: " + (String)distE);
  Bluetooth.println("\tF: " + (String)distF + "\tD: " + (String)distD + "\tE: " + (String)distE);
}

void frente(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  delay(duracao);
  
}

void tras(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  delay(duracao);
}

void direita(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, LOW);
  analogWrite(MOTOR_A_PWM, motorSpeed / 2);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, motorSpeed);

  delay(duracao);
}

void esquerda(int motorSpeed, int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, motorSpeed);

  //Motor B
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_B_PWM, motorSpeed / 2);

  delay(duracao);
}

void robotPara(int duracao) {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, 0);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, 0);

  delay(duracao);
}

void para() {
  //Motor A
  digitalWrite(MOTOR_A_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, 0);

  //Motor B
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_B_PWM, 0);
}

void roda180(int motorSpeed, int duracao) {
  if (getDistance(SONAR_TRIG_FRENTE, SONAR_ECHO_FRENTE) < SONAR_DIST_MIN) {
    tras(velP, delayP / 2); //Não há condições para rodar, recua um pouco
  }

  if (getDistance(SONAR_TRIG_DIREITA, SONAR_ECHO_DIREITA) > SONAR_DIST_MIN) {
    direita(motorSpeed, duracao); //Temos condições para rodar à direita
  } else {
    esquerda(motorSpeed, duracao);
  }
}

void apagarChama(int angle) {
  int dirA, dirB;

  enviarEstado(6); //Enviar o estado
  //Avisa que detetou o a chama
  for (int i = 0; i < 3; i++) {
    digitalWrite(CHAMA_LED, HIGH);
    delay(500);
    digitalWrite(CHAMA_LED, LOW);
    delay(500);
  }

  servo.write(90); //Roda o servo

  //Define para onde se roda
  if (angle > 95) {
    while (analogRead(CHAMA_PIN) <= chama_param) { //Roda ate detetar a chama
      esquerda(velP, delayP / 2);
    }
  } else if (angle < 85) {
    while (analogRead(CHAMA_PIN) <= chama_param) { //Roda ate detetar a chama
      direita(velP, delayP / 2);
    }
  }

  if (angle > 95) {
    esquerda(velP / 2, delayS / 2);
  } else {
    direita(velP / 2, delayS / 2);
  }

  robotPara(0);
  enviarEstado(7); //Enviar o estado
  while (analogRead(CHAMA_PIN) >= chama_param) { //Enquanto há chama mantem o propeller a trabalhar
    analogWrite(VENTOINHA_INA, VENTOINHA_MAX);
    delay(CHAMA_DELAY);
  }

  analogWrite(VENTOINHA_INA, VENTOINHA_MIN); //desliga o propeller
}
