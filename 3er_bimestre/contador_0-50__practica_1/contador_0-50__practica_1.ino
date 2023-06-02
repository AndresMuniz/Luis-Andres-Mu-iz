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

#define a 4
#define b 5 
#define c 6 
#define d 7 
#define a0 8 
#define b0 9 
#define c0 10 
#define d0 11 
#define b_rising 2
#define b_falling 3

//funciones
void f_rising ();
void f_falling ();
void usodisplay();
void in_out();

//variables
volatile static bool f_print = false;
volatile static int i = 0;

void setup() {
  in_out(); 
  pinMode(b_rising, INPUT);
  pinMode(b_falling, INPUT);
  attachInterrupt(digitalPinToInterrupt(b_rising), f_rising, RISING);
  attachInterrupt(digitalPinToInterrupt(b_falling), f_falling, FALLING);   
}

void loop() {
  if (f_print){
    
    f_print = false;

   if (i==-1){
      i=50;
      usodisplay(0,0,0,0,0,1,0,1);
    }
    if (i==0){
      usodisplay(0,0,0,0,0,0,0,0);
    }
    if (i==1){
      usodisplay(0,0,0,1,0,0,0,0);
    }
    if (i==2){
      usodisplay(0,0,1,0,0,0,0,0);
    }
    if (i==3){
      usodisplay(0,0,1,1,0,0,0,0);
    }
    if (i==4){
      usodisplay(0,1,0,0,0,0,0,0);
    }
    if (i==5){
      usodisplay(0,1,0,1,0,0,0,0);
    }
    if (i==6){
      usodisplay(0,1,1,0,0,0,0,0);
    }
    if (i==7){
      usodisplay(0,1,1,1,0,0,0,0);
    }
    if (i==8){
      usodisplay(1,0,0,0,0,0,0,0);
    }
    if (i==9){
      usodisplay(1,0,0,1,0,0,0,0);
    }
    if (i==10){
      usodisplay(0,0,0,0,0,0,0,1); //se conto hasta 10
    }
    if (i==11){
      usodisplay(0,0,0,1,0,0,0,1);
    }
    if (i==12){
      usodisplay(0,0,1,0,0,0,0,1);
    }
    if (i==13){
      usodisplay(0,0,1,1,0,0,0,1);
    }
    if (i==14){
      usodisplay(0,1,0,0,0,0,0,1);
    }
    if (i==15){
      usodisplay(0,1,0,1,0,0,0,1);
    }
    if (i==16){
      usodisplay(0,1,1,0,0,0,0,1);
    }
    if (i==17){
      usodisplay(0,1,1,1,0,0,0,1);
    }
    if (i==18){
      usodisplay(1,0,0,0,0,0,0,1);
    }
    if (i==19){
      usodisplay(1,0,0,1,0,0,0,1);
    }
    if (i==20){
      usodisplay(0,0,0,0,0,0,1,0); //se conto hasta 20
    }
    if (i==21){
      usodisplay(0,0,0,1,0,0,1,0);
    }
    if (i==22){
      usodisplay(0,0,1,0,0,0,1,0);
    }
    if (i==23){
      usodisplay(0,0,1,1,0,0,1,0);
    }
    if (i==24){
      usodisplay(0,1,0,0,0,0,1,0);
    }
    if (i==25){
      usodisplay(0,1,0,1,0,0,1,0);
    }
    if (i==26){
      usodisplay(0,1,1,0,0,0,1,0);
    }
    if (i==27){
      usodisplay(0,1,1,1,0,0,1,0);
    }
    if (i==28){
      usodisplay(1,0,0,0,0,0,1,0);
    }
    if (i==29){
      usodisplay(1,0,0,1,0,0,1,0);
    }
    if (i==30){
      usodisplay(0,0,0,0,0,0,1,1); //se conto hasta 30
    }
    if (i==31){
      usodisplay(0,0,0,1,0,0,1,1);
    }
    if (i==32){
      usodisplay(0,0,1,0,0,0,1,1);
    }
    if (i==33){
      usodisplay(0,0,1,1,0,0,1,1);
    }
    if (i==34){
      usodisplay(0,1,0,0,0,0,1,1);
    }
    if (i==35){
      usodisplay(0,1,0,1,0,0,1,1);
    }
    if (i==36){
      usodisplay(0,1,1,0,0,0,1,1);
    }
    if (i==37){
      usodisplay(0,1,1,1,0,0,1,1);
    }
    if (i==38){
      usodisplay(1,0,0,0,0,0,1,1);
    }
    if (i==39){
      usodisplay(1,0,0,1,0,0,1,1);
    }
    if (i==40){
      usodisplay(0,0,0,0,0,1,0,0); //se conto hasta 40
    }
    if (i==41){
      usodisplay(0,0,0,1,0,1,0,0);
    }
    if (i==42){
      usodisplay(0,0,1,0,0,1,0,0);
    }
    if (i==43){
      usodisplay(0,0,1,1,0,1,0,0);
    }
    if (i==44){
      usodisplay(0,1,0,0,0,1,0,0);
    }
    if (i==45){
      usodisplay(0,1,0,1,0,1,0,0);
    }
    if (i==46){
      usodisplay(0,1,1,0,0,1,0,0);
    }
    if (i==47){
      usodisplay(0,1,1,1,0,1,0,0);
    }
    if (i==48){
      usodisplay(1,0,0,0,0,1,0,0);
    }
    if (i==49){
      usodisplay(1,0,0,1,0,1,0,0);
    }
    if (i==50){
      usodisplay(0,0,0,0,0,1,0,1); //se conto hasta 50
    }
    if (i==51){
      i=0;
      usodisplay(0,0,0,0,0,0,0,0);
    }
  }
}

void f_rising (){
  f_print = true;
  i++;
}
void f_falling (){
  f_print = true;
  i--;
}

void usodisplay(bool d1, bool d2, bool d3, bool d4, bool d5, bool d6, bool d7, bool d8){
    digitalWrite(d,d1);
    digitalWrite(c,d2);
    digitalWrite(b,d3);
    digitalWrite(a,d4);
    digitalWrite(d0,d5);
    digitalWrite(c0,d6);
    digitalWrite(b0,d7);
    digitalWrite(a0,d8);
}

void in_out(){
    pinMode (a, OUTPUT);
    pinMode (b, OUTPUT);
    pinMode (c, OUTPUT);
    pinMode (d, OUTPUT);
    pinMode (a0, OUTPUT);
    pinMode (b0, OUTPUT);
    pinMode (c0, OUTPUT);
    pinMode (d0, OUTPUT);
}
