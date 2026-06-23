#ifndef LORA_MODULE_H
#define LORA_MODULE_H

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include "config.h"

/**
 * @brief Initializes the LoRa module.
 *
 * Configures SPI pins and starts the SX1278 LoRa module.
 *
 * @return true  Initialization successful
 * @return false Initialization failed
 */
bool initLoRa();

/**
 * @brief Sends a raw string packet over LoRa.
 *
 * @param packet Packet to transmit.
 * @return true  Packet transmitted successfully.
 * @return false Transmission failed.
 */
bool sendPacket(const String &packet);

/**
 * @brief Creates an SOS packet using latitude and longitude.
 *
 * Packet Format:
 * SOS,11.025643,76.958742
 *
 * @param latitude  Latitude string
 * @param longitude Longitude string
 * @return Formatted SOS packet
 */
String createSOSPacket(const String &latitude,
                       const String &longitude);

/**
 * @brief Sends an SOS packet over LoRa.
 *
 * Internally creates the packet and transmits it.
 *
 * @param latitude  Latitude string
 * @param longitude Longitude string
 * @return true  Packet sent successfully
 * @return false Packet transmission failed
 */
bool sendSOS(const String &latitude,
             const String &longitude);

#endif // LORA_MODULE_H