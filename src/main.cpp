#include <Arduino.h>

#define RELAY_PIN 26
#define LED_PIN   2

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Type ON or OFF");
}

void loop() {
  // ไฟกะพริบบอกสถานะ
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);

  // รับคำสั่งสั่งรีเลย์
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "ON")  digitalWrite(RELAY_PIN, HIGH);
    if (cmd == "OFF") digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay: " + cmd);
  }
}