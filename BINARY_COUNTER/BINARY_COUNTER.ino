#define BIT_4 2 /*LSB*/
#define BIT_3 3
#define BIT_2 4
#define BIT_1 5 /*MSB*/

const int bit_array[] = {2, 3, 4, 5};

const int interval = 2000;
unsigned long now = 0;
unsigned long prev = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(BIT_1, OUTPUT);
  pinMode(BIT_2, OUTPUT);
  pinMode(BIT_3, OUTPUT);
  pinMode(BIT_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i <= 15;){
    now = millis();
    if(now - prev >= interval || now < 100){
      digitalWrite(BIT_1, LOW);
      digitalWrite(BIT_2, LOW);
      digitalWrite(BIT_3, LOW);
      digitalWrite(BIT_4, LOW);
      for(int j = 0; j < 4; j++){
        if((i & (1 << j)) != 0){
          digitalWrite(bit_array[j], HIGH);
        }
        else{
          digitalWrite(bit_array[j], LOW);
        }
      }
      prev = now;
      i++;
    }
  }
}
