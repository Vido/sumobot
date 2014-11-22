#include <Servo.h>

#define LEFT_MOTOR_PIN 10
#define RIGHT_MOTOR_PIN 11

// Scorpion XL PPM Signal
Servo left_motor;
Servo right_motor;

void setup()
{
  // Serial.begin(9600);
  left_motor.attach(LEFT_MOTOR_PIN);
  right_motor.attach(RIGHT_MOTOR_PIN);
}

void loop()
{  
  int i = 0;
  //////////////////////
  for(i=90; i<180; i++){
    left_motor.write(i);
    delay(100);
  }
  for(i=180; i>0; i--){
    left_motor.write(i);
    delay(100);
  }
  
  //////////////////////
  for(i=90; i<180; i++){
    right_motor.write(i);
    delay(100);
  }
  for(i=180; i>0; i--){
    right_motor.write(i);
    delay(100);
  }
}
