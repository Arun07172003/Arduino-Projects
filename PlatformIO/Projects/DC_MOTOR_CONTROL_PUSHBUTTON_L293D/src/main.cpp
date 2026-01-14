#include <Arduino.h>

#define DEBUG 1

#if DEBUG
  #define DEBUG_BEGIN(x) Serial.begin(x)
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_BEGIN(x) 
  #define DEBUG_PRINT(x) 
  #define DEBUG_PRINTLN(x) 
#endif


#define MOTORSPEED A0
#define IN1 3    /* right */
#define IN2 5    /* left */

#define INCREASE_BUTTON 10
#define DECREASE_BUTTON 11

int speedVal = 0;
const int stepVal = 10;

const int print_delay = 500;

const int debounce_delay = 200;
unsigned long now = 0, prev1 = 0, prev2 = 0, prevd = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(INCREASE_BUTTON, INPUT);
  pinMode(DECREASE_BUTTON, INPUT);
  pinMode(MOTORSPEED, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  DEBUG_BEGIN(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  now = millis();
  if(digitalRead(INCREASE_BUTTON) == HIGH && (now - prev1 >= debounce_delay)){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    speedVal += stepVal;
    prev1 = now;
  }
  if(digitalRead(DECREASE_BUTTON) == HIGH && (now - prev2 >= debounce_delay)){
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
    speedVal -= stepVal;
    prev2 = now;
  }
  if(speedVal == 10){
    speedVal = 100;
  }
  else if(speedVal <= 90 ){
    speedVal = 0;
  }
  if(now - prevd >= print_delay){
    DEBUG_PRINT("Speed Val: ");
    DEBUG_PRINTLN(speedVal);
    prevd = now;
  }
  speedVal = constrain(speedVal, 0, 255);
  analogWrite(MOTORSPEED, speedVal);
}
