#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "SSID";
const char *password = "PASSWORD";

// PCのIPアドレスを設定
const char* pc_ip = "192.168.0.100"; // PCのIPアドレスに置き換えてください

// Pingの設定
const int ping_timeout = 1000; // タイムアウト時間（ミリ秒）

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // WiFi接続の待機
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  // Pingの設定
  Ping.ping(pc_ip);
}

void loop() {
  // PCの状態を確認する
  bool is_online = Ping.ping(pc_ip);

  if (is_online) {
    Serial.println("PC is ONLINE");
  } else {
    Serial.println("PC is OFFLINE");
  }

  // 一定時間待機
  delay(5000); // 5秒ごとに状態を確認
}
