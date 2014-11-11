#include <Servo.h>

#define SWEEP_READS 18
#define SERVO_STEP  180/SWEEP_READS
#define SERVO_DELAY 360/SWEEP_READS

// Scorpion XL PPM Signal
int left_motor_pin = 9;
int right_motor_pin = 10;
int center_sweeper_pin = 3;

Servo left_motor;
Servo right_motor;
Servo center_sweeper;

//
int left_bumper = 4;
int right_bumper = 12;
int monitor_ired = 11;
int center_rangefinder = A0;


void setup()
{
  Serial.begin(9600);
  pinMode(monitor_ired, OUTPUT);
  pinMode(center_rangefinder, INPUT);
  pinMode(left_bumper, INPUT);
  pinMode(right_bumper, INPUT);
  left_motor.attach(left_motor_pin);
  right_motor.attach(right_motor_pin);
  center_sweeper.attach(center_sweeper_pin);
}

int *search()
{
  static int i;
  int ir_values[SWEEP_READS];

  if(i==0){
    for(i=0; i<180; i+=SERVO_STEP){
      ir_values[i/SERVO_STEP] = analogRead(center_rangefinder);
      delayMicroseconds(70);
      center_sweeper.write(i);
      delay(SERVO_DELAY);
      // Serial.print(i);
      // Serial.print("-");
      // Serial.println(ir_values[i/SERVO_STEP]);
    }
  }else{
    for(i=180; i>0; i-=SERVO_STEP){
      ir_values[i/SERVO_STEP] = analogRead(center_rangefinder);
      delayMicroseconds(70);
      center_sweeper.write(i);
      delay(SERVO_DELAY);
      // Serial.print(i);
      // Serial.print("-");
      // Serial.println(ir_values[i/SERVO_STEP]);
    }
  }
  return ir_values;
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
