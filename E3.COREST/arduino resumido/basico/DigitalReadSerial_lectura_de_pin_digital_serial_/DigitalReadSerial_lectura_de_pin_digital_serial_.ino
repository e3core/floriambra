/*
  DigitalReadSerial

   Lee una entrada digital en el pin 2, imprime el resultado en el monitor serie

   Este código de ejemplo es de dominio público.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial
*/


int pushButton = 2;


void setup() {

  Serial.begin(9600);

  pinMode(pushButton, INPUT);
}


void loop() {

  int buttonState = digitalRead(pushButton);

  Serial.println(buttonState);
  delay(1000);        
}
