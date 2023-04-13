/*
  ShiftRegister74HC595 - Library for simplified control of 74HC595 shift registers.
  Created by Timo Denk (www.timodenk.com), Nov 2014.
  Additional information is available at http://shiftregister.simsso.de/
  Released into the public domain.
*/

#include "ShiftRegister74HC595.h"

// create a global shift register object
// parameters: (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595<1> sr (12, 13, 11); 
 
void setup() { 
}

void loop() {

  // setting all pins at the same time to either HIGH or LOW
  //sr.setAllHigh(); // set all pins HIGH
  //delay(500);
  
  //sr.setAllLow(); // set all pins LOW
  //delay(500); 
  

  // setting single pins
  for (int i = 0; i <= 8; i++) {
    
    sr.set(i, HIGH); // set single pin HIGH
    sr.set(i-1, LOW);
    delay(50); 
  }

  for (int i = 9; i>=0; i--) {
    sr.set(i, HIGH);
    sr.set(i+1, LOW);
    delay(50);
  }

byte data = 5;
for (int i=0; i<=8; i++){
for (int mask = 00000001; mask > 0; mask <<=1) {
  if (data & mask) {
    sr.set(i, HIGH);
  } else {
    sr.set(i, LOW);
  }
  delay(50);
}
sr.set(i, HIGH);
}

for (int i=9; i>=0; i--){
for (int mask = 00000001; mask > 0; mask <<=1) {
  if (data & mask) {
    sr.set(i, LOW);
  } else {
    sr.set(i, HIGH);
  }
  delay(50);
}
sr.set(i, LOW);
}


/*
  // set all pins at once
  uint8_t pinValues[] = { B10000000 }; //top led
  sr.setAll(pinValues); 
  delay(1000);


  // read pin (zero based, i.e. 6th pin)
  uint8_t stateOfPin5 = sr.get(5);


  // set pins without immediate update
  sr.setNoUpdate(0, HIGH);
  sr.setNoUpdate(1, LOW);
  // at this point of time, pin 0 and 1 did not change yet
  sr.updateRegisters(); // update the pins to the set values
  */
}
