#include "config.h"
#include "lora_receiver.h"

/*--------------------------------------------------------------
                    Function Prototypes
--------------------------------------------------------------*/
void initializeSystem();
void receiveSOSPackets();

/*--------------------------------------------------------------
                        SETUP
--------------------------------------------------------------*/
void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    while (!Serial)
    {
        // Wait for Serial Monitor
    }

    Serial.println();
    Serial.println("========================================");
    Serial.println("   IoT SOS Tracking Device - Receiver");
    Serial.println("========================================");

    initializeSystem();
}

/*--------------------------------------------------------------
                        LOOP
--------------------------------------------------------------*/
void loop()
{
    receiveSOSPackets();
}

/*--------------------------------------------------------------
                Initialize Receiver
--------------------------------------------------------------*/
void initializeSystem()
{
    if (!initLoRaReceiver())
    {
        Serial.println();
        Serial.println("FATAL ERROR!");
        Serial.println("Unable to initialize LoRa Module.");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println();
    Serial.println("Receiver Ready...");
    Serial.println("Waiting for SOS Packets...");
}

/*--------------------------------------------------------------
                Receive Incoming Packets
--------------------------------------------------------------*/
void receiveSOSPackets()
{
    if (!isPacketAvailable())
    {
        return;
    }

    String packet = receivePacket();

    if (packet.length() == 0)
    {
        return;
    }

    Serial.println();
    Serial.println("----------------------------------------");
    Serial.print("Raw Packet : ");
    Serial.println(packet);

    SOSPacket sosData;

    if (parseSOSPacket(packet, sosData))
    {
        printSOSPacket(sosData);

        Serial.println();
        Serial.println("SOS Received Successfully!");
    }
    else
    {
        Serial.println();
        Serial.println("Invalid Packet Received!");
    }
}