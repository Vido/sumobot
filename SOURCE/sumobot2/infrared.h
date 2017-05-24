#include <Arduino.h>

//#define IR_DEBUG

#define LEFT_FRONT_IR A5
#define RIGHT_FRONT_IR A2
#define BACK_LEFT_IR A4
#define BACK_RIGHT_IR A3

#define WB_THRESHOLD 350
#define IR_DELAY 70

boolean toDigital(uint8_t pin){
  int reading = analogRead(pin);
  // delayMicroseconds(IR_DELAY);
    Serial.print(pin);
    Serial.print("-");  
    Serial.println(reading);
  return reading < WB_THRESHOLD;
}

int dra_field(int *vector, int v_size){
  int i;
  int acc=0;

  // Mean
  for(i=0; i<v_size; i++){
    acc += vector[i] / v_size;
  }
}
