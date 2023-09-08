#include "SimpleDHT.h" // biblioteca do sensor 
#include "LiquidCrystal_I2C.h" // biblioteca da tela lcd IIC LCD1602

LiquidCrystal_I2C lcd(0x27,16,2); // seta o endereço do LCD para 0x27 para 16 caracteres e 2 linhas

int pinDHT11 = 2; // pino que recebe as informações do sensor
SimpleDHT11 dht11; // cria um objeto do sensor DHT11

void setup() {
  lcd.init(); // inicia o LCD
}

void loop() {
  byte temperature = 0; // armazena a temperatura
  byte humidity = 0; // armazena a umidade
  byte data[40] = {0}; // bytes de dados

  // chama a função de leitura do sensor, se der erro, diz que a leitura falhou
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    lcd.setCursor(0, 0); // seta o cursor de escrita para o ponto (0, 0)
    lcd.print("Leitura falhou");
    return;
  }

  lcd.backlight(); // inicializa a luz de fundo do lcd
  lcd.setCursor(0, 0); // seta o cursor de escrita para o ponto (0, 0)
  lcd.print("Temperatura:  *C"); // printa esse texto na tela
  lcd.setCursor(12, 0); // seta o cursor de escrita para o ponto (12, 0)
  lcd.print((int)temperature); // printa a temperatura lida na tela
  lcd.setCursor(0, 1); // seta o cursor de escrita para o ponto (1, 0)
  lcd.print("Umidade:    %"); // printa esse texto na tela
  lcd.setCursor(9, 1); // seta o cursor de escrita para o ponto (10, 0)
  lcd.print((int)humidity); // printa a umidade lida na tela

  delay(1000); // aguarda 1 segundo
}