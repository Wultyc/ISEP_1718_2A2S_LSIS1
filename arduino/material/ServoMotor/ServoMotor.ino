#include <Servo.h>

Servo servo;
int angle = 90;
int v = 25;

void setup() {
  servo.attach(10);
  servo.write(angle);
  Serial.begin(9600);
}


void loop() { 
 // scan from 0 to 180 degrees
  /*for(angle = 0; angle <= 180; angle++){                                  
    servo.write(angle);  
    Serial.print(angle); 
    Serial.print("\n");            
    delay(v);                   
  } 
  delay(1000);   
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle >= 0; angle--){                                
    servo.write(angle);   
    Serial.print(angle);   
    Serial.print("\n");         
    delay(v);       
  } 
  delay(1000);
  */servo.write(90);
} 
