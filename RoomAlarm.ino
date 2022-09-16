// COMP45 1045
// Project
// IAGO RAMALHO DE HOLANDA FURTADO
// 200507139
// 08/17/2022


#include <LiquidCrystal.h>
#define NOTE_A1 55
#define NOTE_A3 220
#define NOTE_E4 330


// variables
int buzzerPin = 7 ; //The buzzerPin
int led = 13; // Pin LED
int sensor = 2; // Sensor
int state = LOW; // By default, no motion detected
int val = 0; // Variable to sensor status
int count = 0; //Counter to transmit message
int buttonPin = 8; //Button Pin
LiquidCrystal lcd( 12,11,6,5,4,3); //LCD pin


//setup output or input
void setup(){
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT); //Buzzer-output
  pinMode(led, OUTPUT); // LED - output
  pinMode(sensor, INPUT); // sensor - input
  pinMode(buttonPin, INPUT);
  lcd.begin (16,2); //Initialize the LCD. Size LCD
}


//The loop function runs forever. Main void.
void loop(){
  val = digitalRead(sensor);
  if(count == 0 && val == HIGH){
    message(); //Message ON
    digitalWrite(led, HIGH); // Turn LED ON
    buzzOn();
  }else if(count == 1){
    lcd.clear(); // Message OFF
    digitalWrite(led, LOW); // Turn LED OFF
    buzzOff();
  }
  // Counter to controll the the button
  if (digitalRead(buttonPin) == HIGH){
      count++;
      if(count > 1){
        count = 0;
      }
    }
  delay(300);
  Serial.println(count);
}


// BUZZER ON AND OFF
void buzzOn(){
  tone(buzzerPin, NOTE_A3,350);
  delay(350);
  tone(buzzerPin, NOTE_E4,350);
  delay(350);
}
void buzzOff(){
  noTone(buzzerPin);
}

// INTRUDE MESSAGE
void message(){
  lcd.clear();   
  lcd.setCursor(1,0);
  lcd.print("INTRUDER");
  delay(300);
}



















