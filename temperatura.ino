#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2      
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(5000);  

  float temperaturaCelsius = dht.readTemperature();  
  float humedad = dht.readHumidity();               

  if (isnan(temperaturaCelsius) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT11");
  } else {
    Serial.print("Temperatura (°C): ");
    Serial.print(temperaturaCelsius);
    Serial.println(" °C");
    
    float temperaturaFahrenheit = (temperaturaCelsius * 9.0 / 5.0) + 32.0;  // Conversión a grados Fahrenheit
    Serial.print("Temperatura (°F): ");
    Serial.print(temperaturaFahrenheit);
    Serial.println(" °F");

    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  }
}