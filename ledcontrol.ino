#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// LED pins
#define LED1 D1
#define LED2 D2
#define LED3 D3

// Create KiwisIoT object
KiwisIoT kiwisiot(ssid, pass, topic);

// LED control callback
void onControl(String ch, String val) {

  val.trim();

  // Channel 0 - LED 1
  if (ch == "0") {
    if (val == "1") {
      digitalWrite(LED1, HIGH);
      Serial.println("LED 1 ON");
    }
    else if (val == "0") {
      digitalWrite(LED1, LOW);
      Serial.println("LED 1 OFF");
    }
  }

  // Channel 1 - LED 2
  else if (ch == "1") {
    if (val == "1") {
      digitalWrite(LED2, HIGH);
      Serial.println("LED 2 ON");
    }
    else if (val == "0") {
      digitalWrite(LED2, LOW);
      Serial.println("LED 2 OFF");
    }
  }

  // Channel 2 - LED 3
  else if (ch == "2") {
    if (val == "1") {
      digitalWrite(LED3, HIGH);
      Serial.println("LED 3 ON");
    }
    else if (val == "0") {
      digitalWrite(LED3, LOW);
      Serial.println("LED 3 OFF");
    }
  }
}

void setup() {

  Serial.begin(115200);

  // Configure LED pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Initially all LEDs OFF
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  // Initialize KiwisIoT
  kiwisiot.begin();

  // Receive dashboard commands
  kiwisiot.onReceive(onControl);

  Serial.println("Three LED Control Ready");
}

void loop() {

  kiwisiot.run();

}
