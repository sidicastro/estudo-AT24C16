#include <Wire.h>

#define ENDERECO 0x50
#define VCC_MEM_FONTE A0
#define VCC_MEM_DESTINO A1
#define LED_SISTEMA_OK 13
#define LED_CLONE_OK 12

byte RDADOS;

void setup() {
  Serial.begin(115200);
  //Wire.setClock(400000);
  Wire.begin();

  pinMode(VCC_MEM_FONTE, OUTPUT);
  pinMode(VCC_MEM_DESTINO, OUTPUT);
  pinMode(LED_SISTEMA_OK, OUTPUT);
  pinMode(LED_CLONE_OK, OUTPUT);

  digitalWrite(VCC_MEM_DESTINO, HIGH); /* liga a memória */
  digitalWrite(LED_CLONE_OK, LOW);

  unsigned end_celula = 4;
  gravarMemoria(ENDERECO, end_celula, 128);
  Serial.print("comecando...");
  lerMemoria(ENDERECO, end_celula);
  Serial.print(RDADOS);
}

void loop() {}
