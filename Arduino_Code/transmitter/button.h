#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "config.h"

/**
 * @brief Initialize SOS button.
 *
 * Configures GPIO as INPUT_PULLUP.
 */
void initButton();

/**
 * @brief Check whether the SOS button has been pressed.
 *
 * Uses software debouncing to eliminate false triggering.
 *
 * @return true  Button pressed
 * @return false Button not pressed
 */
bool isButtonPressed();

#endif // BUTTON_H