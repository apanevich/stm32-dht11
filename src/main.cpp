#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN PB1  
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // USB Serial initialization
  Serial.begin(115200);
  
  // Waiting for the computer to recognize the USB port
  unsigned long startWait = millis();
  while (!Serial && (millis() - startWait < 5000)) {
    delay(10);
  }

  Serial.println("\nSTM32F103C8T6 - USB-CDC Mode");
  Serial.println("DHT11 Temperature and Humidity Sensor");
  
  dht.begin();
}

void loop() {
  delay(2000);
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Could not read from DHT sensor!");
    return;
  }
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
