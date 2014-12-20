#include <Servo.h>

Servo servo_0;
Servo servo_1;

void setup() {
  servo_0.attach(9);
  servo_1.attach(10);
  Serial.begin(9600);
}

void loop() {
    //modo seguidor de linha
    int seg1 = analogRead(A0); // 400
    int seg2 = analogRead(A1); // 400
    int seg3 = analogRead(A2); // 400
    if(seg1 > 400 && seg3 > 400){
      frente();
    }else{
      if(seg1 > 400 && seg2 > 400){
        esquerda_suave();
      }else
      if(seg3 > 400 && seg2 > 400){
        direita_suave();
      }else
      if(seg1 > 400 && seg2 < 400){
        esquerda();
      }else
      if(seg3 > 400 && seg2 < 400){
        direita();
      }else
      if(seg2 > 400 && seg1 < 400 && seg3 < 400){
        frente();
      }else{
        frente();
      }
    }
  delay(50);
}

void frente() {
  servo_0.write(180);
  servo_1.write(0);
}

void direita() {
  servo_0.write(180);
  servo_1.write(180);
}

void esquerda() {
  servo_0.write(0);
  servo_1.write(0);
}

void direita_suave() {
  servo_0.write(180);
  servo_1.write(78);
}

void esquerda_suave() {
  servo_0.write(90);
  servo_1.write(0);
}

void atras() {
  servo_0.write(0);
  servo_1.write(180);
}
