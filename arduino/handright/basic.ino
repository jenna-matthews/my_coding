int pen = A3;
int sensorValue;

void setup() {
  pinMode(pen, INPUT);
  digitalWrite(pen, HIGH);
  Serial.begin(9600);
  sensorValue = analogRead(pen);
  
}

void loop() {
  Serial.println(sensorValue);
}

