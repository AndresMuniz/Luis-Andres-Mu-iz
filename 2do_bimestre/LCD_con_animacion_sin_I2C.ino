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
#include <LiquidCrystal.h>

#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define RS  6
#define E 7
#define trig 8
#define eco 9
#define buz 10


int c=261; 
int d=294;
int sensor();
void secuencia();
int valDistancia; 
int contador = 0; 
LiquidCrystal LCD_muniz(RS, E, D4, D5, D6, D7);


byte dobcorchea[] = {    //caracter de doble corchea
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

byte corchea[] = {
  B00100,
  B00110,
  B00101,
  B00100,
  B00100,
  B01100,
  B01100,
  B00000
};

byte persona_uno[] = {
B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010
};

byte persona_dos[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(eco, INPUT);
  LCD_muniz.createChar(1,dobcorchea);
  LCD_muniz.createChar(2,corchea);
  LCD_muniz.createChar(3,persona_uno);
  LCD_muniz.createChar(4,persona_dos);
  LCD_muniz.begin(16,2);

}

void loop() {
  valDistancia = sensor();
  secuencia();
  sensor ();
  
}
void secuencia(){
  if(valDistancia > 5 && valDistancia < 10 && contador < 16){
    contador = contador + 1;
    delay(300);
  }
 switch (contador){
  case 0:
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 0 ");  
  break;
  
  case 1:
  LCD_muniz.setCursor(0,0);    
  LCD_muniz.write(1);
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 1 "); 
  
  break;
 
  case 2: 
    LCD_muniz.setCursor(1,0);    
  LCD_muniz.write(1);
   LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 2 "); 
   
  break;

   case 3: 
  LCD_muniz.setCursor(2,0);    
  LCD_muniz.write(1);
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 3 ");
   
  break;

   case 4: 
  LCD_muniz.setCursor(3,0);    
  LCD_muniz.write(1);
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 4 "); 
  
  break;

   case 5: 
  LCD_muniz.setCursor(4,0);    
  LCD_muniz.write(1);  
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 5 "); 
 
  break;
   case 6: 
LCD_muniz.setCursor(5,0);    
  LCD_muniz.write(1);  
 LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 6 "); 
   
  break;
   case 7: 
LCD_muniz.setCursor(6,0);    
  LCD_muniz.write(1);  
 LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 7 "); 
   
  break;
   case 8: 
LCD_muniz.setCursor(7,0);    
  LCD_muniz.write(1); 
 LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 8 "); 
   
    break;
   case 9: 
LCD_muniz.setCursor(8,0);    
  LCD_muniz.write(1); 
   LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 9 "); 
  
  break;

   case 10: 
LCD_muniz.setCursor(9,0);    
  LCD_muniz.write(1); 
   LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 10 ");
    
  break;

   case 11: 
  LCD_muniz.setCursor(10,0);    
  LCD_muniz.write(1); 
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 11 "); 
   
  break;

   case 12: 
  LCD_muniz.setCursor(11,0);    
  LCD_muniz.write(1);  
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 12 "); 
   
  break;

   case 13: 
  LCD_muniz.setCursor(12,0);    
  LCD_muniz.write(1); 
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 13 "); 
   
  break;

   case 14: 
  LCD_muniz.setCursor(13,0);    
  LCD_muniz.write(1); 
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 14 "); 
  
  break;

   case 15: 
  LCD_muniz.setCursor(14,0);    
  LCD_muniz.write(1); 
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 15 ");
   
  break;

   case 16:
  LCD_muniz.clear();
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 16 "); 
  LCD_muniz.setCursor(14,1);  
  LCD_muniz.write(3);
  LCD_muniz.setCursor(0,0);  
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  LCD_muniz.write(2);
  tone(buz, d,500);
  delay(250);
  LCD_muniz.clear();
  LCD_muniz.setCursor(0,1);    
  LCD_muniz.write("Personas: 16 "); 
  LCD_muniz.setCursor(14,1);  
  LCD_muniz.write(4);
  LCD_muniz.setCursor(0,0);  
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
  LCD_muniz.write(1); 
    tone(buz, c,500);
  delay(250);
  break;
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
