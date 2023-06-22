/*
  
  Parpadeo sin demora

   Enciende y apaga un diodo emisor de luz (LED) conectado a un pin digital,
   sin utilizar la función delay(). Esto significa que otro código puede ejecutarse en el
   mismo tiempo sin ser interrumpido por el código LED.

   El circuito:
   - Utilice el LED integrado.
   - Nota: la mayoría de los Arduinos tienen un LED integrado que puedes controlar. En la ONU, MEGA
     y CERO está conectado al pin digital 13, en MKR1000 en el pin 6. LED_BUILTIN
     está configurado en el pin LED correcto independientemente de la placa que se utilice.
     Si desea saber a qué pin está conectado el LED integrado en su
     Modelo Arduino, consulta las Especificaciones Técnicas de tu placa en:
*/


const int ledPin = 2; 

int ledState = LOW;  


unsigned long previousMillis = 0;  


const long interval = 1000;  

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  unsigned long currentMillis = millis();
Serial.println(previousMillis);
  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;

  
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    
    digitalWrite(ledPin, ledState);
  }
}
