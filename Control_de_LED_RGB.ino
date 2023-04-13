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
#define in(pin) pinMode (pin, INPUT)
#define out(pin) pinMode (pin, OUTPUT)
#define on(pin) digitalWrite (pin, HIGH)
#define off(pin) digitalWrite (pin, LOW)
#define b1 2
#define b2 3
#define r 4 
#define v 5
#define a 6

void setup() {
  in (b1);
  in (b2);
  out (a);
  out (v);
  out (r);
}

void loop() {
  int bt1; 
  bt1 = digitalRead (b1);
  int bt2; 
  bt2 = digitalRead (b2);


if (bt1 == HIGH && bt2 == LOW) {
    off(a);
    on(r);
    on (v);
    }
if (bt2 == HIGH && bt1 == LOW) {
    on(a);
    on (v);
    off(r);
    }
if (bt1 == HIGH && bt2 == HIGH){
  off(v);
  on(a);
  on (r);
  
}
if (bt1 == LOW && bt2 == LOW){
  on(r); 
  delay (500);
  off(r); on(v); 
  delay (500);
  off(v); on(a); 
  delay (500);
  off(a); 
}
}
