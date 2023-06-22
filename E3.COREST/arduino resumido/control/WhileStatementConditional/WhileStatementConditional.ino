/*
 Condicionales - instrucción while

  Este ejemplo demuestra el uso de sentencias while().

  Mientras se presiona el botón, el croquis ejecuta la rutina de calibración.
  Las lecturas del sensor durante el bucle while definen el mínimo y el máximo de
  valores esperados de la fotorresistencia.

  Esta es una variación del ejemplo de calibración.

  El circuito:
  - fotorresistencia conectada de +5V a analógico en pin 0
  - Resistencia de 10 kilohm conectada de tierra a analógico en el pin 0
  - LED conectado desde el pin digital 9 a tierra a través de una resistencia de 220 ohmios
  - pulsador conectado desde el pin 2 a +5V
  - Resistencia de 10 kilohm conectada desde el pin 2 a tierra 

  
*/


// These constants won't change:
const int sensorPin = A0;        // pin that the sensor is attached to
const int ledPin = 9;            // pin that the LED is attached to
const int indicatorLedPin = 13;  // pin that the built-in LED is attached to
const int buttonPin = 2;         // pin that the button is attached to


// These variables will change:
int sensorMin = 1023;  // minimum sensor value
int sensorMax = 0;     // maximum sensor value
int sensorValue = 0;   // the sensor value


void setup() {
  // set the LED pins as outputs and the switch pin as input:
  pinMode(indicatorLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // while the button is pressed, take calibration readings:
  while (digitalRead(buttonPin) == HIGH) {
    calibrate();
  }
  // signal the end of the calibration period
  digitalWrite(indicatorLedPin, LOW);

  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
}

void calibrate() {
  // turn on the indicator LED to indicate that calibration is happening:
  digitalWrite(indicatorLedPin, HIGH);
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // record the maximum sensor value
  if (sensorValue > sensorMax) {
    sensorMax = sensorValue;
  }

  // record the minimum sensor value
  if (sensorValue < sensorMin) {
    sensorMin = sensorValue;
  }
}
