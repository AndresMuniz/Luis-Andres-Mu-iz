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
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C

#define hot 2
#define cold 3
#define normal 4

byte grado[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte termo[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B11011,
  B10001,
  B10001,
  B11111
};

int celsius;
int fahrenheit;

void salidas();
void secuencia();
int temperaturac();
int temperaturaf();

//Armador de lCD
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
LiquidCrystal_I2C LCD_muniz(direccion_lcd, columnas, filas);

//Constructores
OneWire ourWire(5);                //Se establece el pin 5  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensors(&ourWire);



void setup() {
  LCD_muniz.createChar(1,grado);
  LCD_muniz.createChar(2,termo);
  salidas();
  sensors.begin();  
  LCD_muniz.init(); //inicio la comunicacion serial con el modulo i2c
  LCD_muniz.backlight(); 

}

void loop() {
  fahrenheit = temperaturaf();
  celsius = temperaturac();
  
  LCD_muniz.setCursor(0,0);
  LCD_muniz.print("Termometro  ");
  LCD_muniz.write(2);
  LCD_muniz.setCursor(0,1);
  LCD_muniz.print(celsius);
  LCD_muniz.write(1);
  LCD_muniz.print("C ");
  LCD_muniz.print(fahrenheit);
  LCD_muniz.write(1);
  LCD_muniz.print("F");

  secuencia();
}
void salidas(){
  pinMode(normal, OUTPUT);
  pinMode(cold, OUTPUT);
  pinMode(hot, OUTPUT);
}
void secuencia(){
  
  if ( celsius> 30){
      digitalWrite (hot, HIGH);
      digitalWrite (cold, LOW);
      digitalWrite (normal, LOW);
      }  
  if ( celsius< 15){
      digitalWrite (hot, LOW);
      digitalWrite (cold, HIGH);
      digitalWrite (normal, LOW);
      } 
  if ( celsius< 30 && celsius> 15){
      digitalWrite (hot, LOW);
      digitalWrite (cold, LOW);
      digitalWrite (normal, HIGH);
      } 
      
}

int temperaturac(){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}
int temperaturaf(){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp1 = sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
  return temp1;
}
