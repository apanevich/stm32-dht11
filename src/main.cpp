#include <Arduino.h>
#include <DHT.h>

// Настройки DHT11
#define DHT_PIN PB1  
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // Инициализация USB Serial
  Serial.begin(115200);
  
  // ОЖИДАНИЕ: Ждем, пока компьютер распознает USB-порт (до 5 секунд)
  // Без этого вы не увидите первые сообщения в мониторе порта
  unsigned long startWait = millis();
  while (!Serial && (millis() - startWait < 5000)) {
    delay(10);
  }

  Serial.println("\nSTM32F103C8T6 - USB-CDC Mode");
  Serial.println("DHT11 Temperature and Humidity Sensor");
  Serial.println("=====================================================");
  
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
