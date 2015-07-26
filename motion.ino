const int dimmer = A0;
  int motionValue = 0;
  const int ledPin = 5;


void setup() {  

  Serial.begin(9600);
  pinMode( dimmer, INPUT);
  pinMode(5, OUTPUT);


}



void loop() {
   digitalWrite(ledPin, LOW);
  motionValue = analogRead(dimmer);
   Serial.println(motionValue);
  if (motionValue > 1000) {
    Serial.println("OK");
     digitalWrite(ledPin, HIGH);
  }

  //Serial.println("hello littleWorld!");
  delay(200);

}
