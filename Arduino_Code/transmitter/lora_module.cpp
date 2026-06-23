#include "lora_module.h"

//---------------------------------------------------------------
// Initialize LoRa Module
//---------------------------------------------------------------

bool initLoRa()
{
    Serial.println("--------------------------------");
    Serial.println("Initializing LoRa Module...");
    Serial.println("--------------------------------");

    // Initialize SPI with custom ESP32 pins
    SPI.begin(
        LORA_SCK_PIN,
        LORA_MISO_PIN,
        LORA_MOSI_PIN,
        LORA_SS_PIN
    );

    // Configure LoRa pins
    LoRa.setPins(
        LORA_SS_PIN,
        LORA_RST_PIN,
        LORA_DIO0_PIN
    );

    // Start LoRa
    if (!LoRa.begin(LORA_FREQUENCY))
    {
        Serial.println("ERROR: LoRa initialization failed!");
        return false;
    }

    // Optional radio settings
    LoRa.setSyncWord(0xF3);
    LoRa.enableCrc();
    LoRa.setTxPower(17);

    Serial.println("LoRa Initialized Successfully.");
    Serial.print("Frequency : ");
    Serial.print(LORA_FREQUENCY / 1000000);
    Serial.println(" MHz");

    return true;
}

//---------------------------------------------------------------
// Send Generic Packet
//---------------------------------------------------------------

bool sendPacket(const String &packet)
{
    if (packet.length() == 0)
    {
        Serial.println("ERROR: Empty packet.");
        return false;
    }

    LoRa.beginPacket();
    LoRa.print(packet);

    int status = LoRa.endPacket();

    if (status == 1)
    {
        Serial.println("--------------------------------");
        Serial.println("LoRa Packet Sent Successfully");
        Serial.print("Packet : ");
        Serial.println(packet);
        Serial.println("--------------------------------");

        return true;
    }

    Serial.println("ERROR: Packet transmission failed.");
    return false;
}

//---------------------------------------------------------------
// Create SOS Packet
//---------------------------------------------------------------

String createSOSPacket(const String &latitude,
                       const String &longitude)
{
    String packet = SOS_PREFIX;
    packet += ",";
    packet += latitude;
    packet += ",";
    packet += longitude;

    return packet;
}

//---------------------------------------------------------------
// Send SOS Packet
//---------------------------------------------------------------

bool sendSOS(const String &latitude,
             const String &longitude)
{
    // Validate GPS strings
    if (latitude == "0.000000" || longitude == "0.000000")
    {
        Serial.println("WARNING: Invalid GPS Coordinates.");
        return false;
    }

    String packet = createSOSPacket(latitude, longitude);

    Serial.println("Preparing SOS Packet...");
    Serial.println(packet);

    return sendPacket(packet);
}