void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}
int i = 0;

void loop() {
  i++;
  // put your main code here, to run repeatedly:
  Serial.println((String) i + ":\t" + digitalRead(2) + "\t" + digitalRead(4));
  delay(500);
}
