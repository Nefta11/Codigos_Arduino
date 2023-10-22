#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "INFINITUM8EB8";
const char* password = "Yw5Jg6Sq8e";
String url = "http://192.168.1.78:3000/api/insertOne";
//Gola
void setup()
{
  Serial.begin(9600);
  delay(10);
  // Conectar WiFi
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("No se puede establecer la conexión con la red");
    delay(2000);
  }
}

void loop()
{
  HTTPClient http;
  WiFiClient client;
  if (http.begin(client, url)) //Iniciar conexión
  {
    Serial.println("[HTTP] POST...");
    http.addHeader("Content-Type", "application/json");
    String temperatura=getTemperatura();
    String humedad="45.0";
    String presion="99";
    String folio="5";
    int httpCode = http.POST(
      "{\"humidity\":17"
      ",\"temperaturec\":18" 
      ",\"temperaturef\":128" 
      ",\"heatindexc\":25"
      ",\"heatindexf\":52}"
    );  // Realizar petición

    if (httpCode > 0) {
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);

      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String respuesta = http.getString();  // Obtener respuesta
        Serial.println(respuesta);  // Mostrar respuesta por serial
      }
    }
    else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  else {
    Serial.printf("[HTTP} Unable to connect\n");
  }

  delay(20000);
}
String getTemperatura(){
  return "20";
}