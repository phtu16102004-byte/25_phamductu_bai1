#include <Arduino.h>
#include "DHT.h"  // Thư viện DHT


#define DHTPIN 4       // Chân DATA của DHT11 nối GPIO 4
#define DHTTYPE DHT11  // Loại cảm biến là DHT11

// Tạo đối tượng DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); // Bật Serial để xem kết quả
  dht.begin();          // Khởi động cảm biến
  Serial.println("Bat dau doc du lieu tu DHT11...");
}

void loop() {
  
  float doAm = dht.readHumidity();        // Đọc độ ẩm
  float nhietDo = dht.readTemperature();  // Đọc nhiệt độ (°C)

 
  if (isnan(doAm) || isnan(nhietDo)) {
    Serial.println("Loi: Khong doc duoc du lieu tu DHT11!");
  } else {
   
    Serial.print("Nhiet do: ");
    Serial.print(nhietDo);
    Serial.print(" *C  |  Do am: ");
    Serial.print(doAm);
    Serial.println(" %");
  }

  delay(2000); 
}
