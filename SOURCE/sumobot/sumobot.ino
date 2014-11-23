#include <Servo.h>

#include "bumper.h"
#include "infrared.h"
#include "range_finder.h"
#include "scorpion_xl.h"

void setup()
{
  int i;
  Serial.begin(9600);
  pinMode(LEFT_BUMPER, INPUT);
  pinMode(RIGHT_BUMPER, INPUT);
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  pinMode(BACK_IR, INPUT);
  pinMode(RFINDER_PIN, INPUT);
  irrf_servo.attach(SERVO_PIN);
  left_motor.attach(LEFT_MOTOR_PIN);
  right_motor.attach(RIGHT_MOTOR_PIN);
  
  for(i=0; i<180; i++)
    scan_field[i] = 0;
}

void push(){
  left_motor.write(PPM_SLOW);
  right_motor.write(PPM_SLOW);
}

void push_hard(){
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_MAX);
}


void circle(){
  // Reverse  
  left_motor.write(140);
  right_motor.write(100);  
}

void spin(){
  // Reverse  
  left_motor.write(PPM_MIN);
  right_motor.write(PPM_MIN);
  delay(500);
  
  // Reverse
  left_motor.write(PPM_MAX);
  right_motor.write(PPM_MIN);
  delay(300);  
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
  int rf_reading = analogRead(RFINDER_PIN);
  //field_index = sweep();
  // scan_field[field_index] = analogRead(RFINDER_PIN);
  
  // Bumper
  if(digitalRead(LEFT_BUMPER)) b_left_go++;
  else b_left_stop++;
 
  if(digitalRead(RIGHT_BUMPER)) b_right_go++;
  else b_right_stop++;
 
  // Infrared
  if(toDigital(LEFT_IR)) ir_left_go++;
  else ir_left_stop++;

  if(toDigital(RIGHT_IR)) ir_right_go++;
  else ir_right_stop++;
  
  if(toDigital(BACK_IR)) ir_back_go++;
  else ir_back_stop++;

  if(b_left_stop > 10 || b_right_stop > 10){
    b_left_go = 0; b_left_stop = 0;
    b_right_go = 0; b_right_stop = 0;
  }
  
  if(b_left_go > 3 || b_right_go > 3){
    push_hard();
  }else{
    if(rf_reading < 150) circle();
    else push();
  }

  //return;
  //if(ir_left_stop > 10){ ir_left_go=0; ir_left_stop=0; }
  //if(ir_right_stop > 10){ ir_right_go=0; ir_right_stop=0; }
  //if(ir_back_stop > 10){ ir_back_go=0; ir_back_stop=0; }
  
  if (ir_back_go > 2){
    ir_back_go = 0;
    push_hard(); 
  }
 
  if (ir_left_go > 2 || ir_right_go > 2){
    ir_left_go = 0;
    ir_right_go = 0;
    spin(); 
  }
}
