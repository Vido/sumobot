#include <Servo.h>

#define PPM_MAX 180 -18
#define PPM_IDLE 90
#define PPM_MIN 0 + 18

#define LEFT_MOTOR_PIN 10
#define RIGHT_MOTOR_PIN 11
#define MOTOR_DELAY 100

// Scorpion XL PPM Signal
Servo left_motor;
Servo right_motor;
