#include <Time.h>
//code for final project
//declaring the variables to use in the program
int pen = A3;
int sensorValue; //variable to store the readings

//setup the program input and output states
void setup() {
  //initialize everything
  pinMode(pen, INPUT);
  
  //other set up necessaries
  digitalWrite(pen, HIGH); //initialize sensor
  Serial.begin(9600); //initializes the communication
  int starter = 0;
  int sensorValue = analogRead(pen);
  while(starter < 1) {
  //while(starter == 0) {
    if (sensorValue < 800) {
      starter += 1;
    }
    else {
      Serial.println("Waiting for user to begin"); //!!!!Current problem==it is just printing this line over and over again no matter what!
      
    }
  }
  if(starter >= 1){
    justKeepSwimming();
  }
}
void justKeepSwimming() {
//the just keep swimming code
  //time stuff
  time_t t = now();
  int minu = minute(t);
  int last = second(t);
  //the printing stuff
  int sensorValue = analogRead(pen); //moving this up here so that the loop only runs once they start
  Serial.print("Elapsed Time: ");
  Serial.print(minu);
  Serial.print(":");
  Serial.print(last);
  Serial.print(" Reading: ");
  Serial.println(sensorValue);  //add println instead of print to the last element that you want on that line, telling the output to jump to the next line after that.
  delay(100); //delay for 1/10 of a second
}

void loop() {
}
