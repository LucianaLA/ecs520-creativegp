int microphonePin = 9;
int state = 0;
int mappedState;

void setup() {
  pinMode(microphonePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  state = analogRead(microphonePin);
  //String stateString = String(state);
  //mappedState = map(state, 0, 10, 240,250);
  Serial.println(state);
  delay(10);

  // Serial.println(state);
}