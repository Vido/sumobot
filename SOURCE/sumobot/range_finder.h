#include <Arduino.h>
//#include <Servo.h> 

// #define RF_DEBUG
#define SERVO_DELAY 2
#define RF_LEFT_PIN A0
#define RF_RIGHT_PIN A1

/*
Servo irrf_servo;

byte pos = 0;
char incr = 1;

int scan_field[180];

int sweep()
{
  //Serial.println(pos);
  for(; pos < 180 && incr > 0;)
  {
    //Serial.println(pos);
    irrf_servo.write(pos);
    pos += incr;
    delay(SERVO_DELAY);
    return pos - incr;
  }
  
  if(pos == 180) incr=-1;
  //incr=-1;

  for(; pos > 0 && incr < 0;)
  { 
    //Serial.println(pos);    
    irrf_servo.write(pos);
    pos += incr;
    delay(SERVO_DELAY);
    return pos + incr;
  } 
  
  if(pos == 0) incr=1;
  //incr=1;
  
}
*/
