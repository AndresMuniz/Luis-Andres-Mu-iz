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

//librerias que usaremos
#include <LedControl.h>
#include <Ticker.h>

//DIRECTIVAS DE PREPROCESADOR
#define sensorGas  A0

//CONSTRUCTOR DE MATRIZ LED
#define DATO_PIN 12  //
#define CLK_PIN 11   //definimos los pines
#define CS_PIN 10    //
LedControl matriz = LedControl(DATO_PIN,CLK_PIN,CS_PIN,1); 

//FUNCIONES
void fun_GAS(void);//funcion para la medicion de gas
void alerta(); //funcione para mostrar la alerta

//TICKER PARA LA MEDICION
Ticker tckr_GAS(fun_GAS, 1000);


const int ancho_matriz = 8; 
const int alto_matriz = 8; 
int gasValue;
int prom;

//ANIMACION PARA MATRIZ LED
byte flama1[8] = 
{B00011000,
B00111000,
B01111100,
B01111100,
B01111100,
B00111010,
B00010001,
B00010000};

byte flama2[8] = {
B00110000,
B00111000,
B01111100,
B01111100,
B01111100,
B01011000,
B10001000,
B00001000};

byte copo1 [8] = {
B00000000,
B00101010,
B00011100,
B00110110,
B00011100,
B00101010,
B00000000,
B00000000};

byte copo2 [8] = {
B01001001,
B00101010,
B00011100,
B01110111,
B00011100,
B00101010,
B01000001,
B00000000};

void setup() {
   Serial.begin(9600); //Iniciamos la comunicacion serial
   
  //INICIAMOS LA MATRIZ LED
  matriz.shutdown(0, false); 
  matriz.setIntensity(0, 15); 
  matriz.clearDisplay(0); 
  
  pinMode(sensorGas, INPUT);//Definimos como entrada el pin del sensor
  tckr_GAS.start();         //iniciamos el ticker 
}

void loop() {
  // Leer el valor del sensor de gas
 tckr_GAS.update();
  if (prom > 60) {
    alerta();
  } else {
    for (int i = 0; i < alto_matriz; i++) {
    matriz.setColumn(0, i, copo1[i]);
    }
    delay(300);
    for (int i = 0; i < alto_matriz; i++) {
    matriz.setColumn(0, i, copo2[i]);
    }
    delay(300);
  }
}
void fun_GAS(){
  int suma =0;
  for(int i = 0; i < 5; i++){
  gasValue = map(analogRead(sensorGas),0,1023,0,100);
  suma = suma + gasValue;
  delay(100);
  }
  prom = suma/5;
  Serial.println(gasValue);
}
void alerta() {
  matriz.clearDisplay(0);
for(int t = 0; t<5;t++){
  for (int i = alto_matriz; i > 0; i--) {
    matriz.setColumn(0, i, flama1[i]);
  }
  delay(300);
  
  for (int i = alto_matriz; i > 0; i--) {
    matriz.setColumn(0, i, flama2[i]);
  }
  delay(300);
}
}
