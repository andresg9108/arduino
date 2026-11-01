const byte leftA = 2;
const byte leftB = 4;
const byte leftPWM = 3;
const byte rightA = 7;
const byte rightB = 8;
const byte rightPWM = 6;

char input = "";

void setup() {
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    input = Serial.read();
  }

  switch(input) {
    case 'a':
      forward();
      break;
    case 'b':
      back();
      break;
  }
}

void forward() {
  digitalWrite(leftA, HIGH);
  digitalWrite(leftB, LOW);
  
  digitalWrite(rightA, HIGH);
  digitalWrite(rightB, LOW);

  analogWrite(leftPWM, 255);
  analogWrite(rightPWM, 255);

  delay(2000);

  analogWrite(leftPWM, 0);
  analogWrite(rightPWM, 0);
}

void back() {
  digitalWrite(leftA, LOW);
  digitalWrite(leftB, HIGH);

  digitalWrite(rightA, LOW);
  digitalWrite(rightB, HIGH);

  analogWrite(leftPWM, 255);
  analogWrite(rightPWM, 255);

  delay(2000);

  analogWrite(leftPWM, 0);
  analogWrite(rightPWM, 0);
}