#include "buzzer.h"

//---------------------------------------------------------------
// Initialize Buzzer
//---------------------------------------------------------------

void initBuzzer()
{
    pinMode(BUZZER_PIN, OUTPUT);

    // Ensure buzzer is OFF initially
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("--------------------------------");
    Serial.println("Buzzer Initialized");
    Serial.print("GPIO Pin : ");
    Serial.println(BUZZER_PIN);
    Serial.println("--------------------------------");
}

//---------------------------------------------------------------
// Turn Buzzer ON
//---------------------------------------------------------------

void buzzerOn()
{
    digitalWrite(BUZZER_PIN, HIGH);
}

//---------------------------------------------------------------
// Turn Buzzer OFF
//---------------------------------------------------------------

void buzzerOff()
{
    digitalWrite(BUZZER_PIN, LOW);
}

//---------------------------------------------------------------
// Beep for Custom Duration
//---------------------------------------------------------------

void beep(uint16_t duration)
{
    buzzerOn();

    delay(duration);

    buzzerOff();
}

//---------------------------------------------------------------
// Beep Using Default Duration
//---------------------------------------------------------------

void beep()
{
    beep(BUZZER_ON_TIME);
}