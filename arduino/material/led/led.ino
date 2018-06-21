
  int led_pin = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_pin, HIGH);
  Serial.println("liga");
  delay(2000);
  digitalWrite(led_pin, LOW);
  Serial.println("desliga");
  delay(2000);
}
