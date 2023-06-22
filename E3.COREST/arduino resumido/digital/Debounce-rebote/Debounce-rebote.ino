/*
  
  rebote

   Cada vez que el pin de entrada pasa de BAJO a ALTO (por ejemplo, debido a un botón
   presione), el pin de salida cambia de BAJO a ALTO o de ALTO a BAJO. Hay una
   retardo mínimo entre alterna para eliminar el rebote del circuito (es decir, para ignorar el ruido).

   El circuito:
   - LED conectado desde el pin 13 a tierra a través de una resistencia de 220 ohmios
   - pulsador conectado desde el pin 2 a +5V
   - Resistencia de 10 kilohm conectada desde el pin 2 a tierra
*/


const int buttonPin = 2;  
const int ledPin = 13;   


int ledState = HIGH;        
int buttonState;            
int lastButtonState = LOW;  


unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

 
  digitalWrite(ledPin, ledState);
}

void loop() {
  
  int reading = digitalRead(buttonPin);

 
  if (reading != lastButtonState) {
    
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;

      
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  digitalWrite(ledPin, ledState);

  
  lastButtonState = reading;
}
