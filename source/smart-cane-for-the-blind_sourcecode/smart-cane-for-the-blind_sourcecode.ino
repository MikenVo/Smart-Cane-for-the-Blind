int led = 7;
int trig = 3;
int echo = 2;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(led, LOW);
}

int Getdistance() {
  digitalWrite(trig, 1);
  delayMicroseconds(100);
  digitalWrite(trig, 0);
  delayMicroseconds(1000);
  digitalWrite(trig, 1);

  long duration = pulseIn(echo, 1);

  long distanceinCM = (duration * 0.034) / 2;

  return distanceinCM;
}

void loop() {
  long distance = Getdistance();

  if (distance >= 30) {
    digitalWrite(led, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    delay(100);
    
  }
  else {
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    delay(100);
  }
}
