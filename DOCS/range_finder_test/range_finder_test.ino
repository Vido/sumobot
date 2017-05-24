#include <Servo.h> 

#define SERVO_PIN 9
#define SERVO_DELAY 3
#define RFINDER_PIN A0

Servo irrf_servo;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(RFINDER_PIN, INPUT);
  irrf_servo.attach(SERVO_PIN); 
}


static int pos = 0;
static int incr = 1;

void sweep()
{

  for(; pos < 180 && incr > 0;)
  {
    irrf_servo.write(pos);
    pos += incr;
    delay(SERVO_DELAY);
    return;
  }
  if(pos == 180) incr=-1;

  for(; pos > 0 && incr < 0;)
  {                                
    irrf_servo.write(pos);
    pos += incr;
    delay(SERVO_DELAY);
    return;
  } 
  
  if(pos == 0) incr=1;
  Serial.println(pos);
  Serial.println(incr);

} 

void loop(){
  int read_value;
  static int maxx = 0;
  static int minn = 1023;

  read_value = analogRead(A0);
  read_value = analogRead(A0);
  delayMicroseconds(70);
  
  if(read_value > maxx) maxx = read_value;
  if(read_value < minn) minn = read_value;
  
  // sweep();
  // irrf_servo.write(0);

  Serial.print(minn); // min = 0
  Serial.print("-");
  Serial.print(read_value);
  Serial.print("-");
  Serial.println(maxx);// max = 747
  delay(500);
  
  //Serial.println(read_value);
}
