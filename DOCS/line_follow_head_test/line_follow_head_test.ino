#define FAR_LEFT A0
#define LEFT A1
#define CENTER_LEFT A2
#define CENTER_RIGHT A3
#define RIGHT A4
#define FAR_RIGHT A5

#define WB_THRESHOLDS {500, 500, 500, 500, 300, 300}
#define IR_DELAY 140

void setup() 
{ 
  Serial.begin(9600);
  pinMode(FAR_LEFT, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(CENTER_LEFT, INPUT);
  pinMode(CENTER_RIGHT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(FAR_RIGHT, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); 
}

boolean toDigital(uint8_t pin){
  int thresholds[6] = WB_THRESHOLDS;
  int reading = analogRead(pin);
  delayMicroseconds(IR_DELAY);
  // Serial.println(reading);
  // Works only on UNO
  return reading > thresholds[(pin-14)];
}

void print_digital_readings(){
  
   boolean far_left =     toDigital(FAR_LEFT);
   boolean left =         toDigital(LEFT);
   boolean center_left  = toDigital(CENTER_LEFT);
   boolean center_right = toDigital(CENTER_RIGHT);
   boolean right =        toDigital(RIGHT);
   boolean far_right =    toDigital(FAR_RIGHT);

   Serial.print(far_left);
   Serial.print("\t");
   Serial.print(left);
   Serial.print("\t");
   Serial.print(center_left);
   Serial.print("\t");
   Serial.print(center_right);
   Serial.print("\t");
   Serial.print(right);
   Serial.print("\t");
   Serial.println(far_right);
}

void print_analog_readings(){
  
   int far_left =     analogRead(FAR_LEFT);
   int left =         analogRead(LEFT);
   int center_left  = analogRead(CENTER_LEFT);
   int center_right = analogRead(CENTER_RIGHT);
   int right =        analogRead(RIGHT);
   int far_right =    analogRead(FAR_RIGHT);

   Serial.print(far_left);
   Serial.print("\t");
   Serial.print(left);
   Serial.print("\t");
   Serial.print(center_left);
   Serial.print("\t");
   Serial.print(center_right);
   Serial.print("\t");
   Serial.print(right);
   Serial.print("\t");
   Serial.println(far_right);

}

void loop(){
  print_analog_readings();
  //print_digital_readings();
  delay(20);
}
