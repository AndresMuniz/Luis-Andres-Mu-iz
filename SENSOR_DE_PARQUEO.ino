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
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C


#define trig 8
#define eco 9

byte block[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
int valDistancia; 
int contador = 0; 

void salidas_entradas();
int sensor();
void secuencia();



#define direccion_lcd 0x27
#define filas 2
#define columnas 16
LiquidCrystal_I2C LCD_muniz(direccion_lcd, columnas, filas);


void setup() {
  salidas_entradas();
  LCD_muniz.createChar(0, block);
  LCD_muniz.init(); //inicio la comunicacion serial con el modulo i2c
  LCD_muniz.backlight(); 

}

void loop() {
  valDistancia = sensor();
  secuencia();
  sensor ();
  
}
void secuencia(){
  
  if (valDistancia > 51){
      LCD_muniz.setCursor(0,0);
      LCD_muniz.print("                ");
      LCD_muniz.setCursor(0,1);
      LCD_muniz.print("                "); 
      }  
  
  
  if (valDistancia > 49 && valDistancia < 51){ 
      LCD_muniz.setCursor(0,0);  
      LCD_muniz.write(0); 
      LCD_muniz.write(0);
      LCD_muniz.write(0);  
      LCD_muniz.print("    50    ");   
      LCD_muniz.write(0); 
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.setCursor(0,1); 
      LCD_muniz.print("     LIBRE      ");   
      }
  else if (valDistancia > 29 && valDistancia <31) {      
      LCD_muniz.setCursor(0,0);  
      LCD_muniz.write(0); 
      LCD_muniz.write(0);
      LCD_muniz.write(0);  
      LCD_muniz.write(0); 
      LCD_muniz.write(0); 
      LCD_muniz.print("  30  ");   
      LCD_muniz.write(0); 
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0); 
      LCD_muniz.write(0); 
      LCD_muniz.setCursor(0,1); 
      LCD_muniz.print("     CUIDADO     ");  
      }
  else if (valDistancia > 9 && valDistancia < 11) {     
      LCD_muniz.setCursor(0,0);  
      LCD_muniz.write(0); 
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);  
      LCD_muniz.print("10");   
      LCD_muniz.write(0); 
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.write(0);
      LCD_muniz.setCursor(0,1); 
      LCD_muniz.print("      ALTO      ");  
      }
}
int sensor (){
  int tiempo;
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(eco, HIGH);
  int distancia; 
  distancia = tiempo / 58.2;
  return distancia;
  }
void salidas_entradas(void){
   pinMode(trig, OUTPUT);
   pinMode(eco, INPUT);

}
