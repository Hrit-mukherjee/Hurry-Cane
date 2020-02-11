#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1);

int state = 0;

void setup() {
  // initialize digital pin 8 as an output.

  Serial.begin(38400);
  BTserial.begin(38400);

  pinMode(8, OUTPUT);

}

void loop() {

  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    state = BTserial.read(); // Reads the data from the serial port
  }
  Serial.println(state);
  delay(100);
  // Controlling the LED
  if (state == 128) {
    digitalWrite(8, HIGH); // LED ON
    state = 0;
  }
  else if (state == 0) {
    digitalWrite(8, LOW); // LED ON
    state = 0;
  }
  //digitalWrite(8,HIGH);
}
