// このスケッチは Nefry BT のライブラリを使用しています。
// メニューのPreferenceから、環境設定のダイアログを開いて
// 追加のボードマネージャのURLに http://nefry.studio/package_nefrybt_index.json
// を入力してから、ボードマネージャから Nefry(ESP32) をインストールしてください。
// ボードは Nefry(ESP32)Module > ESP32 DevModule を選択してください。

#include <Nefry.h>
#include "remocon.h"

// Nefry BT で予約済みのピンは使えません(0, 4, 16)
// I2C SDA:21, SCL:22
// SPI CS:25, SCK:18, MISO:19, MOSI:23
// AD A3:39, A4:32, A5:33, A6: 34, A7:35, A12:2,
//    A13:15, A14:13, A15:12, A16:14, A17:27, A18:25, A19:26

const char type[] PROGMEM = "text/html";

void setup() {
  Nefry.setProgramName("YHRemocon");//プログラム名登録
  Nefry.getWebServer()->on("/remocon.html",  [&]() {
    Nefry.getWebServer()->send(200, "text/html", REMOCON_HTML);
  });
  Nefry.setIndexLink("Remocon", "/remocon.html");
  Nefry.getWebServer()->on("/button",  [&]() {
    Nefry.getWebServer()->send(200, "text/html", onButton() ? "Success" : "Failed");
  });
  Serial.begin(115200);
}

void loop() {
}

boolean onButton() {
  ESP32WebServer* server = Nefry.getWebServer();
  String id = server->arg("id");
  String val = server->arg("val");
  Serial.println("id:" + id + ", val:" + val);
  return true;
}

