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
  
  for(i=0; i<180; i++)
    scan_field[i] = 0;
}

/*
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
*/

void loop()
{
//  search();
}
