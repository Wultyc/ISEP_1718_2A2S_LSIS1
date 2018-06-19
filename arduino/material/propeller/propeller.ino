void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(6, HIGH);
  Serial.println("Liga");
  delay(2000);
  digitalWrite(6, LOW);
  Serial.println("Desliga");
  delay(2000);
}
