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

#include <Keypad.h>
#define out(pin) pinMode (pin, OUTPUT)
#define off(pin) digitalWrite (pin, LOW)
#define on(pin) digitalWrite (pin, HIGH)

#define f1 2 //defino los pines que voy a usar
#define f2 3 
#define f3 4 
#define f4 5 
#define c1 6
#define c2 7 
#define c3 8 
#define c4 9 
#define a 10 
#define b 11 
#define c 12 
#define d 13 
#define e 14 
#define f 15 
#define g 16 

const byte filas = 4; //numero de filas
const byte columnas = 4;// numero de columnas
 
char boton[filas][columnas] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte pinfilas[filas] = { 2, 3, 4, 5 };
const byte pincolumnas[columnas] = { 6, 7, 8, 9 };
 
Keypad matriz = Keypad(makeKeymap(boton), pinfilas, pincolumnas, filas, columnas);
 
void setup() {
  out(a);out(b);
  out(c);out(d);
  out(e);out(f);
  out(g);
}
 
void loop() {
   char tecla = matriz.getKey();
 
   if (tecla == 'A') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(c);
    on(e);
    on(f);
    on(g);
   }
   if (tecla == 'B') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(c);
    on(d);
    on(e);
    on(f);
    on(g);
    tecla = 0;
    
   }
   if (tecla == 'C') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(g);
    on(e);
    on(d);
   }
   if (tecla == 'D') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(b);
    on(c);
    on(d);
    on(e);
    on(g);
   }
   if (tecla == '#') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(f);
    on(g);
    on(e);
    on(d);
   }
   if (tecla == '*') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(f);
    on(g);
    on(e);
   }
   if (tecla == '1') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(b);
    on(c);
   }
   if (tecla == '2') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(g);
    on(e);
    on(d);
   }
   if (tecla == '3') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(g);
    on(c);
    on(d);
   }
   if (tecla == '4') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g); 
    
    on(f);
    on(g);
    on(b);
    on(c);
   }
   if (tecla == '5') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(f);
    on(g);
    on(c);
    on(d);
   }
   if (tecla == '6') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(f);
    on(g);
    on(c);
    on(d);
    on(e);
   }
   if (tecla == '7') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(c);
   }
   if (tecla == '8') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(c);
    on(d);
    on(e);
    on(f);
    on(g);
   }
   if (tecla == '9') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(c);
    on(g);
    on(f);
   }
   if (tecla == '0') {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(c);
    on(e);
    on(f);
    on(d);
   }
 
 if (NO_KEY) {
    off(a);
    off(b);
    off(c);
    off(d);
    off(e);
    off(f);
    off(g);
    
    on(a);
    on(b);
    on(c);
    on(d);
    on(e);
    on(f);
   }

   }
