#define LEFT_BUMPER 2
#define RIGHT_BUMPER 4
#define DEBOUNCE_DELAY 50 

void setup() 
{ 
  Serial.begin(9600);
  pinMode(LEFT_BUMPER, INPUT);
  pinMode(RIGHT_BUMPER, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); 
}

uint8_t debounce(uint8_t pin) {
  
  static uint8_t last_state;
  static long last_debounce_time;
  
  int reading = digitalRead(pin);

  if (reading != last_state)
    last_debounce_time = millis();
 
  if ((millis() - last_debounce_time) > DEBOUNCE_DELAY)
    last_state = reading;
 
  return last_state;
}

void loop(){

  uint8_t left = digitalRead(LEFT_BUMPER);
  uint8_t right = digitalRead(RIGHT_BUMPER);
  
  Serial.print(left);
  Serial.println(right);
  
  digitalWrite(LED_BUILTIN, left || right);
//  digitalWrite(LED_BUILTIN, left);
//  digitalWrite(LED_BUILTIN, right);

}
