#ifndef LORA_RECEIVER_H
#define LORA_RECEIVER_H

#ifndef LORA_RECEIVER_H
#define LORA_RECEIVER_H

#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#include "config.h"

/**
 * @brief Structure representing an SOS packet.
 */
struct SOSPacket
{
    String type;
    String latitude;
    String longitude;
};

/**
 * @brief Initialize the LoRa receiver.
 *
 * Configures SPI, initializes SX1278,
 * and places the radio into receive mode.
 *
 * @return true  Initialization successful.
 * @return false Initialization failed.
 */
bool initLoRaReceiver();

/**
 * @brief Check if a new LoRa packet has been received.
 *
 * @return true  Packet available.
 * @return false No packet.
 */
bool isPacketAvailable();

/**
 * @brief Read the received LoRa packet.
 *
 * @return Packet as a String.
 */
String receivePacket();

/**
 * @brief Parse an SOS packet.
 *
 * Expected format:
 * SOS,Latitude,Longitude
 *
 * @param packet Raw received packet.
 * @param data Output parsed packet.
 *
 * @return true  Packet parsed successfully.
 * @return false Invalid packet.
 */
bool parseSOSPacket(const String &packet, SOSPacket &data);

/**
 * @brief Print packet information to Serial Monitor.
 *
 * @param data Parsed SOS packet.
 */
void printSOSPacket(const SOSPacket &data);

#endif // LORA_RECEIVER_H