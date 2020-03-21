
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>
#define potpin A0
int deger;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
int angle;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int degree;
void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  Serial.println("please enter the amount of degree");
  while (Serial.available() > 0) {
     degree = Serial.parseInt();
     int blank = Serial.parseInt();
  }
  while(1){
    myStepper.step(-stepsPerRevolution);
    deger = analogRead(potpin);
    Serial.println("deger");
    Serial.print(deger);
    angle=deger*30;
    if(degree<angle){
      break;
    }
    delay(10);
    Serial.println("angle küçük referans");
  }
  Serial.println("complete");
  delay(200);
   while(1){
    myStepper.step(+stepsPerRevolution);
    deger = analogRead(potpin);
    angle=deger*30;
    if(angle<15){
      break;
    }
    delay(10);
    Serial.println("angle büyük referans");
  }
    

}
