/*
 Declaración de cambio

  Demuestra el uso de una sentencia switch. La instrucción switch le permite
  para elegir entre un conjunto de valores discretos de una variable. es como un
  serie de sentencias if.

  Para ver este boceto en acción, coloque la placa y el sensor en una habitación bien iluminada,
  abra el monitor serie y mueva su mano gradualmente hacia abajo sobre el sensor.

  El circuito:
  - fotorresistencia de analógico en 0 a +5V
  - Resistencia de 10K de entrada analógica 0 a tierra 
  
*/

// these constants won't change. They are the lowest and highest readings you
// get from your sensor:
const int sensorMin = 0;    // sensor minimum, discovered through experiment
const int sensorMax = 600;  // sensor maximum, discovered through experiment

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(A0);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // do something different depending on the range value:
  switch (range) {
    case 0:  // your hand is on the sensor
      Serial.println("dark");
      break;
    case 1:  // your hand is close to the sensor
      Serial.println("dim");
      break;
    case 2:  // your hand is a few inches from the sensor
      Serial.println("medium");
      break;
    case 3:  // your hand is nowhere near the sensor
      Serial.println("bright");
      break;
  }
  delay(1);  // delay in between reads for stability
}
