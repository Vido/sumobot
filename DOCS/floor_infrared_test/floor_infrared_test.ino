#define LEFT_IR A3
#define RIGHT_IR A4
#define BACK_IR A5

#define WB_THRESHOLD 600
#define IR_DELAY 140

void setup() 
{ 
  Serial.begin(9600);
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  pinMode(BACK_IR, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); 
}

boolean toDigital(uint8_t pin){
  int reading = analogRead(pin);
  delayMicroseconds(IR_DELAY);
  Serial.println(reading);
  return reading > WB_THRESHOLD;
}

void loop(){
  // boolean left = toDigital(LEFT_IR);
  // boolean right = toDigital(RIGHT_IR);
   boolean back = toDigital(BACK_IR);

  // Serial.print(left);
  // Serial.print(right);
   Serial.print(back);
}
