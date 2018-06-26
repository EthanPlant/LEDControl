#include "neopixel.h"

// Sets requested number of LEDs to the same RGB value
void neoRGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t leds)
{
    // Repeat all colour bits for each LED
    for (leds; leds != 0; leds--)
    {
        // Send green data to LEDs
        temp = green;
        for (uint8_t i = 8; i != 0; i--)
        {
            asm("bsf LATC, 0");
            asm("nop");
            asm("nop");
            asm("btfss _temp, 7");
            asm("bcf LATC, 0");
            asm("nop");
            asm("lslf _temp, f");
            asm("bcf LATC, 0");
        }
        // Send red data to LEDs
        temp = red;
        for (uint8_t i = 8; i !=0; i--)
        {
            asm("bsf LATC, 0");
            asm("nop");
            asm("nop");
            asm("btfss _temp, 7");
            asm("bcf LATC, 0");
            asm("nop");
            asm("lslf _temp, f");
            asm("bcf LATC, 0");
        }
        // Send blue data to LEDs
        temp = blue;
        for (uint8_t i = 8; i !=0; i--)
        {
            asm("bsf LATC, 0");
            asm("nop");
            asm("nop");
            asm("btfss _temp, 7");
            asm("bcf LATC, 0");
            asm("nop");
            asm("lslf _temp, f");
            asm("bcf LATC, 0");
        }
    }
}

// Send array data to a NeoPixel strip
void neoArray(uint8_t arraySize, uint8_t leds, int8_t offset)
{
    // Check to make sure we aren't out of bounds
    if (arrayIndex >= arraySize)
        arrayIndex = 0;
    
    int8_t tempIndex = arrayIndex;
    
    // Send colour data to the LEDs
    
    // Repeat all colour bits for each LED
    for (leds; leds != 0; leds--)
    {
        // Send green data to LEDs
        temp = greenArray[arrayIndex];
        for (uint8_t i = 8; i != 0; i--)
        {
            asm("bsf LATC, 0");
            asm("nop");
            asm("nop");
            asm("btfss _temp, 7");
            asm("bcf LATC, 0");
            asm("nop");
            asm("lslf _temp, f");
            asm("bcf LATC, 0");
        }
        // Send red data to LEDs
        temp = redArray[arrayIndex];
        for (uint8_t i = 8; i !=0; i--)
        {
            asm("bsf LATC, 0");
            asm("nop");
            asm("nop");
            asm("btfss _temp, 7");
            asm("bcf LATC, 0");
            asm("nop");
            asm("lslf _temp, f");
            asm("bcf LATC, 0");
        }
        // Send blue data to LEDs
        temp = blueArray[arrayIndex];
        for (uint8_t i = 8; i !=0; i--)
        {
            asm("bsf LATC, 0");
            asm("nop");
            asm("nop");
            asm("btfss _temp, 7");
            asm("bcf LATC, 0");
            asm("nop");
            asm("lslf _temp, f");
            asm("bcf LATC, 0");
        }
        
        arrayIndex++;
        if (arrayIndex == arraySize)
            arrayIndex = 0;
    }
    
    arrayIndex = tempIndex;
    arrayIndex += offset;
    if (arrayIndex >= arraySize)
        arrayIndex = 0;
    if (arrayIndex < 0)
        arrayIndex = arraySize - 1;
}