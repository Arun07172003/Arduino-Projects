#define RED_LED 2
#define YELLOW_LED 3
#define GREEN_LED 4

#define BUTTON 7

bool stage1 = false;
bool stage2 = false;
bool stage3 = true;

const int interval = 2000;

unsigned long prev = 0;
unsigned long now = 0;

bool isPressed = false;

unsigned long int finished = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  now = millis();

  if(digitalRead(BUTTON) == LOW){
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    isPressed = true;
  }

  else if(isPressed == true){
    if(stage1 == true && stage3 == false){
      stage3 = true;
      stage2 = false;
      stage1 = false;
    }
    else if(stage2 == true && stage1 == false){
      stage1 = true;
      stage2 = false;
      stage3 = false;
    }
    else{
      stage2 = true;
      stage3 = false;
      stage1 = false;
    }
    finished = now - prev;
    prev = now - interval;
    isPressed = false;
  }
  else if((stage3 == true && (now - prev >= interval)) || now < 100){
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    stage1 = true;
    stage3 = false;
    prev = now - finished;
    finished = 0;
  }

  else if(stage1 == true && (now - prev >= interval)){
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    stage2 = true;
    stage1 = false;
    prev = now - finished;
    finished = 0;
  }

  else if(stage2 == true && (now - prev >= interval)){
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    stage3 = true;
    stage2 = false;
    prev = now - finished;
    finished = 0;
  }
}
