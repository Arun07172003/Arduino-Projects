#include <Arduino.h>

#define INPUT_CLOCK 5
#define OUTPUT_CLOCK 6
#define DATA_PIN 9

byte data = 0X00;

unsigned long now = 0, prev = 0;
const int interval = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_CLOCK, OUTPUT);
  pinMode(OUTPUT_CLOCK, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  now = millis();
  if(now - prev >= interval){
    prev = now;
    digitalWrite(OUTPUT_CLOCK, LOW);
    shiftOut(DATA_PIN, INPUT_CLOCK, LSBFIRST, data);
    digitalWrite(OUTPUT_CLOCK, HIGH);
    if(data < 255){
      data += 1;
    }
    else{
      data = 0;
    }
  }
}

