const int Trigger = 2;    // D2 en Nano para el Trigger del sensor
const int Echo = 3;       // D3 en Nano para el Echo del sensor
const int pinBuzzer = 9;  // D9 en Nano para el buzzer

void setup() {
  Serial.begin(9600);          // Inicializamos la comunicación
  pinMode(Trigger, OUTPUT);    // Pin como salida
  pinMode(Echo, INPUT);        // Pin como entrada
  pinMode(pinBuzzer, OUTPUT);  // Pin del buzzer como salida
  digitalWrite(Trigger, LOW);  // Inicializamos el pin con 0
}

void loop() {
  long t;  // Tiempo que demora en llegar el eco
  long d;  // Distancia en centímetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);  // Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);  // Obtenemos el ancho del pulso
  d = t / 59;               // Escalamos el tiempo a una distancia en cm

  Serial.print("Distancia: ");
  Serial.print(d);  // Enviamos serialmente el valor de la distancia
  Serial.print(" cm");
  Serial.println();
  delay(100);  // Hacemos una pausa de 100 ms

  if (d < 30) {
    digitalWrite(pinBuzzer, HIGH);  // Encender buzzer
  } else {
    digitalWrite(pinBuzzer, LOW);  // Apagar buzzer
  }
}
