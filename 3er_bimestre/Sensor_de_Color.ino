/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
 * Nombre: Luis Andres Muñiz Godoy
*/
#include <Servo.h>
#define n1 2
#define n2 3
#define n3 4
#define n4 5
#define infrarojo A0
#define servos 6
#define ch_LDR A1
#define red 7
#define green 8 
#define blue 9

Servo myservo;

//Variables
int resultado_rojo, resultado_verde, resultado_azul, resultado;
//Funciones
void control(int a, int b, int c, int d){
  digitalWrite(n1,a);
  digitalWrite(n2,b);
  digitalWrite(n3,c);
  digitalWrite(n4,d);
  }  
void leds(); 
void lecturaColor();


void setup() {
  Serial.begin(9600);
     myservo.write(0);
pinMode(n1,OUTPUT);
pinMode(n2,OUTPUT);
pinMode(n3,OUTPUT);
pinMode(n4,OUTPUT);
leds();
myservo.attach(servos);
}

void loop() {
 int lectura = digitalRead(infrarojo);
  control(1,1,0,0);
  delay(10);
  control(0,1,1,0);
  delay(10);
  control(0,0,1,1);
  delay(10);
  control(1,0,0,1);
  delay(10);
  
if(lectura == 0){
  lecturaColor();
  if(resultado_rojo > resultado_verde && resultado_rojo > resultado_azul){
    Serial.println("rojo");
  for(int i = 0; i<380; i++){
  control(1,1,0,0);
  delay(10);
  control(0,1,1,0);
  delay(10);
  control(0,0,1,1);
  delay(10);
  control(1,0,0,1);
  delay(10);   
    }
  control(0,0,0,0);
   myservo.write(100);
   delay(300);   
   myservo.write(0);
      delay(300);   
    }  
   else{
    Serial.println("otro color");
for(int i=0;i<100;i++){
  control(1,1,0,0);
  delay(10);
  control(0,1,1,0);
  delay(10);
  control(0,0,1,1);
  delay(10);
  control(1,0,0,1);
  delay(10);
  }
    }  
  }

}
void leds(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(ch_LDR, INPUT);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  }
  
void lecturaColor() {
   //Enviendo el led rojo
  digitalWrite(red, HIGH);
  //espero 150 milisegundos
  delay(150);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_rojo = map(resultado, 0,1023,0,255);  //lo linealizo 
  //Lo muestro por medio del monitor serial
  Serial.print("R= ");
  Serial.println(resultado_rojo);
  digitalWrite(red, LOW);
  delay(150);

  //Enviendo el led verde
  digitalWrite(green, HIGH);
  //espero 150 milisegundos
  delay(150);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_verde = map(resultado, 0,1023,0,255);  //lo linealizo 
  //Lo muestro por medio del monitor serial
  Serial.print("G = ");
  Serial.println(resultado_verde);
  digitalWrite(green, LOW);
  delay(150);

   //Enviendo el led azul
  digitalWrite(blue, HIGH);
  //espero 150 milisegundos
  delay(150);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_azul = map(resultado, 0,1023,0,255);  //lo linealizo 
  //Lo muestro por medio del monitor serial
  Serial.print("B = ");
  Serial.println(resultado_azul);
  digitalWrite(blue, LOW);
  delay(150);
  }
