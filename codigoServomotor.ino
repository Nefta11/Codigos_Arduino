#include <Servo.h>
#include <LiquidCrystal.h>

Servo myServo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pines de la pantalla LCD

int grados = 0; // Ángulo inicial
int servoPin = 8; // Cambia el pin del servo a 8
int boton1Pin = 6; // Cambia el pin del primer botón a 6
int boton2Pin = 7; // Cambia el pin del segundo botón a 7

void setup() {
  myServo.attach(servoPin);
  pinMode(boton1Pin, INPUT_PULLUP); // Habilitar resistencia pull-up interna para el botón 1
  pinMode(boton2Pin, INPUT_PULLUP); // Habilitar resistencia pull-up interna para el botón 2

  lcd.begin(16, 2); // Inicializa la pantalla LCD con 16 columnas y 2 filas
  lcd.setCursor(0, 0);
  lcd.print("Angulo: ");
  lcd.setCursor(0, 1);
}

void loop() {

  if (digitalRead(boton1Pin) == LOW) {
    int prev_grados = grados;
    grados += 30;
    if (grados > 180) {
      grados = 180;
    }
    imprimirMensaje(prev_grados, grados);
  } else if (digitalRead(boton2Pin) == LOW) {
    int prev_grados = grados;
    grados -= 30;
    if (grados < 0) {
      grados = 0;
    }
    imprimirMensaje(prev_grados, grados);
  }

  myServo.write(grados);

  lcd.setCursor(7, 0);
  lcd.print("    "); // Borrar el valor anterior
  lcd.setCursor(7, 0);
  lcd.print(grados);

  delay(100);
}

void imprimirMensaje(int prev, int actual) {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Borrar el mensaje anterior
  lcd.setCursor(0, 1);
  if (actual > prev) {
    lcd.print("Giro 30 grados");
  } else {
    lcd.print("Giro -30 grados");
  }
}
