#include <Arduino.h>

#define RED_LED 2
#define BLUE_LED 3
#define GREEN_LED 4
char buffer[70];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  sprintf(buffer, "1. RED LED\n2. BLUE LED\n3.GREEN LED\n4. Turn off all LEDs(Turn off)\n");
  Serial.print(buffer);
  Serial.println("Enter the colour which you want to light(name): ");
  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    String user_input = Serial.readString();
    user_input.trim();
    user_input.toLowerCase();
    if(user_input == "red"){
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
    else if(user_input == "blue"){
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
    else if(user_input == "green"){
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
    else{
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
  }
}

