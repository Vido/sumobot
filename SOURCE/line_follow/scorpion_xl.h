#include <Servo.h>

#define PPM_MAX 180 -18
#define PPM_IDLE 90
#define PPM_SLOW 140
#define PPM_MIN 0 + 18

#define LEFT_MOTOR_PIN 6
#define RIGHT_MOTOR_PIN 10
#define MOTOR_DELAY 100

// Scorpion XL PPM Signal
Servo left_motor;
Servo right_motor;

void frente() {
  left_motor.write(PPM_SLOW);
  right_motor.write(PPM_SLOW);
}

void direita() {
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_IDLE);
}

void esquerda() {
  left_motor.write(PPM_IDLE);
  right_motor.write(PPM_MAX);
}

void direita_suave() {
  left_motor.write(PPM_SLOW);
  right_motor.write(PPM_IDLE);
}

void esquerda_suave() {
  left_motor.write(PPM_IDLE);
  right_motor.write(PPM_SLOW);
}
