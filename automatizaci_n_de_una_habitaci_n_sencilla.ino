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
#include <Servo.h> //libreria que me permite usar el servo
#include <Adafruit_NeoPixel.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C

#define pin_Led 3
#define rcwl 4
#define rojo 5
#define azul 6
#define verde 7
#define buzz 8
#define door 9
#define pin_servo 10
#define rel1 11
#define rel2 12
#define bfoco1 A0 
#define bfoco2 A1 

//Constructor
Servo servo;  //mi servo


//Constructor del NeoPixel 
Adafruit_NeoPixel neopixel(7,pin_Led, NEO_GRB + NEO_KHZ800);

//Armador de lCD
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
LiquidCrystal_I2C LCD_muniz(direccion_lcd, columnas, filas);

//Constructores
OneWire ourWire(2);                //Se establece el pin 5  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensors(&ourWire);

//funciones
void puerta();
void movimiento();
void salidas();
void temperatura();
int temperaturac();
void rele1();
void rele2();

//variables
int celsius;
int mempuerta=0; 
int memfoco1=0;
int memfoco2=0;

byte hielo[] = {
  B00000,
  B00111,
  B00111,
  B00111,
  B00000,
  B11100,
  B11100,
  B11100
};
byte agua[] = {
  B00010,
  B00110,
  B01110,
  B10011,
  B10111,
  B11111,
  B01110,
  B00000
};
byte vapor[] = {
  B00010,
  B00111,
  B00000,
  B00100,
  B01110,
  B11111,
  B00000,
  B00000
};
byte person[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010
};
byte f_oof[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01110,
  B01110,
  B00100
};
byte f_on[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B00100
};

void setup() {
  salidas();
  digitalWrite(rel1, HIGH);
  digitalWrite(rel2, HIGH);
  servo.attach(pin_servo);
  sensors.begin();  
  LCD_muniz.init(); //inicio la comunicacion serial con el modulo i2c
  LCD_muniz.backlight(); 
  LCD_muniz.createChar(0,hielo);
  LCD_muniz.createChar(1,agua);
  LCD_muniz.createChar(2,vapor);
  LCD_muniz.createChar(3,person);
  LCD_muniz.createChar(4,f_oof);
  LCD_muniz.createChar(5,f_on);
  LCD_muniz.setCursor(0,1);
  LCD_muniz.print("P:close");
  LCD_muniz.setCursor(9,1);
  LCD_muniz.print("F:");
  LCD_muniz.write(4);
  LCD_muniz.setCursor(13,1);
  LCD_muniz.print("F:");
  LCD_muniz.write(4);
}

void loop() {
  celsius = temperaturac();
  puerta();
  rele1();
  rele2();
  puerta();
  temperatura();
  rele1();
  rele2();
  movimiento();
  rele1();
  rele2();
  puerta();
}

void salidas(){
  pinMode(pin_Led,OUTPUT);
  pinMode(rcwl,INPUT);
  pinMode(door,INPUT);
  pinMode(azul,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(rojo,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(rel1,OUTPUT);
  pinMode(rel2,OUTPUT);
  pinMode(bfoco1,INPUT);
  pinMode(bfoco2,INPUT);

}

void temperatura(){
  if ( celsius> 14 && celsius<22){
      LCD_muniz.setCursor(0,0);
      LCD_muniz.print("Temp:");
      LCD_muniz.write(0);
      digitalWrite(rojo, HIGH);
      digitalWrite(azul, HIGH);
      digitalWrite(verde, LOW);
      }  
  if ( celsius>21 && celsius<26){
      LCD_muniz.setCursor(0,0);
      LCD_muniz.print("Temp:");
      LCD_muniz.write(1);
      digitalWrite(rojo, LOW);
      digitalWrite(azul, LOW);
      digitalWrite(verde, HIGH);
      } 
  if ( celsius>25 && celsius<46){
      LCD_muniz.setCursor(0,0);
      LCD_muniz.print("Temp:");
      LCD_muniz.write(2);
      digitalWrite(rojo, HIGH);
      digitalWrite(azul, LOW);
      digitalWrite(verde, LOW);
      }  
}

int temperaturac(){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}

void movimiento(){
  bool mov = digitalRead(rcwl);
  if(mov==1){
    LCD_muniz.setCursor(9,0);
    LCD_muniz.print("Radar:");
    LCD_muniz.write(3);
    for(int i =0; i<8; i++){
      neopixel.setPixelColor(i,neopixel.Color(255,0,0));
      neopixel.show(); 
    }
    digitalWrite(buzz, HIGH);
    delay(250);
    for(int i =0; i<8; i++){
      neopixel.setPixelColor(i,neopixel.Color(124,252,0));
      neopixel.show(); 
    }
    LCD_muniz.setCursor(9,0);
    LCD_muniz.print("Radar: ");
    digitalWrite(buzz, LOW);
    delay(250);
   
  }
  if(mov==0){
    for(int i =0; i<8; i++){
      neopixel.setPixelColor(i,neopixel.Color(0,0,255));
      neopixel.show(); 
      LCD_muniz.setCursor(9,0);
      LCD_muniz.print("Radar: ");
    }
  }
}
void puerta(){
  if(digitalRead(door) && mempuerta==0){
    servo.write(0);
    LCD_muniz.setCursor(0,1);
    LCD_muniz.print("P:open ");
    delay(500);
    mempuerta=1;
  }
  if(digitalRead(door) && mempuerta==1){
    servo.write(90);
    LCD_muniz.setCursor(0,1);
    LCD_muniz.print("P:close ");
    delay(500);
    mempuerta=0;
  }
}

void rele1(){
  if (digitalRead(bfoco1) && memfoco1==0){
    digitalWrite(rel1, LOW);
    LCD_muniz.setCursor(9,1);
    LCD_muniz.print("F:");
    LCD_muniz.write(5);
    delay(500);
    memfoco1=1;
  }
if (digitalRead(bfoco1) && memfoco1==1){
    digitalWrite(rel1, HIGH);
    LCD_muniz.setCursor(9,1);
    LCD_muniz.print("F:");
    LCD_muniz.write(4);
    delay(500);
    memfoco1=0;
  }
}
 
void rele2(){
  if (digitalRead(bfoco2) && memfoco2==0){
    digitalWrite(rel2, LOW);
    LCD_muniz.setCursor(13,1);
    LCD_muniz.print("F:");
    LCD_muniz.write(5);
    delay(500);
    memfoco2=1;
  }
if (digitalRead(bfoco2) && memfoco2==1){
    digitalWrite(rel2, HIGH);
    LCD_muniz.setCursor(13,1);
    LCD_muniz.print("F:");
    LCD_muniz.write(4);
    delay(500);
    memfoco2=0;
  }
}
