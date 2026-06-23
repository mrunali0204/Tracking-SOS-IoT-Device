#ifndef GPS_MODULE_H
#define GPS_MODULE_H

#ifndef GPS_MODULE_H
#define GPS_MODULE_H

#include <Arduino.h>
#include <TinyGPS++.h>
#include "config.h"

/**
 * @brief Initializes the GPS module.
 *
 * Starts the UART communication between the ESP32 and
 * the NEO-6M GPS module.
 */
void initGPS();

/**
 * @brief Reads incoming GPS data.
 *
 * This function should be called repeatedly inside loop()
 * to keep updating the GPS parser.
 */
void updateGPS();

/**
 * @brief Checks whether a valid GPS location is available.
 *
 * @return true  if GPS coordinates are valid
 * @return false otherwise
 */
bool isGPSValid();

/**
 * @brief Returns the latest latitude.
 *
 * @return Latitude in decimal degrees.
 */
double getLatitude();

/**
 * @brief Returns the latest longitude.
 *
 * @return Longitude in decimal degrees.
 */
double getLongitude();

/**
 * @brief Returns formatted latitude string.
 *
 * Example:
 * 11.025643
 */
String getLatitudeString();

/**
 * @brief Returns formatted longitude string.
 *
 * Example:
 * 76.958742
 */
String getLongitudeString();

/**
 * @brief Prints GPS information to Serial Monitor.
 *
 * Useful for debugging.
 */
void printGPSInfo();

#endif // GPS_MODULE_H