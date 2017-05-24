#include <Arduino.h>

// #define IR_DEBUG

#define FAR_LEFT A0
#define LEFT A1
#define CENTER_LEFT A2
#define CENTER_RIGHT A3
#define RIGHT A4
#define FAR_RIGHT A5

#define WB_THRESHOLD 700
#define WB_THRESHOLDS {350, 350, 350, 300, 300, 300}

#define IR_DELAY 30

boolean toDigital(uint8_t pin){
  int thresholds[6] = WB_THRESHOLDS;
  int reading = analogRead(pin);
  delayMicroseconds(IR_DELAY);
  #ifdef IR_DEBUG
    Serial.print(pin);
    Serial.print(" - ");  
    Serial.println(reading);
  #endif
  // Works only on UNO
  return reading > thresholds[(pin-14)];
}

