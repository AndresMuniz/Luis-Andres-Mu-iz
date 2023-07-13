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

//librerias por utilizar
#include<Wire.h>
#include<SparkFun_ADXL345.h>
#include<LedControl.h>

#define dpin 2
#define dclock 3
#define dload 4

//constructores
ADXL345 adxl = ADXL345();
LedControl matriz = LedControl(dpin,dclock,dload,1);

  //izquierda
  byte centrado[8]= {
  B11000011,
  B11000011,
  B11000011,
  B11011011,
  B11011011,
  B11000011,
  B11000011,
  B11000011
  };

  byte med_inclinado[8]= {
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11011011,
  B11011011,
  B11000011,
  B11000011
  };

  byte inclinado[8]= {
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11011011,
  B11011011,
  B11000011
  };

  byte vertical[8]= {
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11011011,
  B11011011
  };

  //derecha
  byte med_inclinado1[8]= {
  B11000011,
  B11000011,
  B11011011,
  B11011011,
  B11000011,
  B11000011,
  B11000011,
  B11000011
  };

  byte inclinado1[8]= {
  B11000011,
  B11011011,
  B11011011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011
  };

  byte vertical1[8]= {
  B11011011,
  B11011011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011,
  B11000011
  };


void setup() {
  //iniciamos la comunicacion serial
  Serial.begin(9600);

  //iniciamos el ADXL345
  adxl.powerOn();
  adxl.setRangeSetting(8); //definimos el rango

  //iniciamos la matriz led
  matriz.shutdown(0,false);
  matriz.setIntensity(0,5);
  matriz.clearDisplay(0);


}

void loop() {
  //leer los valores del ADXL345 y los muestra
  int x, y, z;
  adxl.readAccel(&x, &y, &z);
  Serial.print("x: ");
  Serial.println(x);

  //izquierda
  if (x<=3 && x>=0){
    Serial.println("centrado");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,centrado[i]);
    }
  }
  if (x<=-1 && x>=-25){
    Serial.println("medio inclinado");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,med_inclinado[i]);
    }
  }
  if (x<=-26 && x>=-50){
    Serial.println("inclinado");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,inclinado[i]);
    }
  }
  if (x<=-51 && x>=-70){
    Serial.println("vertical");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,vertical[i]);
    }
  }

  //derecha
  if (x>=4 && x<=25){
    Serial.println("medio inclinado");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,med_inclinado1[i]);
    }
  }
  if (x>=26 && x<=50){
    Serial.println("inclinado");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,inclinado1[i]);
    }
  }
  if (x>=51 && x<=70){
    Serial.println("vertical");
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,vertical1[i]);
    }
  }
  delay(10);
}
