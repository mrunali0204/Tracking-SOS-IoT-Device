#ifndef CONFIG_H
#define CONFIG_H


#include <Arduino.h>

/*---------------------------------------------------------------
  Serial Configuration
----------------------------------------------------------------*/
constexpr uint32_t SERIAL_BAUD_RATE = 115200;

/*---------------------------------------------------------------
  GPS Configuration
----------------------------------------------------------------*/
#define GPS_SERIAL Serial2

constexpr uint8_t GPS_TX_PIN = 17;      // ESP32 TX -> GPS RX
constexpr uint8_t GPS_RX_PIN = 16;      // ESP32 RX <- GPS TX

constexpr uint32_t GPS_BAUD_RATE = 9600;

/*---------------------------------------------------------------
  SOS Button
----------------------------------------------------------------*/
constexpr uint8_t SOS_BUTTON_PIN = 4;

// Using internal pull-up
constexpr bool BUTTON_PRESSED = LOW;
constexpr bool BUTTON_RELEASED = HIGH;

constexpr uint16_t BUTTON_DEBOUNCE_DELAY = 50;

/*---------------------------------------------------------------
  Buzzer
----------------------------------------------------------------*/
constexpr uint8_t BUZZER_PIN = 2;
constexpr uint16_t BUZZER_ON_TIME = 1000;

/*---------------------------------------------------------------
  LoRa Module (SX1278)
----------------------------------------------------------------*/
constexpr uint8_t LORA_SS_PIN   = 5;
constexpr uint8_t LORA_RST_PIN  = 14;
constexpr uint8_t LORA_DIO0_PIN = 26;

constexpr uint8_t LORA_SCK_PIN  = 18;
constexpr uint8_t LORA_MISO_PIN = 19;
constexpr uint8_t LORA_MOSI_PIN = 23;

constexpr long LORA_FREQUENCY = 433E6;

/*---------------------------------------------------------------
  GPS Settings
----------------------------------------------------------------*/
constexpr uint32_t GPS_TIMEOUT_MS = 10000;

/*---------------------------------------------------------------
  Packet Format
  Example:
  SOS,11.025643,76.958742
----------------------------------------------------------------*/
const String SOS_PREFIX = "SOS";

#endif