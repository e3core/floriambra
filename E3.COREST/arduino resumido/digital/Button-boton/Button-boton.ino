/*
  
 Botón

   Enciende y apaga un diodo emisor de luz (LED) conectado al pin digital 13,
   al presionar un botón conectado al pin 2.

   El circuito:
   - LED conectado desde el pin 13 a tierra a través de una resistencia de 220 ohmios
   - pulsador unido al pin 2 desde +5V
   - Resistencia de 10K conectada al pin 2 desde tierra

   - Nota: en la mayoría de los Arduinos ya hay un LED en la placa
     unido al pin 13.
*/


const int buttonPin = 2;  
const int ledPin = 13;    


int buttonState = 0;  

void setup() {
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
}

void loop() {
 
  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    
    digitalWrite(ledPin, HIGH);
  } else {
    
    digitalWrite(ledPin, LOW);
  }
}
