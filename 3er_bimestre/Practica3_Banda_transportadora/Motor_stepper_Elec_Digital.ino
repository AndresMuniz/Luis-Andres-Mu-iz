#define m1 2
#define m2 3
#define m3 4
#define m4 5

void rodar(int r1, int r2, int r3, int r4){
  digitalWrite(2, r1);
  digitalWrite(3, r2);
  digitalWrite(4, r3);
  digitalWrite(5, r4);
  }
int i = 2;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
rodar(1,1,0,0);
delay(10);
rodar(0,1,1,0);
delay(10);
rodar(0,0,1,1);
delay(10);
rodar(1,0,0,1);
delay(10);
/*rodar(1,0,0,0);
delay(10);
rodar(0,1,0,0);
delay(10);
rodar(0,0,1,0);
delay(10);
rodar(0,0,0,1);
delay(10);*/
}
