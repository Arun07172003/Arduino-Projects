#include <Arduino.h>

#define LED 3

#define INCREASE_BUTTON 5

#define DECREASE_BUTTON 7

#define FLASH_LED 9
const int FLASH_DELAY = 50;
bool FLASH_STATE = false;

int LED_BRIGHTNESS = 0;

const int value = 10;

unsigned long now = 0, prev1 = 0, prev2 = 0, prevF = 0;

const int debounce_delay = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(INCREASE_BUTTON, INPUT);
  pinMode(DECREASE_BUTTON, INPUT);
  pinMode(FLASH_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  now = millis();
  if(digitalRead(INCREASE_BUTTON) == HIGH && (now - prev1 >= debounce_delay)){
    prev1 = now;
    LED_BRIGHTNESS += value;
    LED_BRIGHTNESS = constrain(LED_BRIGHTNESS, 0, 255);
    analogWrite(LED, LED_BRIGHTNESS);
  }

  if(digitalRead(DECREASE_BUTTON) == HIGH && (now - prev2 >= debounce_delay)){
    prev2 = now;
    LED_BRIGHTNESS -= value;
    LED_BRIGHTNESS = constrain(LED_BRIGHTNESS, 0, 255);
    analogWrite(LED, LED_BRIGHTNESS);
  }

  if(LED_BRIGHTNESS > 230 && (now - prevF >= FLASH_DELAY)){
    FLASH_STATE = !FLASH_STATE;
    digitalWrite(FLASH_LED, FLASH_STATE);
    prevF = now;
  }
  else if(LED_BRIGHTNESS <= 230){
    FLASH_STATE = false;
    digitalWrite(FLASH_LED, FLASH_STATE);
  }
  
}

