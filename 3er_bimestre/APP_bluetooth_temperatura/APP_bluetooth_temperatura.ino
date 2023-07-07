/*
Fundacion Kinal
Centro Educativo Tecnico Laboral Kinal
Electronica
Grado: Quinto
Seccion: A
Curso: Taller de electronica digital y reparacion de computadoras 1
Nombre: Luis Andres Muñiz Godoy
Carne: 2019127
*/
#include <Ticker.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ledPin 3 
#define Temperatura 4

void isr_temp();
Ticker isr_accion_temp(isr_temp, 10000);

SoftwareSerial bluetooth(10, 11); 
OneWire oneWire(Temperatura);
DallasTemperature sensors(&oneWire);


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
  bluetooth.begin(9600); 
  sensors.begin();
  isr_accion_temp.start();
}

void loop() {
  if (bluetooth.available()) { 
    char infoblue = bluetooth.read(); 

    if (infoblue == '2') { 
      encenderLed(); 
    } else if (infoblue == '1') { 
      apagarLed(); 
    }
  }
  isr_accion_temp.update();
 
}

void isr_temp(){
  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);

  bluetooth.print(temperatura);
  bluetooth.println("°C");

}

void encenderLed() {
  digitalWrite(ledPin, HIGH); 
}

void apagarLed() {
  digitalWrite(ledPin, LOW); 
}
