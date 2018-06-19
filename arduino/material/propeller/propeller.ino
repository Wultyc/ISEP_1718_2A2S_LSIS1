void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  analogWrite(6, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(6, HIGH);
  delay(2000);
  analogWrite(6, LOW);
  delay(2000);
}
