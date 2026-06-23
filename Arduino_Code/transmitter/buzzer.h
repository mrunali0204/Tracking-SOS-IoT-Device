#ifndef BUZZER_H
#define BUZZER_H

#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "config.h"

/**
 * @brief Initialize the buzzer GPIO.
 *
 * Configures the buzzer pin as OUTPUT and
 * ensures it starts in the OFF state.
 */
void initBuzzer();

/**
 * @brief Turn the buzzer ON.
 */
void buzzerOn();

/**
 * @brief Turn the buzzer OFF.
 */
void buzzerOff();

/**
 * @brief Beep the buzzer for a specified duration.
 *
 * @param duration Duration in milliseconds.
 */
void beep(uint16_t duration);

/**
 * @brief Beep using the default duration defined
 *        in config.h.
 */
void beep();

#endif // BUZZER_H