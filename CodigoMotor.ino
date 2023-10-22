#include <DHT.h>
#include <Stepper.h>

// Definir el número de pasos por revolución del motor.
const int stepsPerRevolution = 2048;  // Este valor es para el motor 28BYJ-48.

// Crear una instancia del objeto Stepper.
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // Cambia el orden si es necesario.

// Definir el pin del sensor DHT11.
#define DHTPIN 2  // Cambia al pin que estás utilizando.
#define DHTTYPE DHT11

// Inicializar el sensor DHT.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializar el motor con la velocidad máxima.
  myStepper.setSpeed(10);

  // Inicializar la comunicación serial.
  Serial.begin(9600);
  
  // Inicializar el sensor DHT.
  dht.begin();
}

void loop() {
  // Leer la humedad y temperatura desde el sensor DHT.
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();

  // Verificar si la lectura del sensor fue exitosa.
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Error al leer el sensor DHT.");
    return;
  }

  // Mostrar la temperatura en el monitor serial.
  Serial.print("Temperatura (C): ");
  Serial.println(temperatureC);

  // Si la temperatura supera los 10 grados Celsius, enciende el motor girando más pasos.
  if (temperatureC > 20) {
    myStepper.step(stepsPerRevolution);  // Gira el motor 200 pasos en una dirección.
  }

  delay(1000);  // Pausa de un segundo entre las lecturas.
}
