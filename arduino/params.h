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
#define SONAR_TRIG 5
#define SONAR_ECHO_FRENTE A2
#define SONAR_ECHO_DIREITA A3
#define SONAR_ECHO_ESQUERDA A4
#define SONAR_DIST 5 //distancia minima do robot à parede em cm
#define SONAR_ROOM 10 //distancia que o robot considera um quarto em cm

//Propeller
#define VENTOINHA_INA 6

//Servomotor
#define SERVO_PIN 10
#define SERVO_DELAY 25
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_ANGLE 0

//Sensor de Chama
#define CHAMA_PIN A5
#define CHAMA_LED 7
#define CHAMA_PARAM 200

//Bluetooth
#define BT_RX 8
#define BT_TX 9

//Botões de Ativação
#define BOTAO_START 4
#define BOTAO_INTRP 2
