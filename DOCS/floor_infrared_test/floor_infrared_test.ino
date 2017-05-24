#define LEFT_FRONT_IR A5
#define RIGHT_FRONT_IR A2
#define BACK_LEFT_IR A4
#define BACK_RIGHT_IR A3

#define WB_THRESHOLD 600
#define IR_DELAY 140

void setup() 
{ 
  Serial.begin(9600);
  pinMode(LEFT_FRONT_IR, INPUT);
  pinMode(RIGHT_FRONT_IR, INPUT);
  pinMode(BACK_LEFT_IR, INPUT);
  pinMode(BACK_RIGHT_IR, INPUT);
  //
  pinMode(LED_BUILTIN, OUTPUT); 
}

boolean toDigital(uint8_t pin){
  int reading = analogRead(pin);
  delayMicroseconds(IR_DELAY);
  Serial.println(reading);
  return reading > WB_THRESHOLD;
}

void loop(){
  
  boolean fl = toDigital(LEFT_FRONT_IR);
  boolean fr = toDigital(RIGHT_FRONT_IR);
  boolean bl = toDigital(BACK_LEFT_IR);
  boolean br = toDigital(BACK_RIGHT_IR);

  Serial.print("LEFT_FRONT_IR: ");
  Serial.println(fl);
  
  Serial.print("RIGHT_FRONT_IR: ");  
  Serial.println(fr);

  Serial.print("BACK_LEFT_IR: ");  
  Serial.println(bl);
  
  Serial.print("BACK_RIGHT_IR: ");
  Serial.println(br);
  
  delay(1000);
}
