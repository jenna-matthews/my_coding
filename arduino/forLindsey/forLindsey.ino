//initialization
int 1 = A1;
int 2 = A2;
int 3 = A3;
int 4 = A4;
int 5 = A5;
int 6 = 2;
int 7 = 3;
int ground = 5;
int ground2 = 4;
int 8 = 6;
int 9 = 7;
int 10 = 8;
int 11 = 9;
int 12 = 10;
int 13 = 11;
int 14 = 12; 
int 15 = 13;
int aluminumFoil = A0; //positive heart patch on the dino's right
int sensorValue; //to store the readings from the sensor

//setup routine
void setup() {
  pinMode(ground, OUTPUT);
  digitalWrite(ground, LOW);
  pinMode(ground2, OUTPUT);
  digitalWrite(ground2, LOW);
  //initialize digital pin as output
  for(i = 1, i < 16, i++) { //using a for loop to set all the pins as output
    pinMode(i, OUTPUT); 
    } 
  pinMode(aluminumFoil, INPUT); //sets aluminum foil pin to INPUT
  digitalWrite(aluminumFoil, HIGH); //initializes the sensor
  Serial.begin(9600); //initializes the communication
  } //end of setup
  
void loop() {
  sensorValue = analogRead(aluminumFoil);
  //sensorValue = int(sensorValue);  //to change the reading to an integer that can be compared.
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue < 1000){
    turnon();
    delay(1000);               // wait for a second      
    turnoff();
    delay(1000);               // wait for a second
    twinkle();   //twinkling the four lights
    //turning everything on
    turnon();
    
    
void turnon() {
  for(i = 1, i < 16, i++) { //using a for loop to turn all on
      digitalWrite(i, HIGH);
      }
}

void turnoff() {
  for(i = 1, i < 12, i++) { //using a for loop to turn all off
       digitalWrite(i, LOW);
      }
}

void twinkle() {
  //turning the four on 1/2 second apart
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(8, HIGH);
    delay(500);
}

