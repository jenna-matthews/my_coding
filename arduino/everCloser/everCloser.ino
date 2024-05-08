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
  int starter = 0; //creating a variable so I can start the loop the first time sensorValue drops below 800, but not repeat everytime they drop below 800
  int sensorValue = analogRead(pen); //moving this up here so that the loop only runs once they start
  while(starter == 0) {
    if(sensorValue < 800) {
      starter += 1;
      Serial.println(sensorValue);
    }
    else { //now it is printing this line without ever recognizing the if statement.
      Serial.println("Waiting for user to begin.");
    }
  }
  if(starter > 1) {
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
