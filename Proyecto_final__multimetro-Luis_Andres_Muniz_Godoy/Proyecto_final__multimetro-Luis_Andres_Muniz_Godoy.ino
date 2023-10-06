#include <SoftwareSerial.h>

const float Resistencia = 1000.0; // la resistencia que usamos para el divisor
float Sensibilidad = 0.185;
const int pin_A = A0;    // Pin para medir el voltaje
int valor;                // Variable que guarda el valor
float voltaje;               // Variable que guarda el voltaje 
const int Punta1 = 7;         // Pin positivo
const int Punta2 = 6;         // Pin negativo

//Constructor
SoftwareSerial BT(7, 6);

unsigned long t_anterior = 0;
const unsigned long intervalo = 1000; // intervalo entre cada medicion

void setup() {
  Serial.begin(9600);    // Iniciar la comunicación serial
  BT.begin(9600);
  pinMode(Punta1, OUTPUT);  // Configurar el pin positivo como salida
  pinMode(Punta2, OUTPUT);  // Configurar el pin negativo como salida
}

char recibir;

void loop() {
  // Verificar si hay datos disponibles desde la aplicación Bluetooth
  if (BT.available()) {
    recibir = BT.read();
    Serial.println(recibir);

    // Procesar comandos según corresponda
    if (recibir == 'A') {
      funcion_voltaje();
    }
    else if (recepcioncioncioncioncioncion == 'B') {
      funcion_resistencia();
    }
    else if (recepcioncioncioncioncioncion == 'C') {
      funcion_corriente();
    }
  }

  // Realizar mediciones continuas a intervalos regulares
  unsigned long tiempoActual = millis();
  if (tiempoActual - t_anterior >= intervalo) {
    t_anterior = tiempoActual;

    // Realizar la medición que desees aquí
    // Por ejemplo: funcion_corriente();
  }
}

float calculo(int numeroMuestral)
{
float LeerSenso = 0;
float inten = 0;
for(int i=0;i<numeroMuestral;i++)
{
  LeerSenso= analogRead(A2) * (5.0 / 1023.0);
  inten=inten+(LeerSenso-2.5)/Sensibilidad;
}
inten=inten/numeroMuestral;
return(inten);
}
void funcion_voltaje() {
  digitalWrite(Punta1, HIGH);
  digitalWrite(Punta2, HIGH);
  valor = analogRead(A1);               // Realizar la lectura
  voltaje = map(valor, 0, 1023, 0, 250) / 10.0;  // Escalar a 0.0 - 25.0
  Serial.print("Voltaje: ");
  Serial.println(voltaje);          // Mostrar el valor por serial
  BT.print(voltaje);
  BT.print(";");
}

void funcion_corriente() {
  float Corriente=calculo(500);
      Serial.print("Corriente: ");
      Serial.println(Corriente,3);
      BT.print(Corriente,3);
      BT.print(";");
}

void funcion_resistencia() {
  digitalWrite(Punta1, LOW);
  digitalWrite(Punta2, LOW);
  int valorAnalogico = analogRead(pin_A);

  // Convertir el valor analógico a tensión (en voltios)
  float tensionMedida = (float)valorAnalogico * (5.0 / 1023.0);

  // Calcular la corriente (I) usando la ley de Ohm: I = V / R
  float corriente = tensionMedida / Resistencia;

  // Calcular la resistencia desconocida usando la ley de Ohm: R = V / I
  float resistenciaDesconocida = tensionMedida / corriente;

  Serial.print("Resistencia: ");
  Serial.println(resistenciaDesconocida);
  BT.print(resistenciaDesconocida);
  BT.print(";");
}
