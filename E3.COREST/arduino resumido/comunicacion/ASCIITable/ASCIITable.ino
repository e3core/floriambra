/*
  abla ASCII

  Imprime valores de bytes en todos los formatos posibles:
  - como valores binarios sin procesar
  - como valores decimales, hexadecimales, octales y binarios codificados en ASCII

  
*/

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // espere a que se conecte el puerto serie. Necesario solo para puerto USB nativo
  }

  // imprime el título con salto de línea final
  Serial.println("ASCII Table ~ Character Map");
}

// primer carácter ASCII visible '!' es el número 33:
int thisByte = 33;
// también puede escribir caracteres ASCII entre comillas simples.
// por ejemplo, '!' es lo mismo que 33, así que también podrías usar esto:
// int thisByte = '!';

void loop() {
  // imprime el valor inalterado, es decir, la versión binaria sin procesar del byte.
  // El Serial Monitor interpreta todos los bytes como ASCII, por lo que 33, el primer número,
  // aparecerá como '!'
  Serial.write(thisByte);

  Serial.print(", dec: ");
  // imprime el valor como cadena como un decimal codificado en ASCII (base 10).
  // Decimal es el formato predeterminado para Serial.print() y Serial.println(),
  // por lo que no se necesita modificador:
  Serial.print(thisByte);
  // Pero puede declarar el modificador para decimal si lo desea.
  // esto también funciona si lo descomentas:

  // Serial.print(thisByte, DEC);


  Serial.print(", hex: ");
  // prints value as string in hexadecimal (base 16):
  Serial.print(thisByte, HEX);

  Serial.print(", oct: ");
  // prints value as string in octal (base 8);
  Serial.print(thisByte, OCT);

  Serial.print(", bin: ");
  // prints value as string in binary (base 2) also prints ending line break:
  Serial.println(thisByte, BIN);

  // if printed last visible character '~' or 126, stop:
  if (thisByte == 126) {  // you could also use if (thisByte == '~') {
    // This loop loops forever and does nothing
    while (true) {
      continue;
    }
  }
  // go on to the next character
  thisByte++;
}
