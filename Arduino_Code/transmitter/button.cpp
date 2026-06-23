#include "button.h"

//---------------------------------------------------------------
// Static Variables
//---------------------------------------------------------------

static bool lastButtonState = BUTTON_RELEASED;
static bool buttonState = BUTTON_RELEASED;
static unsigned long lastDebounceTime = 0;

//---------------------------------------------------------------
// Initialize Button
//---------------------------------------------------------------

void initButton()
{
    pinMode(SOS_BUTTON_PIN, INPUT_PULLUP);

    Serial.println("--------------------------------");
    Serial.println("SOS Button Initialized");
    Serial.print("GPIO Pin : ");
    Serial.println(SOS_BUTTON_PIN);
    Serial.println("--------------------------------");
}

//---------------------------------------------------------------
// Check Button Press
//---------------------------------------------------------------

bool isButtonPressed()
{
    bool reading = digitalRead(SOS_BUTTON_PIN);

    // Button state changed
    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    // Debounce delay
    if ((millis() - lastDebounceTime) > BUTTON_DEBOUNCE_DELAY)
    {
        if (reading != buttonState)
        {
            buttonState = reading;

            // Button Pressed (Active LOW)
            if (buttonState == BUTTON_PRESSED)
            {
                lastButtonState = reading;

                Serial.println("SOS Button Pressed");

                return true;
            }
        }
    }

    lastButtonState = reading;

    return false;
}