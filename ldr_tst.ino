int ldr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10,OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
ldr = analogRead(5);
Serial.println(ldr);

if (ldr<10){
  digitalWrite(10, HIGH);
  delay(200);
} else {
  digitalWrite(10, LOW);
  delay(200);
}

}
