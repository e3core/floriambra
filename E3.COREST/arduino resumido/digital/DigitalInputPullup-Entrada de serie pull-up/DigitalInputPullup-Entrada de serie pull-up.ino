/*
  
  Entrada de serie pull-up

   Este ejemplo demuestra el uso de pinMode(INPUT_PULLUP). Lee un digital
   entrada en el pin 2 e imprime los resultados en el monitor serie.

   El circuito:
   - interruptor momentáneo conectado desde el pin 2 a tierra
   - LED incorporado en el pin 13

   A diferencia de pinMode (INPUT), no se necesita una resistencia desplegable. Un interno
   La resistencia de 20K-ohm se lleva a 5V. Esta configuración hace que la entrada lea
   ALTO cuando el interruptor está abierto y BAJO cuando está cerrado.
*/

void setup() {

  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  
  int sensorVal = digitalRead(2);
  
  Serial.println(sensorVal);

  
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
