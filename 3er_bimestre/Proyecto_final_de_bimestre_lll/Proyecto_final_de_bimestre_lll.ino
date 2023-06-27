#include<SoftwareSerial.h> // libreria para la comunicacion serial por bluetooth
#include<Servo.h> //libreria para el servo

//funcion(es)

void fun_bluetooth();

//constructores
SoftwareSerial bluetooth(0,1);
/* creamos los objetos para los servos*/
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(9600);//iniciamos la comunicacion con la consola
  bluetooth.begin(9600);//iniciamos la comunicacion del bluetooth con el telefono
  servo1.attach(3);//le asignamos un pin al servo 1
  servo2.attach(5);//le asignamos un pin al servo 2
  servo3.attach(6);//le asignamos un pin al servo 3
  servo3.attach(9);//le asignamos un pin al servo 4
}

void loop() {
  fun_bluetooth();
}

//funcion donde que lee el bluetooth y mueve los servos
void fun_bluetooth (){
  unsigned int servopos1 = bluetooth.read();
  unsigned int servopos2 = bluetooth.read();
  unsigned int servopos3 = bluetooth.read();
  unsigned int servopos4 = bluetooth.read();
  unsigned int realservo = (servopos2 *256)  + servopos1 + servopos3 + servopos4;
  Serial.println(realservo);

  if (realservo >= 1000 && realservo < 1180){
    int servomap1 = realservo;
    servomap1 = map(servomap1, 1000,1180,0,180);
    servo1.write(servomap1);
    Serial.println("Servo 1 ON"); 
  }

  if (realservo >= 2000 && realservo < 2180){
    int servomap2 = realservo;
    servomap2 = map(servomap2, 2000,2180,0,180);
    servo2.write(servomap2);
    Serial.println("Servo 2 ON"); 
  }

  if (realservo >= 3000 && realservo < 3180){
    int servomap3 = realservo;
    servomap3 = map(servomap3, 3000,3180,0,180);
    servo3.write(servomap3);
    Serial.println("Servo 3 ON"); 
  }

  if (realservo >= 4000 && realservo < 4180){
    int servomap4 = realservo;
    servomap4 = map(servomap4, 4000,4180,0,180);
    servo3.write(servomap4);
    Serial.println("Servo 4 ON"); 
  }
}
