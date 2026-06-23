#include "config.h"
#include "gps_module.h"
#include "lora_module.h"
#include "button.h"
#include "buzzer.h"

/*--------------------------------------------------------------
                    Function Prototypes
--------------------------------------------------------------*/
void initializeSystem();
void processSOSRequest();

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
    Serial.println("=======================================");
    Serial.println(" IoT SOS Tracking Device - Transmitter ");
    Serial.println("=======================================");

    initializeSystem();
}

/*--------------------------------------------------------------
                        LOOP
--------------------------------------------------------------*/
void loop()
{
    // Keep GPS parser updated
    updateGPS();

    // Check if SOS button is pressed
    if (isButtonPressed())
    {
        processSOSRequest();
    }
}

/*--------------------------------------------------------------
                Initialize All Modules
--------------------------------------------------------------*/
void initializeSystem()
{
    initGPS();

    initButton();

    initBuzzer();

    if (!initLoRa())
    {
        Serial.println();
        Serial.println("FATAL ERROR: Unable to initialize LoRa.");
        Serial.println("Check wiring and restart ESP32.");

        while (true)
        {
            // Continuous error indication
            buzzerOn();
            delay(200);

            buzzerOff();
            delay(200);
        }
    }

    Serial.println();
    Serial.println("System Initialization Complete.");
    Serial.println("Waiting for GPS Fix...");
}

/*--------------------------------------------------------------
                    Handle SOS Event
--------------------------------------------------------------*/
void processSOSRequest()
{
    Serial.println();
    Serial.println("=======================================");
    Serial.println("SOS Button Press Detected");
    Serial.println("=======================================");

    // Give audible confirmation
    beep();

    // Check GPS availability
    if (!isGPSValid())
    {
        Serial.println("ERROR: GPS Fix Not Available.");
        Serial.println("Move to an open sky and try again.");
        return;
    }

    // Read coordinates
    String latitude = getLatitudeString();
    String longitude = getLongitudeString();

    // Display coordinates
    Serial.print("Latitude  : ");
    Serial.println(latitude);

    Serial.print("Longitude : ");
    Serial.println(longitude);

    // Send SOS packet
    if (sendSOS(latitude, longitude))
    {
        Serial.println();
        Serial.println("SOS Packet Sent Successfully.");
    }
    else
    {
        Serial.println();
        Serial.println("Failed to Send SOS Packet.");
    }

    Serial.println("=======================================");
}