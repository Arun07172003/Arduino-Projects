#include <Arduino.h>

#define BUTTON 3
#define LED 7

bool LED_STATE = false;

const int debounce_delay = 200;
unsigned long now = 0, prev = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  now = millis();
  if(digitalRead(BUTTON) == 1 && (now - prev >= debounce_delay)){
    LED_STATE = !LED_STATE;
    digitalWrite(LED, LED_STATE);
    prev = millis();
  }
}
