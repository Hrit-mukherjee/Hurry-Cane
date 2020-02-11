#include <SoftwareSerial.h>
#include <BlynkSimpleStream.h>

SoftwareSerial SwSerial(0, 1); // RX, TX

SoftwareSerial BTserial(0, 1);
int state = 0;
const int buttonPin = 2;  //the pin your button is connected to
int buttonState = 0;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "47-CO-_4Aml4r1X3k-fLNXeqskegViu4";

BlynkTimer timer;
String currentState, prevState;

SoftwareSerial SerialBLE(10, 11); // RX, TX
WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led3(V3);

void updateLED(){
  prevState=currentState;
 
  int state1 = digitalRead(2);
  if(state1==0){
    //Blynk.virtualWrite(V1, HIGH);
    led1.on();
    currentState="RED";
  } else {
    //Blynk.virtualWrite(V1, LOW);
    led1.off();
  }

  int state2 = digitalRead(3);
  if(state2==0){
    led2.on();
    currentState="YELLOW";
  } else {
    led2.off();
  }

  int state3 = digitalRead(4);
  if(state3==0){
    led3.on();
    currentState="GREEN";
  } else {
    led3.off();
  }

  if (currentState != prevState) {
    Blynk.email("debangee.das@gmail.com",
    "Subject: Traffic Notification",
    "The Signal is now" + currentState);

    Blynk.notify("The Signal is now" + currentState);
  }
}

void setup()
{
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(buttonPin, INPUT);

   
  // Debug console
  Serial.begin(9600);
  BTserial.begin(38400);
  SerialBLE.begin(9600);
  Blynk.begin(Serial, auth);

  // Setup a function to be called every second
  timer.setInterval(100L, updateLED);
}

void loop()
{
  Blynk.run();
  timer.run();

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    BTserial.write('1');  //sends a 1 through the bluetooth serial link
    Serial.println("1");
    delay (200);
  }

  /*else {
    BTserial.write('0');
    Serial.println("0");
    delay(200);
  }*/

}
