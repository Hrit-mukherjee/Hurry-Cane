#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"

Talkie voice;

void setup() {
  pinMode(10,INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}
void loop() {
//    voice.say(spPAUSE2);
//    voice.say(sp2_DANGER);
//    voice.say(sp2_DANGER);
//    voice.say(sp3_STORM);
//    voice.say(sp3_IN);
//    voice.say(sp3_THE);
//    voice.say(sp3_NORTH);

    digitalWrite(10, HIGH);
    voice.say(sp2_ON);
    delay(500);
    digitalWrite(10, LOW);
    voice.say(sp2_OFF);
    delay(500);
    
}
