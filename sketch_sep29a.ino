const int PIN_TRIGGER = 10;
const int PIN_ECO = 9;
const int PIN_BOCINA = 3;

void setup() {
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECO, INPUT);
  pinMode(PIN_BOCINA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Envia un pulso ultrasónico
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  // Mide la distancia
  long duracion = pulseIn(PIN_ECO, HIGH);
  int distancia = duracion / 58.2;

  // Imprime la distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Si la distancia es menor o igual a 150 cm, activa la bocina con intensidad controlada por PWM
  if (distancia <= 50 && distancia >= 0) {
    int intensidad = map(distancia, 0, 50, 255, 0); // Mapear la distancia a una intensidad PWM
    analogWrite(PIN_BOCINA, intensidad);
    delay(distancia * 10);
    analogWrite(PIN_BOCINA, 0); // Apagar la bocina
  }

  // Espera antes de la siguiente medición
  delay(200);
}
