#include <Servo.h>

// #define LF_DEBUG

// #include "scorpion_xl.h"
#include "infrared.h"
#include "ln298.h"

void setup() {
  
  #ifdef LF_DEBUG
    Serial.begin(9600);
  #endif
  
  #ifdef IR_DEBUG
    Serial.begin(9600);
  #endif

  pinMode(FAR_RIGHT, INPUT);  
  pinMode(RIGHT, INPUT);
  pinMode(CENTER_RIGHT, INPUT);
  pinMode(CENTER_LEFT, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(FAR_LEFT, INPUT);
  
  // left_motor.attach(LEFT_MOTOR_PIN);
  // right_motor.attach(RIGHT_MOTOR_PIN);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

int state = 0; 
int last_state = 0; 

void loop() {

    boolean r0 = toDigital(FAR_LEFT);  
    boolean r1 = toDigital(LEFT);
    boolean r2 = toDigital(CENTER_LEFT);
    boolean r3 = toDigital(CENTER_RIGHT);
    boolean r4 = toDigital(RIGHT);
    boolean r5 = toDigital(FAR_RIGHT);

    #ifdef LF_DEBUG
      Serial.print("LEFT < ");
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
      Serial.print(r5);
      Serial.println(" > RIGHT");
      Serial.print("----------------------------------------------------------------------------------");
      Serial.print("----------------------------------------------------------------------------------");
      Serial.println(state);
    #endif

    last_state = state;

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
      state = last_state > 0 ? 4 : -4;
    }else{
      // fica loko
    }
    /*
    if(state != last_state){
      //if(-3 >= last_state || last_state <= 3){
        //motor_break();
      //}
      if(0 == last_state){
          left_motor_forward(PWM_IDLE);
          right_motor_forward(PWM_IDLE);
      }
    }
    */
    switch(state){
      case 4:
          //left_motor.write(PPM_MAX);
          left_motor_forward(PWM_MAX);
          //right_motor.write(PPM_MIN);
          right_motor_backward(PWM_MAX);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case 3:
          //left_motor.write(PPM_SLOW);
          left_motor_forward(PWM_SLOW);
          //right_motor.write(PPM_SLOW_BACK);
          right_motor_backward(PWM_SLOW * 1.2);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case 2:
          //left_motor.write(PPM_SLOW);
          left_motor_forward(PWM_SLOW);
          //right_motor.write(PPM_IDLE);
          right_motor_backward(PWM_IDLE);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case -1:
          //left_motor.write(PPM_MAX);
          left_motor_forward(PWM_MAX);
          //right_motor.write(PPM_SLOW);
          right_motor_forward(PWM_SLOW);
          digitalWrite(LED_BUILTIN, HIGH);
          break;
      case 0:
          //left_motor.write(PPM_MAX);
          left_motor_forward(PWM_MAX);
          //right_motor.write(PPM_MAX);
          right_motor_forward(PWM_MAX);
          digitalWrite(LED_BUILTIN, HIGH);
          break;
      case 1:
          //left_motor.write(PPM_SLOW);
          left_motor_forward(PWM_SLOW);
          //right_motor.write(PPM_MAX);
          right_motor_forward(PWM_MAX);
          digitalWrite(LED_BUILTIN, HIGH);
          break;
      case -2:
          //left_motor.write(PPM_IDLE);
          left_motor_backward(PWM_IDLE);
          //right_motor.write(PPM_SLOW);
          right_motor_forward(PWM_SLOW);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case -3:
          //left_motor.write(PPM_SLOW_BACK);
          left_motor_backward(PWM_SLOW * 1.2);
          //right_motor.write(PPM_SLOW);
          right_motor_forward(PWM_SLOW);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case -4:
          //left_motor.write(PPM_MIN);
          left_motor_backward(PWM_MAX);
          //right_motor.write(PPM_MAX);
          right_motor_forward(PWM_MAX);
          digitalWrite(LED_BUILTIN, LOW);
          break;
    }
}
