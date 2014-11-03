#include <Servo.h> 
 
Servo m_left; 
Servo m_right;

void setup() 
{ 
  m_left.attach(9); 
  m_right.attach(10);
} 
 
 
void loop() 
{ 
  // Spin !!!
  m_right.write(180);
  m_left.write(0);
} 
