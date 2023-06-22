/*
  Parpadear

   Enciende un LED durante un segundo, luego lo apaga durante un segundo, repetidamente.

   La mayoría de los Arduinos tienen un LED incorporado que puedes controlar. En el UNO, MEGA y CERO
   está conectado al pin digital 13, en MKR1000 en el pin 6. LED_BUILTIN está configurado para
   el pin LED correcto independientemente de la placa que se utilice.
   Si desea saber a qué pin está conectado el LED integrado en su Arduino
   modelo, consulta las Especificaciones Técnicas de tu placa en:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

//este led es el de la placa
void setup() {
 
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1000);                      
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1000);                      
}
