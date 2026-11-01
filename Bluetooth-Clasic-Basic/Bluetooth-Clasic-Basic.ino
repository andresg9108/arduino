const byte led = 2;

char input = "";

void setup() {
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
  // Serial.begin(38400);
}

void loop() {
  if(Serial.available() > 0) {
    input = Serial.read();
  }

  switch(input) {
    case 'a':
      digitalWrite(led, HIGH);
      break;
    case 'b':
      digitalWrite(led, LOW);
      break;
  }
}