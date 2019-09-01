#include <Arduino.h>
#include <pins_arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <Wire.h>
//#### Screen SETUP ######
#include "SPI.h"
#include <TFT_eSPI.h>
#define BACKLIGHT_CHANNEL   ((uint8_t)1)
#define TFT_BL              12
TFT_eSPI tft = TFT_eSPI();   // Invoke library
//########################
#include "CMMC_buzzer.h"

KB_music music;



void setup()
{
  // Wire.begin(TOUCH_SDA, TOUCH_SCL);
  // Wire1.begin(SENSOR_SDA, SENSOR_SCL);
  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, -1); 

  ledcAttachPin(TFT_BL, 1);
  ledcSetup(BACKLIGHT_CHANNEL, 12000, 8);
  ledcWrite(BACKLIGHT_CHANNEL, 255);

  tft.init();
  tft.fillScreen(0xFFFF);
  tft.setRotation(0);
  tft.setTextSize(1);
  tft.setSwapBytes(true);

  music.begin();
  pinMode(USER_BUTTON,INPUT_PULLUP);

}
void loop()
{
    if (digitalRead(USER_BUTTON) == 0) {
    music.song((std::vector<int>{262,523,220,440,233,466,-1,-1,175,349,147,294,156,311,-1,-1,175,349,147,294,156,311,-1,-1,175,349,147,294,156,311,-1,-1,311,277,294,277,311,311,208,196,277,262,370,349,165,466,440,415,311,247,233,220,208}),250);
  }

  
}
