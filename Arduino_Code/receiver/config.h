#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

/*---------------------------------------------------------------
  Serial Configuration
----------------------------------------------------------------*/

constexpr uint32_t SERIAL_BAUD_RATE = 115200;

/*---------------------------------------------------------------
  LoRa Module (SX1278)
----------------------------------------------------------------*/

// SPI Pins
constexpr uint8_t LORA_SCK_PIN = 18;
constexpr uint8_t LORA_MISO_PIN = 19;
constexpr uint8_t LORA_MOSI_PIN = 23;

// Control Pins
constexpr uint8_t LORA_SS_PIN = 5;
constexpr uint8_t LORA_RST_PIN = 14;
constexpr uint8_t LORA_DIO0_PIN = 26;

// Frequency (Must match transmitter)
constexpr long LORA_FREQUENCY = 433E6;

// Optional Sync Word (Must match transmitter)
constexpr uint8_t LORA_SYNC_WORD = 0xF3;

/*---------------------------------------------------------------
  Packet Configuration
----------------------------------------------------------------*/

// Expected Packet Prefix
const String SOS_PREFIX = "SOS";

// Packet Delimiter
const char PACKET_SEPARATOR = ',';

// Maximum packet length
constexpr uint8_t MAX_PACKET_LENGTH = 64;

#endif // CONFIG_H