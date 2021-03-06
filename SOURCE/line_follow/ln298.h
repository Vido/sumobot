// RIGHT
#define ENA 6 // PWM 
#define IN1 7
#define IN2 8
// LEFT
#define IN3 9  // PWM
#define IN4 10 // PWM
#define ENB 11 // PWM

#define PWM_MAX 115 // 190
#define PWM_SLOW 75 // 110
#define PWM_IDLE 50

#define MOTOR_DELAY 100
#define RIGHT_TRIM 1.25

void left_pid_controller(int x){
  if(x >= 0){
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  }else{
    x *= -1;
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  }
  int power = map(x, 0, 100, PWM_MAX, PWM_IDLE);

  analogWrite(ENB, power);
}

void right_pid_controller(int x){
  if(x >= 0){
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  }else{
    x *= -1;
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  }
  int power = map(x, 0, 100, PWM_MAX, PWM_IDLE);
  analogWrite(ENA, power * RIGHT_TRIM);
}

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
