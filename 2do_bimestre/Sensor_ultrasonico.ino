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
#define off(pin) digitalWrite (pin, LOW)
#define on(pin) digitalWrite (pin, HIGH)
#define Trigger 2  //pines que usaremos
#define Echo 3 
#define a 4
#define b 5 
#define c 6 
#define d 7 
#define e 8 
#define f 9 
#define g 10 
#define re 12

long t;    //variables globales
long x; 
int i=-1; 
 


void setup() {
  in_out();  
  

}

void loop() {
  
  void ultrasonico();
  void funsensor();
  void rele();
    
}
 void ultrasonico(){
    on(Trigger);
    delay(1);          
    off(Trigger);
    t = pulseIn(Echo, HIGH); 
    x = t/59;  
    delay(600);
  } 
  void funsensor(){
    if((x > 5) && (x < 11)){
      i=i++;
      delay(250);
      
    if(i==0){
      usodisplay(1,1,1,1,1,1,0);
      }
    if(i==1){
      usodisplay(0,1,1,0,0,0,0);
      } 
    if(i==2){
      usodisplay(1,1,0,1,1,0,1);
      } 
    if(i==3){
      usodisplay(1,1,1,1,0,0,1);
      }
    if(i==4){
      usodisplay(0,1,1,0,0,1,1);
      }
    if(i==5){
      usodisplay(1,0,1,1,0,1,1);
      }
    if(i==6){
      usodisplay(1,0,1,1,1,1,1);
      }
    if(i==7){
      usodisplay(1,1,1,0,0,0,0);
      }
    if(i==8){
      usodisplay(1,1,1,1,1,1,1);
      }
    if(i==9){
      usodisplay(1,1,1,0,0,1,1);
      }
    }
  }    
 
            
  void rele(){
    if(i==9){
      on(re);
      }
      else {
        off(re);
      }
  }

  void usodisplay(bool d1, bool d2, bool d3, bool d4, bool d5, bool d6, bool d7){
    digitalWrite(a,d1);
    digitalWrite(b,d2);
    digitalWrite(c,d3);
    digitalWrite(d,d4);
    digitalWrite(e,d5);
    digitalWrite(f,d6);
    digitalWrite(g,d7);
  }
  void in_out(){
    pinMode (Echo, INPUT);
    pinMode (Trigger, OUTPUT);
    pinMode (a, OUTPUT);
    pinMode (b, OUTPUT);
    pinMode (c, OUTPUT);
    pinMode (d, OUTPUT);
    pinMode (e, OUTPUT);
    pinMode (f, OUTPUT);
    pinMode (g, OUTPUT);
    pinMode (re, OUTPUT);
  }
