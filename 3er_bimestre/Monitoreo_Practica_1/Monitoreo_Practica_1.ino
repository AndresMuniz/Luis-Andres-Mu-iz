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

//Librerias
#include <Ticker.h>            //esta libreria me permite hacer uso del timer
#include <OneWire.h>                
#include <DallasTemperature.h>

//Directivas de preprocesador
#define boton 2  


//Funciones de ISR
void funcion_boton(void);
void funcion_sensors(); 

//Variables
volatile static bool estado_boton;

//Constructores sensor de temperatura
OneWire ourWire(3);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

//Constructores Ticker
Ticker accion_boton(funcion_boton, 2000); //cada 6 segundos se comprobara el estado del boton
Ticker accion_sensors(funcion_sensors, 2000); //cada 6 segundos se comprobara el estado del boton


void setup() {
  Serial.begin(19200);  //Inicio la comunicación serial
  Serial.println("Iniciamos monitoreo");
  sensors.begin();
  pinMode(boton, INPUT);
  accion_boton.start();   //Iniciando la interrupción que esperaria se repitiera cada 6 segundos
  estado_boton=LOW;
  accion_sensors.start();   //Iniciando la interrupción que esperaria se repitiera cada 6 segundos
}

void loop() {

  accion_boton.update();
  accion_sensors.update();

}

void funcion_boton(void)
{
  estado_boton = digitalRead(boton); //leo el estado digital
  if(estado_boton==HIGH){                     //imprimo cuando esta precionado del boton 
    Serial.println("Boton precionado");
  }
  if(estado_boton==LOW) {                     //imprimo cuando esta precionado del boton 
    Serial.println("Boton no precionado");
  }
}

void funcion_sensors (){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float tempC= sensors.getTempCByIndex(0); //se obtiene la temperatura en celsius
  Serial.println(" ");
  Serial.print ("Temperatura: "); 
  Serial.print (tempC);
  Serial.println ("C"); 
}
