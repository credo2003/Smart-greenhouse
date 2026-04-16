#define BLYNK_TEMPLATE_ID "TMPL48tsBhNY3"
#define BLYNK_TEMPLATE_NAME "Led"
#define BLYNK_AUTH_TOKEN "gwpv1Sz4_HmfPq2O1VR-UvNa6OndTXOg"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "2.4G FreeWiFi";
char pass[] = "";

#define LED_PIN 2   // D4 = GPIO2

BLYNK_CONNECTED() {
  Serial.println("Blynk connected");
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  Serial.println("Start");
  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Connected");
}

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.print("Button value: ");
  Serial.println(value);

  if (value == 1) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
}

void loop()
{
  Blynk.run();
}
