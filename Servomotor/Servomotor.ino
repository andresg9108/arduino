#include <Servo.h>

const byte left = 7;
const byte right = 8;
Servo miServo;
int angulo = 90;

void setup() {
  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  miServo.attach(9); // Conecta el servo al pin digital 9
}

void loop(){
  if(digitalRead(left) == LOW){
    if(angulo <= 179){
      miServo.write(angulo++);
    }
  }else if(digitalRead(right) == LOW){
    if(angulo >= 1){
      miServo.write(angulo--);
    }
  }

  delay(15);
}

/*
void loop(){
  // Mueve el servo de 0° a 180°
  for (int angulo = 0; angulo <= 180; angulo++) {
    miServo.write(angulo);
    delay(15);
  }

  // Mueve el servo de 180° a 0°
  for (int angulo = 180; angulo >= 0; angulo--) {
    miServo.write(angulo);
    delay(15);
  }
}
*/