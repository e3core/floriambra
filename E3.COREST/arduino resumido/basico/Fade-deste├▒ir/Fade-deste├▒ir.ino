/*
Desteñir

   Este ejemplo muestra cómo atenuar un LED en el pin 9 usando analogWrite()
   función.

   La función analogWrite() usa PWM, por lo que si desea cambiar el pin, debe
   usando, asegúrese de usar otro pin compatible con PWM. En la mayoría de Arduino, los pines PWM
   se identifican con un signo "~", como ~3, ~5, ~6, ~9, ~10 y ~11.

   Este código de ejemplo es de dominio público.  

 
*/

int led = 9;         
int brightness = 0;  
int fadeAmount = 5;  


void setup() {
 
  pinMode(led, OUTPUT);
}


void loop() {
  
  analogWrite(led, brightness);

  
  brightness = brightness + fadeAmount;

  
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
