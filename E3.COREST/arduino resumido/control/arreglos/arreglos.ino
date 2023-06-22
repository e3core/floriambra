/*
  arreglos

  Demuestra el uso de una matriz para contener números pin con el fin de iterar sobre
  los pines en una secuencia. Enciende múltiples LED en secuencia, luego en reversa.

  A diferencia del tutorial For Loop, donde los pines tienen que ser contiguos, aquí el
  los pines pueden estar en cualquier orden aleatorio.

  El circuito:
  - LED de los pines 2 a 7 a tierra

*/

int timer = 100;  // The higher the number, the slower the timing.
int ledPins[] = {
  2, 7, 4, 6, 5, 3
};                 // an array of pin numbers to which LEDs are attached
int pinCount = 6;  // the number of pins (i.e. the length of the array)

void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }

  // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
}
