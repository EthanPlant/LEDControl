/*==============================================================================
 UBMP2 NeoPixel driver with array function.
 =============================================================================*/

// Standard library includes
#include "stdint.h"
#include "stdbool.h"

// XC compiler include file
#include "xc.h"

// UBMP2 header
#include "UBMP2.h"

// Global variables for NeoPixel functions
uint8_t redArray[24];
uint8_t blueArray[24];
uint8_t greenArray[24];

const uint8_t maxLEDs = 60; // Maximum amount of LEDs in the strip

int8_t arrayIndex = 0; // Current position in array

uint8_t temp; // Temporary byte storage

void neoRGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t leds);
void neoArray(uint8_t arraySize, uint8_t leds, int8_t offfset);