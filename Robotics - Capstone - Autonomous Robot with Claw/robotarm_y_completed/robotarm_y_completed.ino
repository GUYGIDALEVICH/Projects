#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos ;    

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //myservo.writeMicroseconds(1500);  // set servo to mid-point

}

void loop() {
  // DOWN (90) - going up
  
  for (pos = 0; pos <= 40; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       //speed
  }
//exit(1);
  //UP (60) - holding
  
   for (pos = 40; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                //speed       
  }
     delay(5000);  //5 sec stop at the top and hold (60 degrees)


  
}
