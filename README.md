IoT RGB Color Changer using Arduino and Push Button

🔍 Overview

This project is an IoT-based RGB Color Changer that uses an Arduino and a push button to cycle through multiple colors on an RGB LED.
Each time you press the button, the LED changes color — demonstrating how digital input/output and color mixing can be controlled with simple code and hardware.

Features

Changes RGB LED color with every button press 🎨
Simple and easy-to-understand Arduino code
Demonstrates digital input/output control
Great for IoT and hardware beginners
Can be upgraded with Wi-Fi or Bluetooth control

Components Used

Component	Quantity	Description

Arduino Uno	1	Main microcontroller board
RGB LED	1	Common Anode or Cathode type
Push Button	1	Used to trigger color change
Resistors	3 × 220Ω	Limits current for each LED pin
Breadboard	1	For easy connections
Jumper Wires	As needed	To connect components

How It Works

1. The push button is connected to Arduino as an input.
2. Every button press increases the colorMode value.
3. The program uses that value to select a color and send PWM signals to the RGB LED pins.
4. The LED color changes in sequence every time you press the button.

Picture of the Circuit 
<img width="1440" height="737" alt="image" src="https://github.com/user-attachments/assets/4e1165c3-b189-4443-bb2f-a22ca553e1c5" />

CODING FOR THIS PROJECT 

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

               Author

Meghna Mal
💡 Passionate about IoT, AI, and Smart Systems
🌐 GitHub: Meghna-333

