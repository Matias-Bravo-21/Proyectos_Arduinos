#include <Servo.h>

int sensorPin = 2;  // Pin donde está conectado el sensor IR
int sensorState = 0; // Variable para almacenar el estado del sensor

Servo miServo;  // Crear un objeto Servo

void setup() {
  miServo.attach(9);  // Conectar el servomotor al pin 9
  pinMode(sensorPin, INPUT);  // Configurar el pin del sensor IR como entrada
  miServo.write(0);  // Inicializar el servomotor en posición cerrada (0 grados)
}

void loop() {
  sensorState = digitalRead(sensorPin);  // Leer el estado del sensor

  if (sensorState == HIGH) {  // Si el sensor detecta un vehículo (sensor activado)
    miServo.write(90);  // Mover el servomotor a 90 grados (abrir el portón)
  } else {
    miServo.write(0);  // Mover el servomotor a 0 grados (cerrar el portón)
  }
  
  delay(100);  // Retardo corto para evitar lecturas erróneas
}
