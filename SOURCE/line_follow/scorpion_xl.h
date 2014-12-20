#include <Servo.h>

#define PPM_MAX 125
#define PPM_IDLE 90
#define PPM_SLOW 115
#define PPM_REV 55
#define PPM_MIN 40

#define LEFT_MOTOR_PIN 6
#define RIGHT_MOTOR_PIN 10
#define MOTOR_DELAY 100

// Scorpion XL PPM Signal
Servo left_motor;
Servo right_motor;

void frente() {
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_MAX);
}

void direita() {
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_REV);
}

void esquerda() {
  left_motor.write(PPM_REV);
  right_motor.write(PPM_MAX);
}

void direita_suave() {
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_IDLE);
}

void esquerda_suave() {
  left_motor.write(PPM_IDLE);
  right_motor.write(PPM_MAX);
}
