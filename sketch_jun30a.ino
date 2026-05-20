int sensorPin = A0;
int sensorValue = 0;

int ledPin = 8;      // світлодіод на піні D8
int dryValue = 1000;  // поріг сухого ґрунту

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  Serial.print("Вологість: ");
  Serial.println(sensorValue);

  // якщо ґрунт сухий
  if (sensorValue < dryValue) {
    digitalWrite(ledPin, HIGH); // увімкнути LED
  }
  else {
    digitalWrite(ledPin, LOW); // вимкнути LED
  }

  delay(1000);
}
