#include <Servo.h>

#include "bumper.h"
#include "infrared.h"
#include "range_finder.h"
#include "scorpion_xl.h"

void setup()
{
  int i;
  Serial.begin(9600);
  // BUMPER
  pinMode(LEFT_BUMPER, INPUT);
  pinMode(RIGHT_BUMPER, INPUT);
  // FRONT IR
  pinMode(LEFT_FRONT_IR, INPUT);
  pinMode(RIGHT_FRONT_IR, INPUT);
  
  // BACK IR
  pinMode(BACK_LEFT_IR, INPUT);
  pinMode(BACK_RIGHT_IR, INPUT);
  
  // RANGE FINDER
  pinMode(RF_RIGHT_PIN, INPUT);
  pinMode(RF_RIGHT_PIN, INPUT);
  
  // SCORPION XL
  left_motor.attach(LEFT_MOTOR_PIN);
  right_motor.attach(RIGHT_MOTOR_PIN);
}

int b_left_go = 0;
int b_right_go = 0;
int ir_left_go = 0;
int ir_right_go = 0;
int ir_back_go = 0;

int b_left_stop = 0;
int b_right_stop = 0;
int ir_left_stop = 0;
int ir_right_stop = 0;
int ir_back_stop = 0;

void loop()
{
  // Sweep
  int rf_left_reading = analogRead(RF_LEFT_PIN);
  int rf_right_reading = analogRead(RF_RIGHT_PIN);
  //field_index = sweep();
  // scan_field[field_index] = analogRead(RFINDER_PIN);
  
  // Bumper
  if(digitalRead(LEFT_BUMPER)) b_left_go++;
  else b_left_stop++;
 
  if(digitalRead(RIGHT_BUMPER)) b_right_go++;
  else b_right_stop++;
 
  // Infrared
  if(toDigital(LEFT_FRONT_IR)) ir_left_go++;
  else ir_left_stop++;

  if(toDigital(RIGHT_FRONT_IR)) ir_right_go++;
  else ir_right_stop++;
  
  if(toDigital(BACK_RIGHT_IR)) ir_back_go++;
  else ir_back_stop++;
  
  if(toDigital(BACK_LEFT_IR)) ir_back_go++;
  else ir_back_stop++;
  
  if(b_left_stop > 10 || b_right_stop > 10){
    b_left_go = 0; b_left_stop = 0;
    b_right_go = 0; b_right_stop = 0;
  }

  if (ir_back_go > 2){
    ir_back_go = 0;
    push_hard();
    goto next;
  }
  
  if(b_left_go > 3 || b_right_go > 3){
    push_hard(); // 
  }else{
    if(rf_left_reading <= 150 && rf_right_reading <= 150) circle_left(); // circle_right();
    if (rf_left_reading > 150 && rf_right_reading > 150) push();
    if(rf_left_reading > 150 && rf_right_reading <= 150) circle_right();
    if (rf_left_reading <= 150 && rf_right_reading > 150) circle_left();
}

  //return;
  //if(ir_left_stop > 10){ ir_left_go=0; ir_left_stop=0; }
  //if(ir_right_stop > 10){ ir_right_go=0; ir_right_stop=0; }
  //if(ir_back_stop > 10){ ir_back_go=0; ir_back_stop=0; }
  


  if (ir_left_go > 2 || ir_right_go > 2){
    if(b_left_go > 3 || b_right_go > 3) push_hard(); 
    else{    
        ir_left_go = 0;
        ir_right_go = 0;
        spin(); 
      }
  }
  next: ;
}
