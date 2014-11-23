// #define IR_DEBUG

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
    Serial.println(reading);
  #endif
  return reading > WB_THRESHOLD;
}
