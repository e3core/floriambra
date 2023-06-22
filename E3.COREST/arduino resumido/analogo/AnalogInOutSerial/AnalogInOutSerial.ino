/*
  Entrada analógica, salida analógica, salida serie

   Lee un pin de entrada analógica, asigna el resultado a un rango de 0 a 255 y usa
   el resultado para establecer la modulación de ancho de pulso (PWM) de un pin de salida.
   También imprime los resultados en el monitor serie.

   El circuito:
   - potenciómetro conectado al pin analógico 0.
     El pin central del potenciómetro va al pin analógico.
     los pines laterales del potenciómetro van a +5V y tierra
   - LED conectado desde el pin digital 9 a tierra a través de una resistencia de 220 ohmios
*/


const int analogInPin = A0;  
const int analogOutPin = 9;  

int sensorValue = 0; 
int outputValue = 0;  

void setup() {
 
  Serial.begin(9600);
}

void loop() {
 
  sensorValue = analogRead(analogInPin);
 
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  analogWrite(analogOutPin, outputValue);

  
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  
  delay(20);
}
