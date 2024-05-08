int pen = A2;
int sensorValue;

void setup() {
  pinMode(pen, INPUT);
  digitalWrite(pen, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial. println(sensorValue);
  sensorValue = analogRead(pen);
}
