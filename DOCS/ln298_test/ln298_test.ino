#include <Servo.h>

#define PPM_MAX 180 -18
#define PPM_IDLE 90
#define PPM_MIN 0 + 18

#define LEFT_MOTOR_PIN 10
#define RIGHT_MOTOR_PIN 11
#define MOTOR_DELAY 100

// Scorpion XL PPM Signal
Servo left_motor;
Servo right_motor;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  left_motor.attach(LEFT_MOTOR_PIN);
  right_motor.attach(RIGHT_MOTOR_PIN);
}

void run()
{  
  int i;
  
  // LEFT //////////////////////
  for(i=PPM_IDLE; i<PPM_MAX; i++){
    left_motor.write(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PPM_MAX; i>PPM_MIN; i--){
    left_motor.write(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PPM_MIN; i<PPM_IDLE; i++){
    left_motor.write(i);
    delay(MOTOR_DELAY);
    // Serial.println(i);
  }

  // RIGHT //////////////////////
  for(i=PPM_IDLE; i<PPM_MAX; i++){
    right_motor.write(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PPM_MAX; i>PPM_MIN; i--){
    right_motor.write(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PPM_MIN; i<PPM_IDLE; i++){
    right_motor.write(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
}


void calibrate()
{
    digitalWrite(LED_BUILTIN, HIGH);
    right_motor.write(PPM_IDLE);
    left_motor.write(PPM_IDLE);
    delay(MOTOR_DELAY*30);
    digitalWrite(LED_BUILTIN, LOW);


    digitalWrite(LED_BUILTIN, LOW);
    left_motor.write(PPM_MAX);
    delay(MOTOR_DELAY);
    digitalWrite(LED_BUILTIN, HIGH);


    digitalWrite(LED_BUILTIN, LOW);
    left_motor.write(PPM_MIN);
    delay(MOTOR_DELAY);
    digitalWrite(LED_BUILTIN, HIGH);


    digitalWrite(LED_BUILTIN, LOW);
    right_motor.write(PPM_MAX);
    delay(MOTOR_DELAY);
    digitalWrite(LED_BUILTIN, HIGH);


    digitalWrite(LED_BUILTIN, LOW);
    right_motor.write(PPM_MIN);
    delay(MOTOR_DELAY);
    digitalWrite(LED_BUILTIN, HIGH);
}

void push(){
    left_motor.write(PPM_MAX);
    right_motor.write(PPM_MAX);
}

void idle(){
    left_motor.write(PPM_IDLE);
    right_motor.write(PPM_IDLE);
}

void loop(){
  push();
  //calibrate();
}

