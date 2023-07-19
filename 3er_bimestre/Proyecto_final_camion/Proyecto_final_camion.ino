#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(7, 8);  // Pines RX, TX del módulo Bluetooth HC-05

// Pines de control del carro
const int motor1Pin1 = 3;
const int motor1Pin2 = 5;
const int motor2Pin1 = 6;
const int motor2Pin2 = 9;
const int led1 = 2;
const int led2 = 4;
const int led3 = 12;
const int buzzerPin = 11;
Servo myservo;

void setup() {
  Serial.begin(9600);
  // Configurar los pines de control del carro como salida
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  myservo.attach(10);

  bluetooth.begin(9600);  // Iniciar la comunicación Bluetooth a 9600 bps
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();  // Leer el comando recibido por Bluetooth

    // Controlar el carro según el comando recibido
    switch (command) {
      case 'A':
        adelante();
        break;
      case 'R':
        atras();
        break;
      case 'S':
        stop();
        break;
      case 'D':
        pide_vias_D();
        break;
      case 'I':
        pide_vias_I();
        break;
      case '9':
        noventa_Grados();
        break;
      case '8':
        ciento_ochenta_Grados();
        break;
      case '1':
        centro_C(); 
        break;
      case 'a':
        luces_a();
        break;
      case 'p':
        luces_p(); 
        break;
    }
  }
}

// Funciones de control del camion 
void adelante() {
   Serial.println("Adelante");
  digitalWrite(buzzerPin, LOW);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void atras() {
   Serial.println("Atras");
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stop() {
   Serial.println("Stop");
  digitalWrite(buzzerPin, LOW);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void pide_vias_D() {
  Serial.println("Derecha");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led3, HIGH);
    delay(200);  
    digitalWrite(led3, LOW);   
    delay(200);  
    digitalWrite(led3, HIGH);  
    delay(200);  
    digitalWrite(led3, LOW); 
    delay(200);  
    digitalWrite(led3, LOW);   
    delay(200);  
    digitalWrite(led3, HIGH);  
    delay(200);  
    digitalWrite(led3, LOW); 
  
}

void pide_vias_I() {
  Serial.println("Izquierda");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(led2, HIGH);
    delay(200);  
    digitalWrite(led2, LOW);   
    delay(200);  
    digitalWrite(led2, HIGH);  
    delay(200);  
    digitalWrite(led2, LOW); 
    delay(200);  
    digitalWrite(led2, LOW);   
    delay(200);  
    digitalWrite(led2, HIGH);  
    delay(200);  
    digitalWrite(led2, LOW); 
}

void noventa_Grados(){
  digitalWrite(buzzerPin, LOW);
  myservo.write(70);
  delay (2000);
  myservo.write(90);
}

void ciento_ochenta_Grados(){
  digitalWrite(buzzerPin, LOW);
  myservo.write(180);
  delay (2000);
  myservo.write(90);
}

void centro_C(){
  digitalWrite(buzzerPin, LOW);
  myservo.write(90);
}

void buzzer() {
  tone(buzzerPin, 1000);
  delay(500);
  noTone(buzzerPin);
  delay(500);
  tone(buzzerPin, 1000);
  delay(500);
  noTone(buzzerPin);
}

void luces_p() {
  digitalWrite(led1, HIGH);
}

void luces_a() {
  digitalWrite(led1, LOW);
}
