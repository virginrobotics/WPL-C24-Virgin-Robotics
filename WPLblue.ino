// Feel free to make it your own homies :)

#include <AFMotor.h>

AF_DCMotor motor(1);
#include<Servo.h>
int led = A0;

char Incoming_value = 0;
Servo myservo;
void setup() {
  Serial.begin(9600);
pinMode(led,OUTPUT);
myservo.attach(9);
myservo.write(93);

}

void loop() {

  


if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");       
    if(Incoming_value == '1') {           
         myservo.write(93);// Change the servo angles to suit your truck/car whatever.
         delay(100);  
    }
    else if(Incoming_value == '2') {       
      myservo.write(119); // Steering Angle
      delay(100);
    }
    else if (Incoming_value == '3') {
      myservo.write(72); //Steering Angle
      delay(100);
    }
    else if (Incoming_value == '4') {
      motor.run(FORWARD); // Throttle Up
      motor.setSpeed(150);
      delay(50);
    }
    else if (Incoming_value == '5') {
      motor.run(BACKWARD); // Throttle Back
      motor.setSpeed(150);
      delay(50);
    }
    else if (Incoming_value == '6') {
      motor.run(RELEASE); // Stop duh. 
      
      delay(50);
    }
    else if (Incoming_value == '7') {
      digitalWrite(led,LOW); // Headlights 
      delay(50);
    }
    else if (Incoming_value == '8') {
      digitalWrite(led,HIGH);
      delay(50);
    }
    
    
    
  }                    
}
