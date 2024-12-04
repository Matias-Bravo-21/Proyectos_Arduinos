#include <ESP8266WiFi.h>

const char* ssid = "Luna"; // Nombre de la red
const char* password = "luna111923"; // Contraseña

void setup() {
  Serial.begin(9600);
  
  // Configura el ESP8266 como punto de acceso
  WiFi.softAP(ssid, password);

  Serial.println("Punto de acceso configurado");
  Serial.print("IP de acceso: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Aquí puedes añadir más lógica si es necesario
}
