#define button 11
#define redLED 8
#define greenLED 9
#define blueLED 10
int state = 0;
int old = 0;
int buttonPoll = 0;
void setup() {
  pinMode(button,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  
  digitalWrite(redLED,LOW);
  digitalWrite(greenLED,LOW);
  digitalWrite(blueLED,LOW);
  }
               void loop() {
                 buttonPoll = digitalRead(button);
                 if(buttonPoll ==1){
                   delay(50);
                   buttonPoll = digitalRead(button);
                   if(buttonPoll == 0) {
                     state = old + 1;
                   }
                 }
                 else {
                   delay(100);
                 }
                 switch (state) {
                   case 1:
                   digitalWrite(redLED,HIGH);
                   digitalWrite(greenLED,LOW);
                   digitalWrite(blueLED,LOW);
                   old = state;
                   break;
                    case 2:
                   digitalWrite(redLED,LOW);
                   digitalWrite(greenLED,HIGH);
                   digitalWrite(blueLED,LOW);
                   old = state;
                   break;
                    case 3:
                   digitalWrite(redLED,LOW);
                   digitalWrite(greenLED,LOW);
                   digitalWrite(blueLED,HIGH);
                   old = state;
                   break;
                    case 4:
                   digitalWrite(redLED,HIGH);
                   digitalWrite(greenLED,LOW);
                   digitalWrite(blueLED,HIGH);
                   old = state;
                   break;
                    case 5:
                   digitalWrite(redLED,HIGH);
                   digitalWrite(greenLED,HIGH);
                   digitalWrite(blueLED,HIGH);
                   old = state;
                   break;
                   default:
                   digitalWrite(redLED,LOW);
                   digitalWrite(greenLED,LOW);
                   digitalWrite(blueLED,LOW);
                   old = 0;
                   break;
                 }
               }
