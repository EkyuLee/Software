// pin number -- start
// dm453 trig, echo
const int trigPin = 10;
const int echoPin = 11;

//green, yellow, red led pin
const int greenPin = 3;
const int yellowPin = 2;
const int redPin = 1;

// pin number -- end

float duration, distance;

//setup 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  //distance standard, low than 10 = RED, 10 ~ 15 = yellow, over the 15 = green
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
  if (distance < 10) {
    digitalWrite(redPin, HIGH);
  } else if (10 <= distance && distance < 15) {
    digitalWrite(yellowPin, HIGH);
  } else {
    digitalWrite(greenPin, HIGH);
  }

  delay(500);
}




/*
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}


*/