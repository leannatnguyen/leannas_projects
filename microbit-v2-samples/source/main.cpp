#include "MicroBit.h"
#include "samples/Tests.h"

MicroBit uBit;

int main()
{
    while (true) {
        uBit.display.image.setPixelValue(2, 2, 255); // Turn on center LED
        uBit.display.image.setPixelValue(0, 0, 255);  
        uBit.display.image.setPixelValue(4, 4, 255);  
        uBit.display.image.setPixelValue(0, 4, 255);
        uBit.display.image.setPixelValue(4, 0, 255);  
        uBit.sleep(500);
        uBit.display.image.setPixelValue(2, 2, 0);    // Turn off center LED
        uBit.display.image.setPixelValue(0, 0, 0);
        uBit.display.image.setPixelValue(4, 4, 0);
        uBit.display.image.setPixelValue(0, 4, 0);
        uBit.display.image.setPixelValue(4, 0, 0);
        uBit.sleep(500);
    }
    
}

