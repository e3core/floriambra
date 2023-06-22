/*
 Condicionales - Si declaración

  Este ejemplo demuestra el uso de sentencias if().
  Lee el estado de un potenciómetro (una entrada analógica) y enciende un LED
  solo si el potenciómetro supera un cierto nivel de umbral. Imprime el
  valor analógico independientemente del nivel.

  El circuito:
  - potenciómetro
    El pin central del potenciómetro va al pin analógico 0.
    Los pines laterales del potenciómetro van a +5V y tierra.
  - LED conectado desde el pin digital 13 a tierra a través de una resistencia de 220 ohmios

  - Nota: En la mayoría de las placas Arduino, ya hay un LED conectado en la placa
    al pin 13, por lo que no necesita ningún componente adicional para este ejemplo. 

  
*/

// These constants won't change:
const int analogPin = A0;   // pin that the sensor is attached to
const int ledPin = 13;      // pin that the LED is attached to
const int threshold = 400;  // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
  if (analogValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);  // delay in between reads for stability
}
