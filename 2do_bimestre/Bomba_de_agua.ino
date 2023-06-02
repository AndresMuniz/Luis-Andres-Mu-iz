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

#define in(pin) pinMode (pin, INPUT)
#define out(pin) pinMode (pin, OUTPUT)
#define off(pin) digitalWrite (pin, LOW)
#define on(pin) digitalWrite (pin, HIGH)

#define bomba 2
#define sensor 3
#define full 4
#define low 5

void setup() {
out(bomba);
in(sensor);
out(full);
out(low);
}

void loop() {
  
  int medida;
  medida = digitalRead(sensor);
  
  if (medida == HIGH){
    on(low);
    off(full);
    on(bomba);
    }
    
    medida = digitalRead(sensor);
  
  if (medida == LOW){
    off(low);
    on(full);
    off(bomba);
    delay(2000);
    }
}
