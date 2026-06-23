# ESP32 Receiver

## Overview

The receiver unit continuously listens for incoming LoRa packets from the transmitter. Whenever an SOS packet is received, it extracts the GPS coordinates and displays them on the Serial Monitor along with a Google Maps link.

This receiver can later be extended to send the data to a cloud server, GSM module, Wi-Fi dashboard, or mobile application.

---

# Hardware Required

- ESP32 DevKit V1
- SX1278 LoRa Module (433 MHz)
- USB Cable
- Computer with Arduino IDE

---

# Pin Connections

## SX1278 LoRa Module

| LoRa Pin | ESP32 Pin |
|----------|-----------|
| NSS (CS) | GPIO5 |
| RST | GPIO14 |
| DIO0 | GPIO26 |
| SCK | GPIO18 |
| MISO | GPIO19 |
| MOSI | GPIO23 |
| VCC | 3.3V |
| GND | GND |

> **Important:** The SX1278 is a **3.3V device**. Do not connect it to 5V.

---

# Required Libraries

Install these libraries from the Arduino Library Manager:

- LoRa
- SPI (Built-in)

---

# Folder Structure

```text
receiver/
│
├── config.h
├── lora_receiver.h
├── lora_receiver.cpp
├── receiver.ino
└── README.md
```

---

# Packet Format

The receiver expects packets in the following format:

```text
SOS,<Latitude>,<Longitude>
```

### Example

```text
SOS,11.025643,76.958742
```

---

# Working

1. ESP32 starts.
2. Initializes the LoRa module.
3. Enters continuous receive mode.
4. Waits for an incoming packet.
5. When a packet arrives:
   - Reads the packet.
   - Verifies the format.
   - Extracts latitude and longitude.
   - Prints the coordinates.
   - Generates a Google Maps link.
   - Displays **"SOS Received Successfully!"**

---

# Sample Serial Output

```text
========================================
IoT SOS Tracking Device - Receiver
========================================

Initializing LoRa Receiver...

LoRa Receiver Initialized Successfully.

Receiver Ready...
Waiting for SOS Packets...

----------------------------------------
Raw Packet :
SOS,11.025643,76.958742

========================================
        SOS RECEIVED SUCCESSFULLY
========================================

Message Type : SOS

Latitude     : 11.025643

Longitude    : 76.958742

----------------------------------------
Google Maps :
https://maps.google.com/?q=11.025643,76.958742

========================================

SOS Received Successfully!
```

---

# Future Improvements

The receiver can be enhanced by integrating:

- 📱 GSM Module (SIM800L/SIM7600) for SMS alerts
- 🌐 Wi-Fi dashboard
- ☁️ Firebase Cloud Database
- 📍 Live GPS tracking on Google Maps
- 📲 Android application
- 🚑 Automatic emergency service notification
- 📡 LoRa mesh networking for extended coverage
- 🔋 Battery backup with charging circuit
- 📺 OLED/LCD display for standalone operation

---

# Troubleshooting

## LoRa Initialization Failed

- Check SPI wiring.
- Verify NSS, RST, and DIO0 connections.
- Ensure both modules use **433 MHz** hardware.
- Confirm transmitter and receiver use the same frequency and sync word.

---

## No Packet Received

- Verify the transmitter is powered on.
- Ensure both devices are within LoRa range.
- Check antenna connections.
- Confirm both devices use identical LoRa settings.

---

## Invalid Packet Received

- Ensure the transmitter sends packets in the format:

```text
SOS,<Latitude>,<Longitude>
```

---

# Project Information

**Project Title**

**IoT-Based SOS Tracking Device for Hill Stations Using ESP32, GPS, and LoRa**

---

# Author

**Mrunali Jibhakate**

Final Year B.Tech Engineering Project