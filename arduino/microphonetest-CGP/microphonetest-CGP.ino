int microphonePin = 9;
int state = 0;
int mappedState;
int POTENTIOMETER_PIN = 12;
int ledStrip = 5;

void setup() {
  pinMode(microphonePin, INPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  pinMode(ledStrip, INPUT);
  Serial.begin(9600);
}

void loop() {
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int pVal = map(potentiometerValue, 0, 1023, 0, 40);
  if(pVal<10){
    digitalWrite(5,HIGH);
  } else if (10<pVal<20){
    digitalWrite(5,LOW);
  } else if (20<pVal<30){
    digitalWrite(5,HIGH);
  } else{
    digitalWrite(5,HIGH);
  }


  state = analogRead(microphonePin);
  //String stateString = String(state);
  //mappedState = map(state, 0, 10, 240,250);
  Serial.println(state);
  delay(10);

  // Serial.println(state);
}