#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
//#include "RTClib.h"

#define RST 9
#define SS 10
//#define sensor_corrinete A1

//DS3231 rtc;

MFRC522 RFID(SS,RST);

byte ActualUID[4];
byte usuario1[4]= {0x90, 0x0E, 0xE4, 0xA4};

//////variables del modulo de voltaje
const int sensorPin = A0;   // seleccionar la entrada para el sensor
int sensorValue;      // variable que almacena el valor raw (0 a 1023)
float voltaje;        // variable que almacena el voltaje (0.0 a 25.0)

//////variables del sensor de corriente
float Sensibilidad=0.185; //sensibilidad en Voltios/Amperio para sensor de 5A

void setup() {
  
  Serial.begin(9600);
  SPI.begin();
  RFID.PCD_Init();
  Serial.println("Listo");
  /*
  if (!rtc.begin()) {
    Serial.println(F("RTC desconectado"));
    while (1);
  }

  // Si se ha perdido la corriente, fijar fecha y hora
  if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }*/
}

void loop() {
  /////voltaje
  sensorValue = analogRead(sensorPin);        // realizar la lectura
  voltaje = fmap(sensorValue, 0, 1023, 0.0, 25.0);   // cambiar escala a 0.0 - 25.0

  /////corriente
  float I=get_corriente(200);//obtenemos la corriente promedio de 500 muestras 

  /////potencia
  float potencia = I*voltaje;
  
  // Revisamos si hay nuevas tarjetas  presentes
  if ( RFID.PICC_IsNewCardPresent()) {  
     //Seleccionamos una tarjeta
     if ( RFID.PICC_ReadCardSerial()) {
        // Enviamos serialemente su UID
        Serial.print(F("Card UID:"));
        for (byte i = 0; i < RFID.uid.size; i++) {
            Serial.print(RFID.uid.uidByte[i] < 0x10 ? " 0" : " ");
            Serial.print(RFID.uid.uidByte[i], HEX);   
            ActualUID[i]=RFID.uid.uidByte[i];          
        } 
        Serial.print("     ");                 
        //comparamos los UID para determinar si es uno de nuestros usuarios  
        if(compareArray(ActualUID,usuario1)){
           Serial.println("Acceso concedido...");
           /*
           DateTime now = rtc.now();
           printDate(now);
           */
           Serial.print("Voltaje: ");              // mostrar el valor por serial
           Serial.println(voltaje);
           Serial.print("Corriente: ");
           Serial.println(I,3);
           Serial.print("Potencia: ");
           Serial.println(potencia);  
        }
        else{
           Serial.println("Acceso denegado...");
        }
        // Terminamos la lectura de la tarjeta tarjeta  actual
        RFID.PICC_HaltA();
     }   
  }  
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}

//voltaje /  cambio de escala entre floats
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//corriente
float get_corriente(int n_muestras)
{
  float voltajeSensor;
  float corriente=0;
  for(int i=0;i<n_muestras;i++)
  {
    voltajeSensor = analogRead(A1) * (5.0 / 1023.0);////lectura del sensor
    corriente=corriente+(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  }
  corriente=corriente/n_muestras;
  return(corriente);
}

/*
//funcion para mostrar la hora
void printDate(DateTime date)
{
  Serial.print("Hora de ingreso: ");
  Serial.print(date.hour(), DEC);
  Serial.print(':');
  Serial.print(date.minute(), DEC);
  Serial.print(':');
  Serial.print(date.second(), DEC);
  Serial.println();
}
*/
