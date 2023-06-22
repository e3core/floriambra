/*
  AnalogReadSerial

   Lee una entrada analógica en el pin 0, imprime el resultado en el monitor serie.
   La representación gráfica está disponible usando Serial Plotter (menú Herramientas > Serial Plotter).
   Conecte el pin central de un potenciómetro al pin A0 y los pines exteriores a +5V y tierra.

   Este código de ejemplo es de dominio público.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/


void setup() {

  Serial.begin(9600);
}


void loop() {

  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
  delay(500);       
}
