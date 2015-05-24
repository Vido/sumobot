#include <Servo.h>

#define PPM_MAX 180 -18
#define PPM_IDLE 90
#define PPM_SLOW 130
#define PPM_MIN 0 + 18

#define LEFT_MOTOR_PIN 6
#define RIGHT_MOTOR_PIN 10
#define MOTOR_DELAY 100

// Scorpion XL PPM Signal
Servo left_motor;
Servo right_motor;

void push(){
  left_motor.write(PPM_SLOW);
  right_motor.write(PPM_SLOW);
}

void push_hard(){
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_MAX);
}

void circle_left(){
  // Reverse  
  left_motor.write(140);
  right_motor.write(100);  
}

void circle_right(){
  // Reverse  
  left_motor.write(100);
  right_motor.write(140);  
}

void spin(){
  // Reverse  
  left_motor.write(PPM_MIN);
  right_motor.write(PPM_MIN);
  delay(500);
  
  // Reverse
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_MIN);
  delay(300);  
}
