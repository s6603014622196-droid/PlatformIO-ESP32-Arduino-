#include <Arduino.h>

#define RELAY_PIN 26
#define LED_PIN   2

unsigned long lastBlink = 0;
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Type ON or OFF");
}

void loop() {
  // ไฟกะพริบแบบ non-blocking
  if (millis() - lastBlink >= 1000) {
    lastBlink = millis();
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  // รับคำสั่งได้ทันที
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "ON")  digitalWrite(RELAY_PIN, HIGH);
    if (cmd == "OFF") digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay: " + cmd);
  }
}