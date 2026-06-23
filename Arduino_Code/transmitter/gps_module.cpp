#include "gps_module.h"

//---------------------------------------------------------------
// Private GPS Object
//---------------------------------------------------------------

static TinyGPSPlus gps;

//---------------------------------------------------------------
// Initialize GPS
//---------------------------------------------------------------

void initGPS()
{
    GPS_SERIAL.begin(
        GPS_BAUD_RATE,
        SERIAL_8N1,
        GPS_RX_PIN,
        GPS_TX_PIN
    );

    Serial.println("--------------------------------");
    Serial.println("Initializing GPS Module...");
    Serial.println("--------------------------------");
}

//---------------------------------------------------------------
// Continuously Read GPS Data
//---------------------------------------------------------------

void updateGPS()
{
    while (GPS_SERIAL.available() > 0)
    {
        gps.encode(GPS_SERIAL.read());
    }
}

//---------------------------------------------------------------
// Check GPS Validity
//---------------------------------------------------------------

bool isGPSValid()
{
    return gps.location.isValid();
}

//---------------------------------------------------------------
// Get Latitude
//---------------------------------------------------------------

double getLatitude()
{
    if (gps.location.isValid())
    {
        return gps.location.lat();
    }

    return 0.0;
}

//---------------------------------------------------------------
// Get Longitude
//---------------------------------------------------------------

double getLongitude()
{
    if (gps.location.isValid())
    {
        return gps.location.lng();
    }

    return 0.0;
}

//---------------------------------------------------------------
// Get Latitude as String
//---------------------------------------------------------------

String getLatitudeString()
{
    if (!gps.location.isValid())
    {
        return "0.000000";
    }

    return String(gps.location.lat(), 6);
}

//---------------------------------------------------------------
// Get Longitude as String
//---------------------------------------------------------------

String getLongitudeString()
{
    if (!gps.location.isValid())
    {
        return "0.000000";
    }

    return String(gps.location.lng(), 6);
}

//---------------------------------------------------------------
// Print GPS Information
//---------------------------------------------------------------

void printGPSInfo()
{
    if (!gps.location.isValid())
    {
        Serial.println("Waiting for GPS Fix...");
        return;
    }

    Serial.println("========== GPS DATA ==========");

    Serial.print("Latitude  : ");
    Serial.println(getLatitudeString());

    Serial.print("Longitude : ");
    Serial.println(getLongitudeString());

    if (gps.satellites.isValid())
    {
        Serial.print("Satellites: ");
        Serial.println(gps.satellites.value());
    }

    if (gps.hdop.isValid())
    {
        Serial.print("HDOP      : ");
        Serial.println(gps.hdop.hdop());
    }

    if (gps.altitude.isValid())
    {
        Serial.print("Altitude  : ");
        Serial.print(gps.altitude.meters());
        Serial.println(" m");
    }

    Serial.println("==============================");
}