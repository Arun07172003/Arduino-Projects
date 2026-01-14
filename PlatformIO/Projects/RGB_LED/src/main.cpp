#include <Arduino.h>

#define RED_LED 2
#define BLUE_LED 4
#define GREEN_LED 3


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.println("Enter any value between 0 and 255(inclusive): ");
  Serial.println("Three times(RED, GREEN, BLUE)");
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    int red = Serial.parseInt();
    while(Serial.available() == 0){}
    int green = Serial.parseInt();
    while(Serial.available() == 0){}
    int blue = Serial.parseInt();

    red = constrain(red, 0, 255);
    green = constrain(green, 0, 255);
    blue = constrain(blue, 0, 255);

    analogWrite(RED_LED, red);
    analogWrite(GREEN_LED, green);
    analogWrite(BLUE_LED, blue);
  }
}

