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
#define buz 10
#define Led1 2
#define Led2 3
#define Led3 4


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
  
  LCD_muniz.init(); //inicio la comunicacion serial con el modulo i2c
  LCD_muniz.backlight(); 

}

void loop() {
  valDistancia = sensor();
  secuencia();
  sensor ();
  
}
void secuencia(){
  if (valDistancia > 45) { 
      digitalWrite(Led1, LOW); 
      digitalWrite(Led2, LOW); 
      digitalWrite(Led3, LOW); 
      LCD_muniz.setCursor(0,0);    
      LCD_muniz.print("fuera            ");
      LCD_muniz.setCursor(0,1);    
      LCD_muniz.print("del alcance          ");
      }
  else if (valDistancia > 29 && valDistancia < 45) {
      digitalWrite(Led1, HIGH); 
      digitalWrite(Led2, LOW); 
      digitalWrite(Led3, LOW);       
      LCD_muniz.setCursor(0,0);    
      LCD_muniz.print("Persona            ");
      LCD_muniz.setCursor(0,1);    
      LCD_muniz.print("Acercandose       ");
      }
  else if (valDistancia > 14 && valDistancia < 30) { 
      digitalWrite(Led1, HIGH); 
      digitalWrite(Led2, HIGH); 
      digitalWrite(Led3, LOW);    
      LCD_muniz.setCursor(0,0);    
      LCD_muniz.print("Cuidado, espacio        ");
      LCD_muniz.setCursor(0,1);    
      LCD_muniz.print("Privado           ");
      digitalWrite(buz, HIGH); 
      delay(5000);
      digitalWrite(buz, LOW); 

      }
  else if (valDistancia <16) {
      digitalWrite(Led1, HIGH); 
      digitalWrite(Led2, HIGH); 
      digitalWrite(Led3, HIGH);     
      LCD_muniz.setCursor(0,0);    
      LCD_muniz.print("Invadiendo        ");
      LCD_muniz.setCursor(0,1);    
      LCD_muniz.print("Espacio Privado          ");
     digitalWrite(buz, HIGH); 
      delay(10000);
      digitalWrite(buz, LOW); 
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
   pinMode(buz, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);

}
