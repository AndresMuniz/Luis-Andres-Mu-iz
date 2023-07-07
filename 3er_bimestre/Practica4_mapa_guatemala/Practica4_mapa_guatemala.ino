/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: Cristian Estuardo Orellana Dieguez
 * Nombre: Luis Andres Muñiz Godoy1
*/
//Librerias
#include <Wire.h>
#include <SoftwareSerial.h>
#include <PCF8574.h>

//Directivas
#define PHIGH LOW  
#define PLOW HIGH  
#define buzz 2
#define totonicapan 3
#define zacapa 4
#define altaV 5
#define bajaV 6
#define chimaltenango 7
#define chiquimula 8
#define guatemala 9
#define elprogreso 10
#define escuintla 11
#define huehuetenango 12
#define izabal 13
#define jalapa  A0
#define jutiapa A1
#define peten A2
#define quetzaltenango A3
#define quiche A4
#define retalhuleu A5
#define sacatepequez A6
#define sanmarcos A7
#define santarosa A8
#define suchitepequez A9
#define solola 0

  #define Do 262
  #define Dosos 277
  #define Re 294
  #define Resos 311
  #define Mi 330
  #define Fa 349
  #define Fasos 370
  #define Sol 392
  #define Solsos 415
  #define La 440
  #define Lasos 466
  #define Si 494
  
//Constructores
PCF8574 expansor(0x27);

//Variables
bool iniciar = false;
String respuesta;
int nrandom;

//Funciones
void fallo();
void quiz();
void pines();
void apagarLed();
void esperar_respuesta();

void setup() {

  Serial1.begin(9600);
  pines();
  Serial.println("Bienvenido a Guate te enseña.com");  
  Serial.println("Para empezar Escriba (Iniciar) ");   
  Serial.println("Para finalizar Escriba (Fin) ");   
}

void loop() {
  if(Serial1.available()>0){
    String empezar = Serial1.readStringUntil('\n');
  if ( empezar == String("iniciar")){
  Serial1.println("Primera pregunta");   
  iniciar = true;
    delay(100);
  }
  }
  
  if (iniciar == true){
  nrandom = random(0, 21);
  quiz();
  delay(500);
  Serial1.println("Siguiente pregunta");   
  }
  
  if(iniciar == false){
  Serial1.println("Escribe (Iniciar) para empezar el Quiz");
  while(!Serial1.available()){
  delay(1);
  }   
 }
}

void quiz(){
   if(nrandom == 0){
    Serial1.println("Cabecera departamental de Petén");
    esperar_respuesta();
      if(respuesta == String("Flores")){    //Respuesta correcta
        apagarLed();        
        digitalWrite(peten, HIGH);  
        Serial1.println("Respuesta correcta"); 
      }
      else{
       fallo();
       }
      }
           
      if(nrandom == 1){
    Serial1.println("Cabecera departamental de Izabal");
    esperar_respuesta();
      if(respuesta == String("Puerto Barrios")){    //Respuesta correcta
        apagarLed();
        digitalWrite(izabal, HIGH);  
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 2){
    Serial1.println("Cabecera departamental de Alta Verapaz");
    esperar_respuesta();
      if(respuesta == String("Coban")){    //Respuesta correcta
        apagarLed();  
        digitalWrite(altaV, HIGH); 
        Serial1.println("Respuesta correcta"); 
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 3){
    Serial1.println("Cabecera departamental de Quiché");
    esperar_respuesta();
      if(respuesta == String("Santa Cruz del Quiche")){   //Respuesta correcta
         apagarLed();  
         digitalWrite(quiche, HIGH);   
         Serial1.println("Respuesta correcta");
      }
      else{
        fallo();
       }
      }
      
      if(nrandom == 4){
    Serial1.println("Cabecera departamental de Huehuetenango");
    esperar_respuesta();
      if(respuesta == String("Huehuetenango")){  //Resuesta Correcta
        apagarLed();  
        digitalWrite(huehuetenango, HIGH);
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
       if(nrandom == 5){
    Serial1.println("Cabecera departamental de Escuintla");
    esperar_respuesta();
      if(respuesta == String("Escuintla")){
        apagarLed();  
        digitalWrite(escuintla, HIGH); 
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
        if(nrandom == 6 ){
    Serial1.println("Cabecera departamental de San Marcos");
    esperar_respuesta();
      if(respuesta == String("San Marcos")){
        apagarLed();  
        digitalWrite(sanmarcos, HIGH);  
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 7 ){
    Serial1.println("Cabecera departamental de Jutiapa");
    esperar_respuesta();
      if(respuesta == String("Jutiapa")){
        apagarLed();  
        digitalWrite(jutiapa, HIGH); 
        Serial1.println("Respuesta correcta"); 
      }
      else{
      fallo();
       }
      }
      
      if(nrandom == 8 ){
    Serial1.println("Cabecera departamental de Baja Verapaz");
    esperar_respuesta();
      if(respuesta == String("Salama")){
        apagarLed();  
        digitalWrite(bajaV, HIGH); 
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
       if(nrandom == 9 ){
    Serial1.println("Cabecera departamental de Santa Rosa");
    esperar_respuesta();
      if(respuesta == String("Cuilapa")){
             apagarLed();  
             digitalWrite(santarosa, HIGH); 
             Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 10 ){
    Serial1.println("Cabecera departamental de Zacapa");
    esperar_respuesta();
      if(respuesta == String("Zacapa")){
              apagarLed();
              digitalWrite(zacapa, HIGH);  
              Serial1.println("Respuesta correcta");     
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 11 ){
    Serial1.println("Cabecera departamental de Suchitepéquez");
    esperar_respuesta();
      if(respuesta == String("Mazatenango")){
              apagarLed();  
              digitalWrite(suchitepequez, HIGH);
              Serial1.println("Respuesta correcta");       
      }
      else{
        fallo();
       }
      }
      
      if(nrandom == 12 ){
    Serial1.println("Cabecera departamental de Chiquimula");
    esperar_respuesta();
      if(respuesta == String("Chiquimula")){
              apagarLed();  
        digitalWrite(chiquimula, HIGH);
                 Serial1.println("Respuesta correcta");   
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 13 ){
    Serial1.println("Cabecera departamental de Guatemala");
    esperar_respuesta();
      if(respuesta == String("Guatemala")){
              apagarLed();  
        digitalWrite(guatemala, HIGH); 
                 Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 14 ){
    Serial1.println("Cabecera departamental de Jalapa");
    esperar_respuesta();
      if(respuesta == String("Jalapa")){
             apagarLed();  
        digitalWrite(jutiapa, HIGH); 
                 Serial1.println("Respuesta correcta"); 
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 15 ){
    Serial1.println("Cabecera departamental de Chimaltenango");
    esperar_respuesta();
      if(respuesta == String("Chimaltenango")){
             apagarLed();  
        digitalWrite(chimaltenango, HIGH);  
                 Serial1.println("Respuesta correcta");
      }
      else{
        fallo();
       }
      }
      
      if(nrandom == 16 ){
    Serial1.println("Cabecera departamental de Quetzaltenango");
    esperar_respuesta();
      if(respuesta == String("Quetzaltenango")){
             apagarLed();  
        digitalWrite(quetzaltenango, HIGH); 
                 Serial1.println("Respuesta correcta"); 
                 
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 17 ){
    Serial1.println("Cabecera departamental de El progreso");
    esperar_respuesta();
      if(respuesta == String("Guastatoya")){
             apagarLed();  
        digitalWrite(elprogreso, HIGH);  
                 Serial1.println("Respuesta correcta");
      }
      else{
     fallo();
       }
      }
      
      if(nrandom == 18 ){
    Serial1.println("Cabecera departamental de Retalhuleu");
    esperar_respuesta();
      if(respuesta == String("Retalhuleu")){
        apagarLed();  
        digitalWrite(retalhuleu, HIGH);  
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 19 ){
    Serial1.println("Cabecera departamental de Sololá");
    esperar_respuesta();
      if(respuesta == String("Solola")){      
             apagarLed();  
             expansor.write(solola, PHIGH);       
             Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 20 ){
    Serial1.println("Cabecera departamental de Totonicapán");
    esperar_respuesta();
      if(respuesta == String("Totonicapan")){
             apagarLed();  
             digitalWrite(totonicapan, HIGH);
             Serial1.println("Respuesta correcta"); 
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 21 ){
    Serial1.println("Cabecera departamental de Sacatepéquez");
    esperar_respuesta();
      if(respuesta == String("La antigua guatemala")){
        apagarLed();  
        digitalWrite(sacatepequez, HIGH);  
        Serial1.println("Respuesta correcta");
      }
      else{
       fallo();
       }
      }
      
      if(respuesta == String("Fin")){
       iniciar = false;
       Serial1.print("Juego Finalizado");
    }
  }
  
void fallo(){
  apagarLed();
  Serial1.println("Respuesta incorrecta");
  tone(buzz, Re*2 ,500);  
  delay(100);
  tone(buzz, Sol*2 ,500); 
  delay(200);
  tone(buzz, Sol*2 ,500);  
  delay(200);
  tone(buzz, Do*2 ,500); 
  delay(200);
  tone(buzz, Lasos*2 ,500); 
  delay(500);
  tone(buzz, Do*2,500);
  delay(100);
  tone(buzz, Si*2,500);  
  delay(100);
  }
  
void apagarLed(){
       digitalWrite(peten, LOW); 
       digitalWrite(izabal, LOW);   
       digitalWrite(altaV, LOW); 
       digitalWrite(quiche, LOW); 
       digitalWrite(huehuetenango, LOW); 
       digitalWrite(escuintla, LOW);   
       digitalWrite(sanmarcos, LOW); 
       digitalWrite(jutiapa, LOW);
       digitalWrite(bajaV, LOW); 
       digitalWrite(chiquimula, LOW); 
       digitalWrite(guatemala, LOW);   
       digitalWrite(jalapa, LOW); 
       digitalWrite(chimaltenango, LOW);
       digitalWrite(quetzaltenango, LOW); 
       digitalWrite(elprogreso, LOW);   
       digitalWrite(retalhuleu, LOW); 
       digitalWrite(sacatepequez, LOW);   
       digitalWrite(suchitepequez, LOW); 
       digitalWrite(totonicapan, LOW); 
       digitalWrite(santarosa, LOW);   
       digitalWrite(zacapa, LOW); 
       expansor.write(solola, PLOW); 
  }
  
void pines(){
       pinMode(buzz, OUTPUT); 
       pinMode(peten, OUTPUT); 
       pinMode(izabal, OUTPUT);   
       pinMode(altaV, OUTPUT); 
       pinMode(quiche, OUTPUT); 
       pinMode(huehuetenango, OUTPUT); 
       pinMode(escuintla, OUTPUT);   
       pinMode(sanmarcos, OUTPUT); 
       pinMode(jutiapa, OUTPUT);
       pinMode(bajaV, OUTPUT);   
       pinMode(chiquimula, OUTPUT); 
       pinMode(guatemala, OUTPUT);   
       pinMode(jalapa, OUTPUT); 
       pinMode(chimaltenango, OUTPUT);
       pinMode(quetzaltenango, OUTPUT); 
       pinMode(elprogreso, OUTPUT);   
       pinMode(retalhuleu, OUTPUT); 
       pinMode(sacatepequez, OUTPUT);   
       pinMode(santarosa, OUTPUT); 
       pinMode(totonicapan, OUTPUT); 
       pinMode(zacapa, OUTPUT);
       pinMode(suchitepequez, OUTPUT);  
  }
  void esperar_respuesta(){
    int tiempo_max = 10;
    bool tiempo_a = false;
    while(!Serial1.available() && tiempo_a == false){
      tiempo_max--;
      delay(1000);
      if(tiempo_max < 0){
        tiempo_a = true;
        }
      }
    respuesta = Serial1.readStringUntil('\n');
    }
