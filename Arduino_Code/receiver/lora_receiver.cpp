#include "lora_receiver.h"

/*--------------------------------------------------------------
                    Initialize LoRa Receiver
--------------------------------------------------------------*/

bool initLoRaReceiver()
{
    Serial.println("----------------------------------------");
    Serial.println("Initializing LoRa Receiver...");
    Serial.println("----------------------------------------");

    SPI.begin(
        LORA_SCK_PIN,
        LORA_MISO_PIN,
        LORA_MOSI_PIN,
        LORA_SS_PIN);

    LoRa.setPins(
        LORA_SS_PIN,
        LORA_RST_PIN,
        LORA_DIO0_PIN);

    if (!LoRa.begin(LORA_FREQUENCY))
    {
        Serial.println("ERROR: LoRa Initialization Failed!");
        return false;
    }

    LoRa.setSyncWord(LORA_SYNC_WORD);
    LoRa.enableCrc();

    Serial.println("LoRa Receiver Initialized Successfully.");
    Serial.print("Frequency : ");
    Serial.print(LORA_FREQUENCY / 1000000);
    Serial.println(" MHz");

    return true;
}

/*--------------------------------------------------------------
                    Check Packet Availability
--------------------------------------------------------------*/

bool isPacketAvailable()
{
    return (LoRa.parsePacket() > 0);
}

/*--------------------------------------------------------------
                    Receive Packet
--------------------------------------------------------------*/

String receivePacket()
{
    String packet = "";

    while (LoRa.available())
    {
        packet += (char)LoRa.read();
    }

    packet.trim();

    return packet;
}

/*--------------------------------------------------------------
                    Parse SOS Packet
--------------------------------------------------------------*/

bool parseSOSPacket(const String &packet, SOSPacket &data)
{
    int firstComma = packet.indexOf(',');

    if (firstComma == -1)
    {
        return false;
    }

    int secondComma = packet.indexOf(',', firstComma + 1);

    if (secondComma == -1)
    {
        return false;
    }

    data.type = packet.substring(0, firstComma);

    data.latitude = packet.substring(
        firstComma + 1,
        secondComma);

    data.longitude = packet.substring(
        secondComma + 1);

    data.type.trim();
    data.latitude.trim();
    data.longitude.trim();

    if (data.type != SOS_PREFIX)
    {
        return false;
    }

    return true;
}

/*--------------------------------------------------------------
                    Print SOS Packet
--------------------------------------------------------------*/

void printSOSPacket(const SOSPacket &data)
{
    Serial.println();
    Serial.println("========================================");
    Serial.println("         SOS RECEIVED SUCCESSFULLY");
    Serial.println("========================================");

    Serial.print("Message Type : ");
    Serial.println(data.type);

    Serial.print("Latitude     : ");
    Serial.println(data.latitude);

    Serial.print("Longitude    : ");
    Serial.println(data.longitude);

    Serial.println("----------------------------------------");
    Serial.print("Google Maps  : ");

    Serial.print("https://maps.google.com/?q=");
    Serial.print(data.latitude);
    Serial.print(",");
    Serial.println(data.longitude);

    Serial.println("========================================");
}