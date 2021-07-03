int trigPin = 9;
int echoPin = 10;

int led1 = 5;
int led2 = 6;
int led3 = 7;

bool isLedOn1 = false;
bool isLedOn2 = false;
bool isLedOn3 = false;

void setup() {
  Serial.begin(9600);

// DEFINING THE PINs FOR ULTRA-SONIC SENSOR
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

// DEFINING THE LED PINs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

//  LOGIC FOR CALCULATING THE DISTANCE IN CM USING ULTRA-SONIC SENSOR.
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);

  if ((distance <= 10)) // If distance is <= 10cm turn LED1 ON/OFF
  {
    toggleLed1();
    delay(1000);
  }
  else if (distance > 10 && distance <= 15) // If distance > 10cm AND <= 15cm turn LED2 ON/OFF
  {
    toggleLed2();
    delay(1000);
  }
  else if (distance > 15 && distance <= 20) // If distance > 15cm AND <= 20cm turn LED2 ON/OFF
  {
    toggleLed3();
    delay(1000);
  }
}

void toggleLed1() {
  if (isLedOn1) {
    isLedOn1 = false;
    digitalWrite(led1, LOW);
  }
  else {
    isLedOn1 = true;
    digitalWrite(led1, HIGH);
  }
}

void toggleLed2() {
  if (isLedOn2) {
    isLedOn2 = false;
    digitalWrite(led2, LOW);
  }
  else {
    isLedOn2 = true;
    digitalWrite(led2, HIGH);
  }
}

void toggleLed3() {
  if (isLedOn3) {
    isLedOn3 = false;
    digitalWrite(led3, LOW);
  }
  else {
    isLedOn3 = true;
    digitalWrite(led3, HIGH);
  };
}
