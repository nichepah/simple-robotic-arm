/*
 * Teleoperation Demo
 * arduino-based rc servo-controlled 3 dof manipulator
 * written by aneesh on 160317
 * controls 3 rc servos connected with pots
 * 
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 


Servo servo1, servo2, servo3;
int pot1=9 , pot2= 10, pot3=11; //pot pins for each servo
int val; //for analog read from pots


void demo1(){  
  for(int i=0; i<180; i++) {
    servo1.write(i);
    delay(5);
  }
  for(int i=180; i>90; i--) {
    servo1.write(i);
    delay(5);
  }  
}

void demo2(){  
  for(int i=0; i<180; i++) {
    servo2.write(i);
    delay(5);
  }
  for(int i=180; i>0; i--) {
    servo2.write(i);
    delay(5);
  }  
}
  
void demo3(){  
  for(int i=0; i<180; i++) {
    servo3.write(i);
    delay(5);
  }
  for(int i=180; i>0; i--) {
    servo3.write(i);
    delay(5);
  }  
}
  void homeBase() {
    for(int i=90; i>0; i--) {
    servo1.write(i);
    delay(5);
  }
  }


void setup(){
  pinMode(13, OUTPUT); //for blinking

  servo1.attach(9);   // attach servo1
  demo1();
  delay(50);
  
  servo2.attach(10);  // attach servo2
  demo2();
  delay(50);
  
  servo3.attach(11);  // attach servo3
  demo3();
  Serial.begin(9600); //for serial monitor
  
  homeBase();
  
}

void loop(){
  
//set angular pos from pot1 for servo1 control
  val = analogRead(pot1);  // reads the value of the potentiometer (value between 0 and 1023) 
  
  //Serial.println("pot1 reading:"); //debug
  //Serial.println(val) ; //debug 
  val = map(val, 0, 1023, 0,179 );     // scale it to use it with the servo (value between 0 and 180) 
  servo1.write(val);                  // sets the servo position according to the scaled value 
  delay(5);                           // waits for the servo to get there 

//set angular pos from pot1 for servo2 control  
  val = analogRead(pot2);            // reads the value of the potentiometer (value between 0 and 1023) 
  
  Serial.println("pot2 reading:"); //debug
  Serial.println(val) ; //debug 
  
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  servo2.write(val);                  // sets the servo position according to the scaled value 
  delay(5);                           // waits for the servo to get there 

//set angular pos from pot1 for servo3 control  
  val = analogRead(pot3);  // reads the value of the potentiometer (value between 0 and 1023) 
  
  Serial.println("pot3 reading:"); //debug
  Serial.println(val) ; //debug 
  
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  servo3.write(val);                  // sets the servo position according to the scaled value 
  delay(5);                           // waits for the servo to get there 

}
