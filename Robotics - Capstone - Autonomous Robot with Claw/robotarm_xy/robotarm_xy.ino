#include <Servo.h>

Servo xservo;
Servo yservo;

int xpos;
int ypos;

void setup() {

  xservo.attach(10);
  yservo.attach(9);
   
}

void loop() {

    for (ypos = 0; ypos <= 2; ypos += 1) { 
    yservo.write(ypos);              
    delay(30);                       //speed
    }

    for (xpos = 180; xpos >= 20; xpos -= 1) { 
    xservo.write(xpos);              
    delay(30);                //speed       
  }

  //IN OPEN POSITION (40) - closing
  delay(2000);

  //40 to 110 (not closed all the way)
  for (xpos = 20; xpos <= 125; xpos += 1) { 
    xservo.write(xpos);              
    delay(30);                       //speed
  }

   delay(5000);  //stop at almost closed (110 degrees)

       for (ypos = 2; ypos <= 40; ypos += 1) { 
    yservo.write(ypos);              
    delay(15);                       //speed
  }

  delay(10000);

exit(0);
}


/*void xgrab(){
  //IN CLOSED POSITION (180) - openning
    for (xpos = 180; xpos >= 40; xpos -= 1) { 
    xservo.write(xpos);              
    delay(30);                //speed       
  }

  //IN OPEN POSITION (40) - closing
  delay(2000);

  //40 to 110 (not closed all the way)
  for (xpos = 40; xpos <= 110; xpos += 1) { 
    xservo.write(xpos);              
    delay(30);                       //speed
  }

   delay(5000);  //stop at almost closed (110 degrees)

       for (ypos = 0; ypos <= 40; ypos += 1) { 
    yservo.write(ypos);              
    delay(30);                       //speed
  }

}

void ygrab(){
    // DOWN (90) - going up
    for (ypos = 0; ypos <= 40; ypos += 1) { 
    yservo.write(ypos);              
    delay(30);                       //speed
  }

  //UP (60) - holding
  
   for (ypos = 60; ypos >= 0; ypos -= 1) { 
    yservo.write(ypos);              
    delay(30);                //speed       
  }

     delay(5000);  //5 sec stop at the top and hold (60 degrees)
     

}
*/
