#include <Arduino.h>

//#define IR_DEBUG

#define LEFT_IR A3
#define RIGHT_IR A4
#define BACK_IR A5

#define WB_THRESHOLD 600
#define IR_DELAY 140

boolean toDigital(uint8_t pin){
  int reading = analogRead(pin);
  delayMicroseconds(IR_DELAY);
  #ifdef IR_DEBUG
    Serial.print(pin);
    Serial.print("-");  
    Serial.println(reading);
  #endif
  return reading > WB_THRESHOLD;
}

int dra_field(int *vector, int v_size){
  int i;
  int acc=0;

  // Mean
  for(i=0; i<v_size; i++){
    acc += vector[i] / v_size;
  }
}
