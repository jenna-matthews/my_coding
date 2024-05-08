//initialization
//making the variable names numbers so I can use a for loop later
int on = 200;  //When the sensorValue is below this number, it will start the program
int 1 = A1;
int 2 = A2;
int 12 = A3;
int 4 = A4;
int 5 = A5;
int 6 = 2;
int 14 = 3;
int ground = 5;
int ground2 = 4;
int 15 = 6;
int 9 = 7;
int 10 = 8;
int 11 = 9;
int 3 = 10;
int 13 = 11;
int 7 = 12; 
int 8 = 13;
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
  sensorValue = int(sensorValue);  //to change the reading to an integer that can be compared.
  Serial.println(sensorValue);
  delay(100);
  if(sensorValue < on){
    twinkle();   //twinkling the four lights
    delay(2000); //wait for two seconds before turning on all the lights
    turnon();
    delay(30000); //thirty second delay
    turnALLOFF();
    }
}

    
void turnon() {
  for(i = 1, i < 12, i++) { //using a for loop to turn on all but the blinkers
      digitalWrite(i, HIGH);
      }
}

void twinkle() {
  //turning the four on 1/2 second apart
  int twinkleCount;
  for(twinkleCount = 0, twinkleCount > 4, twinkleCount++) { //will run this twinkle loop five times.
    for(i = 12, i < 16, i++) {
        digitalWrite(i, HIGH);
        delay(500);
        }
    delay(3000);
    for(i = 12, i < 16, i++){
        digitalWrite(i, LOW);
        delay(500);
        }
   delay(1000);     
  }
}

void turnALLOFF() { //to turn everything off at the end.
  for(i = 1, i < 16, i++) {
    digitalWrite(i, LOW);
  }
}
  

