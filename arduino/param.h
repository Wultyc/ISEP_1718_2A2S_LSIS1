//Motores (A: Esquerda | B: Direita)
#define MOTOR_A_DIR 12
#define MOTOR_B_DIR 13
#define MOTOR_A_PWM 3
#define MOTOR_B_PWM 11
//#define MOTOR_A_BRK 9
//#define MOTOR_B_BRK 8
#define MOTOR_A_CS A0
#define MOTOR_B_CS A1
#define MOTOR_MOVE_STOP 0  //Constantes de apoio
#define MOTOR_MOVE_FORWARD 1
#define MOTOR_MOVE_BACKWARD 2
#define MOTOR_MOVE_RIGHT 3
#define MOTOR_MOVE_LEFT 4
#define MOTOR_VEL 128

//Sonares
#define SONAR_TRIG_ESQUERDA 5
#define SONAR_TRIG_DIREITA 8
#define SONAR_TRIG_FRENTE 9
#define SONAR_ECHO_FRENTE A2
#define SONAR_ECHO_DIREITA A3
#define SONAR_ECHO_ESQUERDA A4
#define SONAR_DIST_MIN 15 //distancia minima do robot à parede em cm
#define SONAR_ROOM 60     //distancia que o robot considera um quarto em cm
#define SONAR_ROOM_FRENTE 20     //distancia máxima para que o robot entre no quarto em vez de seguir em frente

//Propeller
#define VENTOINHA_INA 6
#define VENTOINHA_MAX 0
#define VENTOINHA_MIN 255

//Servomotor
#define SERVO_PIN 10
#define SERVO_DELAY 10
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_ANGLE 0
#define SERVO_INCREMENTO 1

//Sensor de Chama
#define CHAMA_PIN A5
#define CHAMA_LED 7
#define CHAMA_PARAM 200

//Bluetooth
#define BT_RX 0
#define BT_TX 1

//Botões de Ativação
#define BOTAO_START 4
#define BOTAO_STOP 2

//Tempo de reação
#define REACT_TIME 1000
