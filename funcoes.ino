

void gravarMemoria(int endereco, unsigned int end_celula, byte w_dados) {
  Wire.beginTransmission(endereco);
  Wire.write((int)(end_celula >> 8));
  Wire.write((int)(end_celula & 0xFF));
  Wire.write(w_dados);
  Wire.endTransmission();
  delay(10);
}

/* byte  */ void lerMemoria(int endereco, unsigned int end_celula) {
  Wire.beginTransmission(endereco);
  Wire.write((int)(end_celula >> 8));
  Wire.write((int)(end_celula & 0xFF));
  Wire.endTransmission();
  delay(5);
  Wire.requestFrom(endereco, 1);
  //delay(10);
  if (Wire.available()) {
    RDADOS = Wire.read();
    digitalWrite(LED_CLONE_OK, HIGH);
  }
  //return rData;
}