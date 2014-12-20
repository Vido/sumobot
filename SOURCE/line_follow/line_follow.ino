#include <Servo.h>

#define LF_DEBUG

#include "scorpion_xl.h"
#include "infrared.h"

void setup() {
  Serial.begin(9600);
  
  pinMode(FAR_RIGHT, INPUT);  
  pinMode(RIGHT, INPUT);
  pinMode(CENTER_RIGHT, INPUT);
  pinMode(CENTER_LEFT, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(FAR_LEFT, INPUT);
  
  left_motor.attach(LEFT_MOTOR_PIN);
  right_motor.attach(RIGHT_MOTOR_PIN);
}

int state = 0; 

void loop() {

    boolean r0 = toDigital(FAR_LEFT);  
    boolean r1 = toDigital(LEFT);
    boolean r2 = toDigital(CENTER_LEFT);
    boolean r3 = toDigital(CENTER_RIGHT);
    boolean r4 = toDigital(RIGHT);
    boolean r5 = toDigital(FAR_RIGHT);

    #ifdef LF_DEBUG
      Serial.print(r0);
      Serial.print("\t");
      Serial.print(r1);
      Serial.print("\t");
      Serial.print(r2);
      Serial.print("\t");
      Serial.print(r3);
      Serial.print("\t");
      Serial.print(r4);
      Serial.print("\t");
      Serial.println(r5);
      Serial.println(state);
    #endif

    if(!r0 && r1 && r2 && r3 && r4 && r5){
      state = -3;
    }
    else if(!r0 && !r1 && r2 && r3 && r4 && r5){
      state = -2;
    }
    else if(r0 && !r1 && !r2 && r3 && r4 && r5){
      state = -1;
    }
    else if(r0 && r1 && !r2 && !r3 && r4 && r5){
      state = 0;
    }
    else if(r0 && r1 && r2 && !r3 && !r4 && r5){
      state = 1;
    }
    else if(r0 && r1 && r2 && r3 && !r4 && !r5){
      state = 2;
    }
    else if(r0 && r1 && r2 && r3 && r4 && !r5){
      state = 3;
    }
    else if(r0 && r1 && r2 && r3 && r4 && r5){
      // Tudo 1
      state = state > 0 ? 4 : -4;
    }else{
      // fica loko
    }
    
    switch(state){
      case -4:
          left_motor.write(PPM_MAX);
          right_motor.write(PPM_MIN);
          break;
      case -3:
          left_motor.write(PPM_SLOW);
          right_motor.write(PPM_SLOW_BACK);
          break;
      case -2:
          left_motor.write(PPM_SLOW);
          right_motor.write(PPM_IDLE);
          break;
      case -1:
          left_motor.write(PPM_MAX);
          right_motor.write(PPM_SLOW);
          break;
      case 0:
          left_motor.write(PPM_MAX);
          right_motor.write(PPM_MAX);
          break;
      case 1:
          left_motor.write(PPM_SLOW);
          right_motor.write(PPM_MAX);
          break;
      case 2:
          left_motor.write(PPM_SLOW_BACK);
          right_motor.write(PPM_SLOW);
          break;
      case 3:
          left_motor.write(PPM_SLOW_BACK);
          right_motor.write(PPM_SLOW);
          break;
      case 4:
          left_motor.write(PPM_MIN);
          right_motor.write(PPM_MAX);
          break;
    }
}
