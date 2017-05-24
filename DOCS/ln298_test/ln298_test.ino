// RIGHT
#define ENA 6 // PWM 
#define IN1 7
#define IN2 8
// LEFT
#define IN3 9  // PWM
#define IN4 10 // PWM
#define ENB 11 // PWM

#define PWM_MAX 195
#define PWM_SLOW 110
#define PWM_IDLE 35

#define MOTOR_DELAY 100
#define RIGHT_TRIM 1.25

void left_motor_forward(int power){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, power);
}

void right_motor_forward(int power){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, power * RIGHT_TRIM);
}

void left_motor_backward(int power){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, power);
}

void right_motor_backward(int power){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, power * RIGHT_TRIM);
}

void motor_break(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void run()
{  
  int i;
  
  // LEFT //////////////////////
  for(i=PWM_IDLE; i<PWM_MAX; i++){
    left_motor_forward(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PWM_MAX; i>PWM_IDLE; i--){
    left_motor_forward(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PWM_IDLE; i>PWM_MAX; i--){
    left_motor_backward(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PWM_MAX; i<PWM_IDLE; i++){
    left_motor_backward(i);
    delay(MOTOR_DELAY);
    // Serial.println(i);
  }

  // RIGHT //////////////////////
  for(i=PWM_IDLE; i<PWM_MAX; i++){
    right_motor_forward(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PWM_MAX; i>PWM_IDLE; i--){
    right_motor_forward(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PWM_IDLE; i>PWM_MAX; i--){
    right_motor_backward(i);
    delay(MOTOR_DELAY);
    Serial.println(i);
  }
  for(i=PWM_MAX; i<PWM_IDLE; i++){
    right_motor_backward(i);
    delay(MOTOR_DELAY);
    //Serial.println(i);
  }
}


void calibrate()
{
    digitalWrite(LED_BUILTIN, HIGH);
    right_motor_forward(PWM_IDLE);
    left_motor_forward(PWM_IDLE);
    delay(MOTOR_DELAY*30);

    digitalWrite(LED_BUILTIN, LOW);
    left_motor_forward(PWM_MAX);
    delay(MOTOR_DELAY);

    digitalWrite(LED_BUILTIN, HIGH);
    left_motor_backward(PWM_MAX);
    delay(MOTOR_DELAY);

    digitalWrite(LED_BUILTIN, LOW);
    right_motor_forward(PWM_MAX);
    delay(MOTOR_DELAY);
    
    digitalWrite(LED_BUILTIN, HIGH);
    right_motor_backward(PWM_MAX);
    delay(MOTOR_DELAY);
}

void push(){
    left_motor_forward(PWM_MAX);
    right_motor_forward(PWM_MAX);
}

void idle(){
    left_motor_forward(PWM_IDLE);
    right_motor_forward(PWM_IDLE);
}

void loop(){
  // push();
  //idle();
  //calibrate();
  run();
}

