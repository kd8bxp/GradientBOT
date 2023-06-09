/* -----------------------------------------------------------------------------
  Author             : Allen
  Check              : Amy
  Version            : V1.0
  Date               : 17/06/2016
  Description        : Motor Test
  Company website    : http://www.sunfounder.com
   ---------------------------------------------------------------------------*/

/* Include -------------------------------------------------------------------*/
#include "src/Rollbot/Rollbot.h"

/* Define -------------------------------------------------------------------*/
RollbotMotors Motors;
int Speed_Dir = 0;
int Lspeed_F = 100, Rspeed_F = 100;
int Lspeed_B = -100, Rspeed_B = -100;
int Lspeed_L = -50, Rspeed_L = 100;
int Lspeed_R = 100, Rspeed_R = -50;

int sensor=0;
/*
  - setup function
 ---------------------------------------------------------------------------*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Robot starts initialization");
  pinMode(A2, INPUT);
}
/*
  - loop function
   ---------------------------------------------------------------------------*/
void loop() {
  // put your main code here, to run repeatedly:
  while (sensor <= 39 || sensor >= 44) {
  Motors.Motordrive(Speed_Dir, -65, 65 ); //Lspeed_F, Rspeed_F);
 // while(1);
 sensor = analogRead(A2);
 Serial.println(sensor);
  }
  Motors.Motordrive(Speed_Dir, 0, 0 );
  //sensor = 0;
}
