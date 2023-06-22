/*
  Calibración

  Demuestra una técnica para calibrar la entrada del sensor. Las lecturas del sensor
  durante los primeros cinco segundos de la ejecución del croquis definir el mínimo y
  máximo de los valores esperados adjuntos al pin del sensor.

  Los valores iniciales mínimo y máximo del sensor pueden parecer al revés. Inicialmente,
  establece el mínimo alto y escucha cualquier cosa más baja, guardándolo como el nuevo
  mínimo. Del mismo modo, establece el máximo bajo y escucha cualquier cosa más alta como
  el nuevo máximo.

  El circuito:
  - sensor analógico (el potenciómetro funcionará) conectado a la entrada analógica 0
  - LED conectado desde el pin digital 9 a tierra a través de una resistencia de 220 ohmios

  
*/

// These constants won't change:
const int sensorPin = A0;  // pin that the sensor is attached to
const int ledPin = 9;      // pin that the LED is attached to

// variables:
int sensorValue = 0;   // the sensor value
int sensorMin = 1023;  // minimum sensor value
int sensorMax = 0;     // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
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

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, sensorMin, sensorMax);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
}
