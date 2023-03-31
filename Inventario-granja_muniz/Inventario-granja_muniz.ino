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
#define AD 2
#define AT 3

struct info {
  char nombre[30];
  float precio;
  int reserva;
  int stock;
};

//variables
  info p0 = {"Gallina", 30.50, 60,30};
  info p1 = {"Huevo", 1.25, 100, 50};
  info p2 = {"Pollo", 13.75,70, 35};
  info p3 = {"Queso", 19.50, 20, 10};
  bool ad, at;
  int  p;
  int a;

void setup() {
  Serial.begin(9600);
  Serial.println("Bienvenido a la GRANJITA DE MUNIZ");
  Serial.println("Pulsa un boton para empezar");
  pinMode(ad, INPUT);
  pinMode(at, INPUT);
}

void loop(){
  ad = digitalRead(AD);
  at = digitalRead(AT);
  if (ad==1){
    a=1;
    }
  if (at==1){
    a=1;
    }

while(a==1){
  if(ad==1){
    p++;
    delay(200);
    }
  if(p>4){
    p=1; 
    delay(200);
    }
  if(at==1){
    p--;
    delay(200);
    }
  if(p<1){
    p=4; 
    delay(200);
    }

  if(p==1){
    Serial.println("");
    Serial.println(p0.nombre);
    Serial.print("El precio por unidad es Q"); 
    Serial.println(p0.precio);
    Serial.print("En reserva hay "); 
    Serial.print(p0.reserva); 
    Serial.println(" unidades.");
    Serial.print("En stock hay ");
    Serial.print(p0.stock); 
    Serial.println(" unidades.");
    Serial.print("El precio del lote es de Q"); 
    Serial.println(p0.precio * p0.stock);
    a=0;
    }
  if(p==2){
    Serial.println("");
    Serial.println(p1.nombre);
    Serial.print("El precio por unidad es Q"); 
    Serial.println(p1.precio);
    Serial.print("En reserva hay "); 
    Serial.print(p1.reserva); 
    Serial.println(" unidades.");
    Serial.print("En stock hay ");
    Serial.print(p1.stock); 
    Serial.println(" unidades.");
    Serial.print("El precio del lote es de Q"); 
    Serial.println(p1.precio * p1.stock);
    a=0;
    }

  if(p==3){
    Serial.println("");
    Serial.println(p2.nombre);
    Serial.print("El precio por unidad es Q"); 
    Serial.println(p2.precio);
    Serial.print("En reserva hay "); 
    Serial.print(p2.reserva); 
    Serial.println(" unidades.");
    Serial.print("En stock hay ");
    Serial.print(p2.stock); 
    Serial.println(" unidades.");
    Serial.print("El precio del lote es de Q"); 
    Serial.println(p2.precio * p2.stock);
    a=0;
  }
  if(p==4){
    Serial.println("");
    Serial.println(p3.nombre);
    Serial.print("El precio por unidad es Q"); 
    Serial.println(p3.precio);
    Serial.print("En reserva hay "); 
    Serial.print(p3.reserva); 
    Serial.println(" unidades.");
    Serial.print("En stock hay ");
    Serial.print(p3.stock); 
    Serial.println(" unidades.");
    Serial.print("El precio del lote es de Q"); 
    Serial.println(p3.precio * p3.stock);
    a=0;
  }
}
}
