int Speaker = A0; 
int ledPin = 9;
int Old=0;
int SpeakerVolts=0;

void setup() {
  pinMode(Speaker, INPUT);
  Serial.begin(9600);
  Old=0;
  pinMode(ledPin, OUTPUT);
}

void loop() {
  SpeakerVolts = analogRead(Speaker);
  if (SpeakerVolts > Old){
    Old = SpeakerVolts;
  };
  if (SpeakerVolts < Old){
    Serial.println(Old);
  };

  int brightness = (255/Old) * SpeakerVolts;
  analogWrite(ledPin, brightness);
}