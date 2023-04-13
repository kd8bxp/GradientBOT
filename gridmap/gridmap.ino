#include "src/Rollbot/Rollbot.h"

#define LED1 3 //left led
#define LED2 2 //right led

RollbotMotors Motors;
RollbotLED  LED;

int Speed_Dir = 0;
int sensor=0;


void setup() {
  
  Serial.begin(115200);
  Serial.println("Robot starts initialization");
  pinMode(A2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  LED.DataOut(0);
}

void loop() {
 
 sensor = analogRead(A2);
 if (sensor <= 39 || sensor >= 275) { Motors.Motordrive(Speed_Dir, 0, 0); digitalWrite(LED1, LOW); digitalWrite(LED2, LOW); while(1); } //stop
 if (sensor >= 159 || sensor <= 161) { Motors.Motordrive(Speed_Dir, -65, 65); digitalWrite(LED1, HIGH); digitalWrite(LED2, HIGH); } //move forward on target 158, 164
 if (sensor > 162 ) { Motors.Motordrive(Speed_Dir, 0, 65); digitalWrite(LED1, HIGH); digitalWrite(LED2, LOW); } //correct to the left
 if (sensor < 158 ) { Motors.Motordrive(Speed_Dir, -65, 0); digitalWrite(LED1, LOW); digitalWrite(LED2, HIGH); } //correct to the right
 
}
