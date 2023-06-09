
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
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C

//Directivas de preprocesador
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define volt A0

//variables globales
float resultado;
float vout;
float numerador;
float denominador;
float volt_bruto;

LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);

void setup() {
  lcd.init(); //inicio la comunicacion serial con el modulo i2c
  lcd.backlight(); //Enciendo la luz de fondo para poder ver el texto
  pinMode(volt, INPUT);
}

void loop() {
  volt_bruto = analogRead(volt);
  vout = (volt_bruto*5)/1023;
  numerador = (-vout)*(1000);
  denominador = vout-5;
  resultado = numerador/denominador;
  
  lcd.setCursor(0,0);
  lcd.write("   OHMNIMETRO   ");
  lcd.setCursor(4,1);
  lcd.write(resultado);
  lcd.write("Ohms    ");

}
