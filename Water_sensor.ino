void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}
void loop() {
int h20=digitalRead(8);
Serial.println(h20);
if(h20>0)
digitalWrite(10,HIGH);
else
digitalWrite(10,LOW);
//delay(1000);   
  // put your main code here, to run repeatedly:
}
