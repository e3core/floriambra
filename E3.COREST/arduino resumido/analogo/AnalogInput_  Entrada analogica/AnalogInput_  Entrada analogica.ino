/*
  Entrada analogica

  Demuestra la entrada analógica leyendo un sensor analógico en el pin analógico 0 y
  encender y apagar un diodo emisor de luz (LED) conectado al pin digital 13.
  El tiempo que el LED estará encendido y apagado depende del valor obtenido
  por analogRead().

  El circuito:
  - potenciómetro
    pin central del potenciómetro a la entrada analógica 0
    un pin lateral (cualquiera de los dos) a tierra
    el otro pin lateral a +5V
  - CONDUJO
    ánodo (pata larga) conectado a la salida digital Resistencia de 13 a 220 ohmios
    cátodo (pata corta) conectado a tierra


   
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
