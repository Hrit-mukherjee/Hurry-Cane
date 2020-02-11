#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"
#include <SoftwareSerial.h>
#include <SPI.h>

SoftwareSerial BTserial(0, 1);

Talkie voice;

int duration, distance, ldr, val, state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT); //trigPin
  pinMode(6,INPUT); //echoPin
  pinMode(5,OUTPUT);//led
  pinMode(8,INPUT);//water
  //pinMode(7,INPUT);//pir
  pinMode(11,OUTPUT);//tx-rx
  Serial.begin(38400);
  BTserial.begin(38400); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Start of Loop!");
  //tx-rx
  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    state = BTserial.read(); // Reads the data from the serial port
  }
  Serial.println(state);
  delay(100);
  // Controlling the buzzer
  if (state == 128) {
    digitalWrite(11, HIGH); // Buzzer ON
    state = 0;
  }
  else if (state == 0) {
    digitalWrite(11, LOW); // Buzzer OFF
    state = 0;
  }
//Obstacle Detection
   long duration, inches, cm;
   
   digitalWrite(7, LOW);
   delayMicroseconds(2);
   digitalWrite(7, HIGH);
   delayMicroseconds(10);
   digitalWrite(7, LOW);
   
   duration = pulseIn(6, HIGH);
   cm = microsecondsToCentimeters(duration);
   if (cm<50)
   {
    Serial.print("Obstacle Detected : ");
    Serial.print(cm);
    Serial.print("cm");
    voice.say(sp2_DANGER);
    voice.say(sp2_DANGER);
   }
   Serial.println();
   delay(500);

//Water Detection
  int h20=digitalRead(8);
  Serial.println(h20);
  if(h20>0){
  voice.say(sp2_CAUTION);
  voice.say(sp2_CAUTION);
  }
  //delay(500);

 //Glow in the dark
  ldr = analogRead(4);
  Serial.println(ldr);

  if (ldr<250){
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
}
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
