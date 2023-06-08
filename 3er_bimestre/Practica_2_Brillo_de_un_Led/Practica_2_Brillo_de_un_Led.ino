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
#define PinPote A0
#define led 5

//variables globales
int pote;             //variable para guardar la lectura analogica del pote
int  brillo;          //variable para guardar el valor del brillo

void setup() {
  pinMode(PinPote, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  pote = analogRead(PinPote); //se guarda el valor de la medicion del potenciometro
  brillo = map(pote, 0, 1023, 0, 255);
  analogWrite(led, brillo);
}
