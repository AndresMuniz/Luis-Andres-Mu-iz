/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Luis Andres Muniz Godoy
Carné: 2019127
*/

#define out(pin) pinMode (pin, OUTPUT)
#define on(pin) digitalWrite (pin, HIGH)
#define off(pin) digitalWrite (pin, LOW)
#define l1 2
#define l2 3
#define l3 4
#define l4 5
#define l5 6
#define l6 7
#define l7 8
#define l8 9
#define l9 10
#define l10 11

void setup() {
out(l1); out(l2);
out(l3); out(l4);
out(l5); out(l6);
out(l7); out(l8);
out(l9); out(l10);
}

void loop() {
  int a; a = 2;
  while (a<=11){
    on(a);
    delay (50);
    off(a);
    a++;
    }
    while (a>=2){
    on(a);
    delay (50);
    off(a);
    a--;
    }
  }
