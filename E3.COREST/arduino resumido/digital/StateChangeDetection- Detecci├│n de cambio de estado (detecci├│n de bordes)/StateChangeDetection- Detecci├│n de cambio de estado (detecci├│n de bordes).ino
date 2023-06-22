/*
  Detección de cambio de estado (detección de bordes)

   A menudo, no necesita saber el estado de una entrada digital todo el tiempo, pero
   solo necesita saber cuándo la entrada cambia de un estado a otro.
   Por ejemplo, desea saber cuándo un botón pasa de APAGADO a ENCENDIDO. Se llama
   detección de cambio de estado o detección de bordes.

   Este ejemplo muestra cómo detectar cuando un botón o botón cambia de apagado a encendido
   y de encendido a apagado.

   El circuito:
   - pulsador unido al pin 2 desde +5V
   - Resistencia de 10 kilohm conectada al pin 2 desde tierra
   - LED conectado desde el pin 13 a tierra a través de una resistencia de 220 ohmios (o use el
     LED integrado en la mayoría de las placas Arduino)
 


*/ 


const int buttonPin = 2;  
const int ledPin = 13;    


int buttonPushCounter = 0;  
int buttonState = 0;       
int lastButtonState = 0;   

void setup() {
 
  pinMode(buttonPin, INPUT);
  
  pinMode(ledPin, OUTPUT);
 
  Serial.begin(9600);
}


void loop() {
  
  buttonState = digitalRead(buttonPin);

 
  if (buttonState != lastButtonState) {
    
    if (buttonState == HIGH) {
      
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
     
      Serial.println("off");
    }
    
    delay(50);
  }
  
  lastButtonState = buttonState;


  
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
