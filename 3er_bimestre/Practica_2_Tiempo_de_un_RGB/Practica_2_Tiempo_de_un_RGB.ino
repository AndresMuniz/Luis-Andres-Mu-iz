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
#define red A2
#define green A3
#define blue A4

//funciones
int valor_tiempo();

//variables globales
int  tiempo;          //variable para guardar el valor del tiempo

void setup() {
  pinMode(PinPote, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
}

void loop() {
  valor_tiempo();
  tiempo=valor_tiempo();
  analogWrite(red, 174);
  analogWrite(green, 92);
  analogWrite(blue, 230);
  delay(tiempo);
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(tiempo);
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(tiempo);
  analogWrite(red, 189);
  analogWrite(green, 174);
  analogWrite(blue, 20);
  delay(tiempo);
  analogWrite(red, 225);
  analogWrite(green, 87);
  analogWrite(blue, 35);
  delay(tiempo);
}

int valor_tiempo(){
  int pote;
  int valtiempo;
  pote = analogRead(PinPote); //se guarda el valor de la medicion del potenciometro
  valtiempo = map(pote, 0, 1023, 100, 1000);
  return (valtiempo);
}
