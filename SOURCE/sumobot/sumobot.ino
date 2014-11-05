#include <Servo.h> 

// Scorpion XL PPM Signal 
int left_motor_pin = 3;
int right_motor_pin = 10;
Servo left_motor;
Servo right_motor;

// 
int left_bumper = 4;
int right_bumper = 12;
int monitor_ired = 11;
int center_ired = A0;


void setup() 
{ 
  Serial.begin(9600);
  pinMode(monitor_ired, OUTPUT);
  pinMode(center_ired, INPUT);
  pinMode(left_bumper, INPUT);
  pinMode(right_bumper, INPUT);
  left_motor.attach(left_motor_pin); 
  right_motor.attach(right_motor_pin);  
} 

void search()
{
  int ir_val = analogRead(center_ired);
  Serial.println(ir_val);
  analogWrite(monitor_ired, map(ir_val, 0, 1023, 0 , 255));
  
}

void push(){
  if(digitalRead(left_bumper)){
    left_motor.write(180);
  }else{
    left_motor.write(0);  
  }

  if(digitalRead(right_bumper)){
    right_motor.write(180);
  }else{
    right_motor.write(0);  
  }
}

void loop() 
{ 
  search();
  push();
} 
