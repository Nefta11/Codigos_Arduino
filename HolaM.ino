#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int potentiometerPin = A0; // Pin analógico donde está conectado el potenciómetro

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hola mundo..!!");
  lcd.setCursor(0, 1);
  lcd.print("Neftali 4A DSM");
  Serial.begin(9600); // Inicializa la comunicación serie

}

void loop() {
  int potValue = analogRead(potentiometerPin); // Lee el valor del potenciómetro
  float voltage = potValue * (5.0 / 1023.0); // Convierte el valor a voltaje (si el potenciómetro es de 5V)
  Serial.print("Potenciometro: ");
  Serial.print(potValue);
  Serial.print(", Voltaje: ");
  Serial.println(voltage);

  delay(1000); // Pausa de un segundo
}
