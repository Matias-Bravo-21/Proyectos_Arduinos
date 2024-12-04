//incluimos la libreria del servomotor
#include <Servo.h>

// Definición del pin al que está conectado el sensor analógico
const int analogInPin = A0;
int sensorValue = 0;
Servo elbrigido;

// funcion para mover el servomotor 90 grados
void funcionelBrigido() {
  elbrigido.write(90);
}

void setup() {
  // configuramos los pines como salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  // iniciamos la comunicación serial
  Serial.begin(9600);
  //decimos que el servomotor esta en el pin "s3"
  elbrigido.attach(3);
}

void loop() {
  // almacenamos la informacion del sensor
  sensorValue = analogRead(analogInPin);

  // imprimimos en el monitor la informacion que reciba
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(2);
  // condicionales de ejecucion
  if (sensorValue >= 100) {
    // encendemos la luz de deteccion
    digitalWrite(2, HIGH);
    //espera 2 segundoss
    delay(2000);
    // alertamos con el buzzer
    digitalWrite(5, HIGH);
    //esperamos 2 segundos
    delay(2000);
    //ejecutamos la funcion
    funcionelBrigido();
    //apagamos el buzzer y la luz
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
  } else {
    // Apagar luces y mover el servo a -90 grados
    digitalWrite(5, LOW);
    elbrigido.write(-90);
  }
}
