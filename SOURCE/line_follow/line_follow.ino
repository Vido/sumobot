#include <Servo.h>

#define LF_DEBUG

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
  
    int seg1 = analogRead(RIGHT);
    int seg2 = (analogRead(CENTER_RIGHT) + analogRead(CENTER_LEFT))/2;
    int seg3 = analogRead(LEFT);
  
    #ifdef LF_DEBUG
      Serial.print(seg1);
      Serial.print("\t");
      Serial.print(seg2);
      Serial.print("\t");
      Serial.println(seg3);
    #endif

    if(seg1 > 700 && seg3 > 700){
      frente();
    }else{
      if(seg1 > 700 && seg2 > 700){
        esquerda_suave();
      }else
      if(seg3 > 700 && seg2 > 700){
        direita_suave();
      }else
      if(seg1 > 700 && seg2 < 700){
        esquerda();
      }else
      if(seg3 > 700 && seg2 < 700){
        direita();
      }else
      if(seg2 > 700 && seg1 < 700 && seg3 < 700){
        frente();
      }else{
        frente();
      }
    }
  // delay(1);
}
