# ESP32 Transmitter

## Overview

The transmitter is the portable SOS device carried by the user. It continuously reads GPS coordinates from the NEO-6M GPS module and waits for the SOS push button to be pressed.

When the button is pressed:

1. Current GPS coordinates are obtained.
2. The buzzer beeps to confirm the button press.
3. An SOS packet is created.
4. The packet is transmitted using the SX1278 LoRa module.

The receiver can then display the user's location.

---

## Hardware Required

- ESP32 DevKit V1
- NEO-6M GPS Module
- SX1278 LoRa Module (433 MHz)
- Active Buzzer
- Push Button
- Jumper Wires
- Power Supply/Battery

---

## Pin Connections

### GPS Module

| GPS Pin | ESP32 Pin |
|----------|-----------|
| TX | GPIO16 |
| RX | GPIO17 |
| VCC | 3.3V |
| GND | GND |

---

### LoRa Module (SX1278)

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

---

### SOS Push Button

| Button Pin | ESP32 Pin |
|------------|-----------|
| One Side | GPIO4 |
| Other Side | GND |

> The code uses the ESP32's internal pull-up resistor (`INPUT_PULLUP`).

---

### Active Buzzer

| Buzzer Pin | ESP32 Pin |
|------------|-----------|
| Signal | GPIO2 |
| VCC | 3.3V (or 5V if supported) |
| GND | GND |

---

## Required Arduino Libraries

Install the following libraries from the Arduino Library Manager:

- TinyGPS++
- LoRa
- SPI (Built-in)

---

## Project Structure

```text
transmitter/
│
├── config.h
├── gps_module.h
├── gps_module.cpp
├── lora_module.h
├── lora_module.cpp
├── button.h
├── button.cpp
├── buzzer.h
├── buzzer.cpp
├── transmitter.ino
└── README.md
```

---

## SOS Packet Format

The transmitter sends the GPS location in the following format:

```text
SOS,<Latitude>,<Longitude>
```

### Example

```text
SOS,11.025643,76.958742
```

---

## Working

1. ESP32 powers ON.
2. GPS module starts receiving satellite data.
3. ESP32 continuously updates GPS coordinates.
4. System waits for the SOS button.
5. When the button is pressed:
   - Buzzer beeps.
   - Current latitude is read.
   - Current longitude is read.
   - SOS packet is created.
   - Packet is transmitted via LoRa.
6. The transmitter returns to standby mode.

---

## Serial Monitor Output

Example:

```text
=======================================
 IoT SOS Tracking Device - Transmitter
=======================================

Initializing GPS Module...

Initializing LoRa Module...

System Initialization Complete.

Waiting for GPS Fix...

SOS Button Pressed

Latitude  : 11.025643
Longitude : 76.958742

Preparing SOS Packet...
SOS,11.025643,76.958742

LoRa Packet Sent Successfully.
```

---

## Notes

- Wait until the GPS obtains a valid satellite fix before sending an SOS.
- Use the transmitter outdoors for the fastest GPS lock.
- Ensure both LoRa modules use the same frequency (433 MHz).
- Keep both transmitter and receiver powered using a stable power source.
- The ESP32 and SX1278 both operate at **3.3V**.

---

## Author

**Mrunali Jibhakate**

Final Year Engineering Project

**Project Title:**

**IoT-Based SOS Tracking Device for Hill Stations Using ESP32, GPS, and LoRa**