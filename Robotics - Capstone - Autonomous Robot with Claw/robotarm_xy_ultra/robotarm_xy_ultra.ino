#include <Servo.h>

Servo xservo;
Servo yservo;

int xpos;
int ypos;

const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;

void setup() {

  xservo.attach(10);
  yservo.attach(9);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600); // Starts the serial communication

  //setup the y axis
    for (ypos = 0; ypos <= 2; ypos += 1) { 
    yservo.write(ypos);              
    delay(30);                       //speed
    }

//setup the x axis
  for (xpos = 180; xpos >= 178; xpos -= 1) { 
    xservo.write(xpos);              
    delay(30);                //speed       
  }

   
}

void loop() {


//setup and start ultrasonic:
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

delay(100);

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

if (distance < 10) {
Serial.println("youre close");


    for (xpos = 178; xpos >= 20; xpos -= 1) { 
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

   delay(3000);  //stop at almost closed (110 degrees)

       for (ypos = 2; ypos <= 40; ypos += 1) { 
    yservo.write(ypos);              
    delay(20);                       //speed
  }

  delay(10000);
  exit(0);
}

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
