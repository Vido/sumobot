//#include <Servo.h>

#include "bumper.h"
#include "infrared.h"
#include "range_finder.h"
// #include "scorpion_xl.h"
#include "ln298.h"


void setup()
{
  int i;
  #ifdef IR_DEBUG
    Serial.begin(9600);
    Serial.println("FOOBAR");
  #endif
  
  // BUMPER
  pinMode(LEFT_BUMPER, INPUT);
  pinMode(RIGHT_BUMPER, INPUT);
  // FRONT IR
  pinMode(LEFT_FRONT_IR, INPUT);
  //pinMode(RIGHT_FRONT_IR, INPUT); //Burn'd
  
  // BACK IR
  pinMode(BACK_LEFT_IR, INPUT);
  pinMode(BACK_RIGHT_IR, INPUT);
  
  // RANGE FINDER
  pinMode(RF_LEFT_PIN, INPUT);
  
  // SCORPION XL
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

void loop(){
  
  if(toDigital(!LEFT_BUMPER) || toDigital(!RIGHT_BUMPER)){
    push_hard();
    return;
  }
  
  left_motor_forward(PWM_SLOW * 2);
  right_motor_forward(PWM_SLOW * 1.5);
}

/*
void loop()
{
  
  Serial.println("LOOP");
  
  // Sweep
  int rf_left_reading = analogRead(RF_LEFT_PIN);  
  // if (rf_left_reading >= 500) push();
  circle_right();

  // int rf_right_reading = analogRead(RF_RIGHT_PIN);
  //field_index = sweep();
  // scan_field[field_index] = analogRead(RFINDER_PIN);
  
  // Bumper
  if(digitalRead(LEFT_BUMPER) || digitalRead(RIGHT_BUMPER)){
    push_hard();
  }
  
  // Infrared
  if(toDigital(LEFT_FRONT_IR)){
    spin();
  }
  
  if(toDigital(BACK_RIGHT_IR) || toDigital(BACK_LEFT_IR)){
    push_hard();
  }

}
*/
