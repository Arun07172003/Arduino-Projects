#include <Arduino.h>


#define POT_PIN A1
#define LED_PIN 3

const float POT_RESOLUTION = 1023.0f; /* max , min = 0*/
const float LED_RESOLUTION = 255.0f;

unsigned long prev = 0, current = 0;

const int interval = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  current = millis();
  int readVal = analogRead(POT_PIN);
  if(current - prev >= interval){
    prev = millis();
    Serial.print("ReadVal = ");
    Serial.println(readVal);
    int Led_Analog_Val = (float)(readVal * LED_RESOLUTION) / POT_RESOLUTION;
    Serial.print("LedVal = ");
    Serial.println(Led_Analog_Val);
    analogWrite(LED_PIN, Led_Analog_Val);
  }
}



