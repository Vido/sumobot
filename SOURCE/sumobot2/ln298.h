// RIGHT
#define ENA 6 // PWM 
#define IN1 7
#define IN2 8
// LEFT
#define IN3 9  // PWM
#define IN4 10 // PWM
#define ENB 11 // PWM

// default 180
// default 180

/*
#define PWM_MAX 180
#define PWM_SLOW 90
#define PWM_IDLE 32
*/

#define PWM_MAX 90
#define PWM_SLOW 50
#define PWM_IDLE 32

#define RIGHT_TRIM 1.24 

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

/**********************/

void push(){
  left_motor_forward(PWM_SLOW);
  right_motor_forward(PWM_SLOW);
}

void push_hard(){
  left_motor_forward(PWM_MAX);
  right_motor_forward(PWM_MAX);
}

void circle_left(){
  // Reverse  
  left_motor_forward(PWM_SLOW * 1.5);
  right_motor_forward(PWM_SLOW);  
}

void circle_right(){
  // Reverse  
  left_motor_forward(PWM_SLOW * 1.2);
  right_motor_forward(PWM_SLOW * 1.5);
}

void spin(){
  // Reverse  
  right_motor_backward(PWM_MAX);
  right_motor_backward(PWM_MAX);
  delay(300);
  
  // Reverse
  left_motor_forward(PWM_MAX);
  right_motor_backward(PWM_MAX);
  delay(150);  
}
