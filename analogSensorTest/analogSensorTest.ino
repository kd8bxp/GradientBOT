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
 // while (sensor <= 39 || sensor >= 44) {
 // Motors.Motordrive(Speed_Dir, -65, 65 ); //Lspeed_F, Rspeed_F);
 // while(1);
 sensor = analogRead(A2);
 Serial.println(sensor);
 
}
