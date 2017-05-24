// #define LF_DEBUG
// #define ST_DEBUG

#include <PID_v1.h>
// #include <Servo.h>
// #include "scorpion_xl.h"

int state = 0; 
int last_state = 0; 
boolean r0, r1, r2, r3, r4, r5;
byte bitmap;

#include "state_machine.h"
#include "infrared.h"
#include "ln298.h"
//#include "pid.h"

void setup() {
  
  #if defined(IR_DEBUG) || defined(ST_DEBUG) ||  defined(LF_DEBUG)
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

  /*
  // Sample
  leftPID.SetSampleTime(10);
  rightPID.SetSampleTime(10);
  
  // Min-Max
  leftPID.SetOutputLimits(-100.0, 100.0);
  rightPID.SetOutputLimits(-100.0, 100.0);
  
  //turn the PID on
  leftPID.SetMode(AUTOMATIC);
  rightPID.SetMode(AUTOMATIC);  
  */
}

void loop() {

    r0 = toDigital(FAR_LEFT);  
    r1 = toDigital(LEFT);
    r2 = toDigital(CENTER_LEFT);
    r3 = toDigital(CENTER_RIGHT);
    r4 = toDigital(RIGHT);
    r5 = toDigital(FAR_RIGHT);
    bitmap = r0 +
            (r1 * 2) +
            (r2 * 4) +
            (r3 * 8) +
            (r4 * 16) +
            (r5 * 32);
    
    /*        
    LInput = pid_tranlationL();
    RInput = pid_tranlationR();
    
    leftPID.Compute();
    rightPID.Compute();
    left_pid_controller(LOutput);
    right_pid_controller(ROutput);
    */

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
      Serial.println("---------------------------------------------------------------------------------");
      //Serial.println(state);
      //Serial.println(bitmap);
      
      /*
      Serial.print("PID LInput                                                                              "); Serial.println(LInput);
      Serial.print("PID RInput                                                                              "); Serial.println(RInput);
      Serial.print("PID LOutput                                                                             "); Serial.println(LOutput);
      Serial.print("PID ROutput                                                                             "); Serial.println(ROutput);
      */   
    #endif

    last_state = state;
    // fast_sm();
    falcon_sm();
    
    #ifdef ST_DEBUG
      Serial.println("B----------------");
      Serial.println(bitmap);
      Serial.println("S----------------");
      Serial.println(state);
    #endif
    
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
          right_motor_backward(PWM_IDLE);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case 2:
          //left_motor.write(PPM_SLOW);
          left_motor_forward(PWM_SLOW * 1.2);
          //right_motor.write(PPM_IDLE);
          right_motor_forward(PWM_IDLE);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case -1:
          //left_motor.write(PPM_MAX);
          left_motor_forward(PWM_MAX);
          //right_motor.write(PPM_SLOW);
          right_motor_forward(PWM_SLOW * 1.2);
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
          left_motor_forward(PWM_SLOW * 1.2);
          //right_motor.write(PPM_MAX);
          right_motor_forward(PWM_MAX);
          digitalWrite(LED_BUILTIN, HIGH);
          break;
      case -2:
          //left_motor.write(PPM_IDLE);
          left_motor_forward(PWM_IDLE);
          //right_motor.write(PPM_SLOW);
          right_motor_forward(PWM_SLOW * 1.2);
          digitalWrite(LED_BUILTIN, LOW);
          break;
      case -3:
          //left_motor.write(PPM_SLOW_BACK);
          left_motor_backward(PWM_IDLE);
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
