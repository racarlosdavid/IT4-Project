#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

long distanciaDeActivacion = 10; 
int RELAY_PIN = 10; //Pin al que esta conectado el relay

void setup() {
   pinMode(RELAY_PIN, OUTPUT); // pin 10 como salida 
   digitalWrite(RELAY_PIN, HIGH);  // RELAY_PIN a cero logico
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   
   if (a <= distanciaDeActivacion){
    Serial.println("despachar producto");
    despacharProducto(3000); //Si el sensor detecta un objeto a menos de 10 cm se activa
  }
   delay(1000);
}

void despacharProducto(int tiempo) {
  digitalWrite(RELAY_PIN, LOW); // RELAY_PIN a uno logico
  delay(tiempo); //Tiempo que voy a dejar la bomba encendida para que despache el producto
  digitalWrite(RELAY_PIN, HIGH);  // RELAY_PIN a cero logico
}
