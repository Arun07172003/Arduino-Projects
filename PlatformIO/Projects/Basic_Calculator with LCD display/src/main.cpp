#include <Arduino.h>
#include <LiquidCrystal.h>
#include <stdlib.h>

const int RS = 2, EN = 3;

const int D4 = 4, D5 = 5, D6 = 6, D7 = 7;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
const int button_pin = 9;

double number1 = 0.0f, number2 = 0.0f, result = 0.0f;
char op;
char buffer[50], num1[10], num2[10], num3[10];

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.write("Hello World!!");
  lcd.setCursor(0, 1);
  lcd.write("Good Morning");
  pinMode(button_pin, INPUT);
  delay(2000);
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (digitalRead(button_pin) == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write("Enter number 1: ");
    Serial.println("Enter number 1: ");
    while (Serial.available() == 0)
    {
    }
    number1 = Serial.parseFloat();
    lcd.setCursor(0, 0);
    lcd.write("Enter operator: ");
    Serial.println("Enter operator: ");
    while (Serial.available() == 0)
    {
    }
    op = Serial.read();
    lcd.setCursor(0, 0);
    lcd.write("Enter number 2: ");
    Serial.println("Enter number 2: ");
    while (Serial.available() == 0)
    {
    }
    number2 = Serial.parseFloat();
   
    switch (op)
    {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      if (number2 != 0)
      {
        result = number1 / number2;
      }
      else
      {
        result = -1;
      }
      break;
    default:
      Serial.println("Enter a valid operator(+ / - / * / /)");
      break;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    dtostrf(number1, 5, 2, num1);
    dtostrf(number2, 5, 2, num2);
    dtostrf(result, 5, 2, num3);
    sprintf(buffer, "%s %c %s", num1, op, num2);
    lcd.print(buffer);
    lcd.setCursor(0, 1);
    sprintf(buffer, " = %s", num3);
    lcd.print(buffer);
  }
}
