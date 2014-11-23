#include <Servo.h> 

// #define RF_DEBUG
#define SERVO_PIN 9
#define SERVO_DELAY 3
#define RFINDER_PIN A0

Servo irrf_servo;

int 
byte pos = 0;
char incr = 1;

int scan_field[180];

int sweep()
{
  for(; pos < 180 && incr > 0;)
  {
    irrf_servo.write(pos);
    pos += incr;
    delay(SERVO_DELAY);
    return pos - incr;
  }
  
  // if(pos == 180) incr=-1;
  incr=-1;

  for(; pos > 0 && incr < 0;)
  {                                
    irrf_servo.write(pos);
    pos += incr;
    delay(SERVO_DELAY);
    return pos + incr;
  } 
  
  // if(pos == 0) incr=1;
  incr=1;

  #ifdef RF_DEBUG
    Serial.println(pos);
    Serial.println(incr);
  #endif
}
