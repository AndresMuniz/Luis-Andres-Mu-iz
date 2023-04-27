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
#include <LiquidCrystal.h>

#define RS  6     //directivas
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5

//Constructor
LiquidCrystal LCD_munis(RS, Enable, D4, D5, D6, D7); //Constructor que me permite usar la LCD

void setup()
{
  LCD_munis.begin(16,2); //Objeto de una LCD de 16 columnas x 2 filas
  LCD_munis.print("Luis");
  LCD_munis.setCursor(0,2);
  LCD_munis.print("2019127");

}
void loop()
{
}  
