#define LED_SAT 2
#define RELAY 1
#define PPM 3

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LED_SAT, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(PPM, INPUT);
  digitalWrite(LED_SAT, LOW);
  digitalWrite(RELAY, LOW);
}

void loop() {
  // PPM
  int pulse_width = pulseIn(PPM, HIGH);

  // SAT LED
  if(500 < pulse_width && pulse_width < 2500){
    digitalWrite(LED_SAT, HIGH);   // turn the LED on (HIGH is the voltage level)
  }else{
    digitalWrite(LED_SAT, LOW);
    digitalWrite(RELAY, LOW); // fail safe
    return;
  }

  // RELAY
  if(1650 < pulse_width && pulse_width < 2500){
    digitalWrite(RELAY, HIGH);
  }else{
    digitalWrite(RELAY, LOW); // fail safe
  }
}
