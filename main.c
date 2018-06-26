// Include NeoPixel driver
#include "neopixel.h"

// Include mode definitions
#include "modes.h"

// Include colour pallete
#include "pallete.h"

bool isOn; // Variable telling us if the LEDs are on

// Load a rainbow pattern into the array
void rainbow(void)
{
    uint8_t half = 255 >> 1;
    uint8_t quarter = half >> 1;
    uint8_t eighth = quarter >> 1;
    
    redArray[0] = 255;
    redArray[1] = 255 - eighth;
    redArray[2] = half + quarter;
    redArray[3] = half + eighth;
    redArray[4] = half;
    redArray[5] = quarter + eighth;
    redArray[6] = quarter;
    redArray[7] = eighth;
    redArray[8] = 0;
    redArray[9] = 0;
    redArray[10] = 0;
    redArray[11] = 0;
    redArray[12] = 0;
    redArray[13] = 0;
    redArray[14] = 0;
    redArray[15] = 0;
    redArray[16] = 0;
    redArray[17] = eighth;
    redArray[18] = quarter;
    redArray[19] = quarter + eighth;
    redArray[20] = half;
    redArray[21] = half + eighth;
    redArray[22] = half + quarter;
    redArray[23] = 255 - eighth;
    
    greenArray[0] = 0;
    greenArray[1] = eighth;
    greenArray[2] = quarter;
    greenArray[3] = quarter + eighth;
    greenArray[4] = half;
    greenArray[5] = half + eighth;
    greenArray[6] = half + quarter;
    greenArray[7] = 255 - eighth;
    greenArray[8] = 255;
    greenArray[9] = 255 - eighth;
    greenArray[10] = half + quarter;
    greenArray[11] = half + eighth;
    greenArray[12] = half;
    greenArray[13] = quarter + eighth;
    greenArray[14] = quarter;
    greenArray[15] = eighth;
    greenArray[16] = 0;
    greenArray[17] = 0;
    greenArray[18] = 0;
    greenArray[19] = 0;
    greenArray[20] = 0;
    greenArray[21] = 0;
    greenArray[22] = 0;
    greenArray[23] = 0;
    
    blueArray[0] = 0;
    blueArray[1] = 0;
    blueArray[2] = 0;
    blueArray[3] = 0;
    blueArray[4] = 0;
    blueArray[5] = 0;
    blueArray[6] = 0;
    blueArray[7] = 0;
    blueArray[8] = 0;
    blueArray[9] = eighth;
    blueArray[10] = quarter;
    blueArray[11] = quarter + eighth;
    blueArray[12] = half;
    blueArray[13] = half + eighth;
    blueArray[14] = half + quarter;
    blueArray[15] = 255 - eighth;
    blueArray[16] = 255;
    blueArray[17] = 255 - eighth;
    blueArray[18] = half + quarter;
    blueArray[19] = half + eighth;
    blueArray[20] = half;
    blueArray[21] = quarter + eighth;
    blueArray[22] = quarter;
    blueArray[23] = eighth;
}

void fade(uint8_t arraySize)
{
    // Fades through all the colours in an array
    for (uint8_t i = 0; i < arraySize; i++)
    {
        neoRGB(redArray[i], greenArray[i], blueArray[i], maxLEDs);
        __delay_ms(45);
    }
}

void strobe(uint8_t arraySize)
{
    // Similar to fade, except it's a more flashy strobe light effect
    for (uint8_t i = 0; i < arraySize; i++)
    {
        neoRGB(redArray[i], greenArray[i], blueArray[i], maxLEDs);
        __delay_ms(5);
    }
}

int main(void)
{
    // Initialize oscillator and I/O
    initOsc();
    initPorts();
    rainbow(); // Load the array with the rainbow pattern
    isOn = false; // Start off
    __delay_ms(1);
    
    // Main loop
    while (true)
    {
        // Power button
        if (S2 == 0)
        {
            isOn = !isOn; // Flip the value of isOn
            __delay_ms(100);
        }
        
        // Switch between modes
        if (S3 == 0)
        {
            // Increment through modes
            if (mode >= MAX_MODE)
                mode = 0; // Loop back to the first mode
            else
                mode++; // Increment the mode
            
            __delay_ms(100);
        }
        if (S4 == 0)
        {
            // Decrement through modes
            if (mode <= 0)
                mode = MAX_MODE; // Loop back to last mode
            else
               mode--;
            
            __delay_ms(100);
        }
        
        if (isOn)
        {
             //LEDs are on, so they should be lit up
             //Set LEDs based off of current mode
            switch (mode)
            {
                case SOLID_RED:
                    neoRGB(RED, maxLEDs);
                    break;
                case SOLID_ORANGE:
                    neoRGB(ORANGE, maxLEDs);
                    break;
                case SOLID_GOLD:
                    neoRGB(GOLD, maxLEDs);
                    break;
                case SOLID_YELLOW:
                    neoRGB(YELLOW, maxLEDs);
                    break;
                case SOLID_GREEN:
                    neoRGB(GREEN, maxLEDs);
                    break;
                case SOLID_TEAL:
                    neoRGB(TEAL, maxLEDs);
                    break;
                case SOLID_AQUA:
                    neoRGB(AQUA, maxLEDs);
                    break;
                case SOLID_BLUE:
                    neoRGB(BLUE, maxLEDs);
                    break;
                case SOLID_PURPLE:
                    neoRGB(PURPLE, maxLEDs);
                    break;
                case SOLID_MAGENTA:
                    neoRGB(MAGENTA, maxLEDs);
                    break;
                case SOLID_WHITE:
                    neoRGB(WHITE, maxLEDs);
                    break;
                case RAINBOW:
                    neoArray(24, maxLEDs, 0);
                    break;
                case SCROLL_RAINBOW:
                    neoArray(24, maxLEDs, -1);
                    break;
                case FADE:
                    fade(24);
                    break;
                case STROBE:
                    strobe(24);
                    break;
            }
        }
        else
            // LEDs should be off
            neoRGB(0, 0, 0, maxLEDs);
        __delay_ms(25);
        
        // Go to bootloader
        if (S1 == 0)
        {
            asm("movlp 0x00");
            asm("goto 0x001C");
        }
    }
}
