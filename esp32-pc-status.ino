#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "SSID";
const char *password = "PASSWORD";

void setup() {
  Serial.begin(115200);
  // Wi-Fiに接続
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("WiFiに接続中...");
  }
  Serial.println("WiFiに接続完了");
  Serial.println(WiFi.localIP());
}

void loop() {
  // ループ内では何もしません
}
