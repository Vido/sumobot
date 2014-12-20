#include <Servo.h>

#include "scorpion_xl.h"
#include "infrared.h"

void setup() {
  Serial.begin(9600);
  
  pinMode(RIGHT, INPUT);
  pinMode(CENTER_RIGHT, INPUT);
  pinMode(CENTER_LEFT, INPUT);
  pinMode(LEFT, INPUT);
  
  left_motor.attach(LEFT_MOTOR_PIN);
  right_motor.attach(RIGHT_MOTOR_PIN);
}

void loop() {
    int seg1 = toDigital(RIGHT);
    int seg2 = toDigital(CENTER_RIGHT) && toDigital(CENTER_LEFT);
    int seg3 = toDigital(LEFT);

    if(seg1 && seg3){
      frente();
    }else{
      if(seg1 && seg2 ){
        esquerda_suave();
      }else
      if(seg3 && seg2 ){
        direita_suave();
      }else
      if(seg1 && (!seg2)){
        esquerda();
      }else
      if(seg3 && (!seg2)){
        direita();
      }else
      if(seg2 && (!seg1) && (!seg3)){
        frente();
      }else{
        frente();
      }
    }
  delay(50);
}
