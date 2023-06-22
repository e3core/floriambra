/*
  Teclado

   Reproduce un tono que cambia según una entrada analógica cambiante

   circuito:
   - tres resistencias de detección de fuerza de +5 V a analógico en 0 a 5
   - tres resistencias de 10 kilohm de entrada analógica 0 a 5 a tierra
   - Altavoz de 8 ohmios en pin digital 8

  
*/

#include "pitches.h"

const int threshold = 10;  


int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
};

void setup() {
}

void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    
    int sensorReading = analogRead(thisSensor);

    
    if (sensorReading > threshold) {
     
      tone(8, notes[thisSensor], 20);
    }
  }
}
