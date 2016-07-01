//
// AXR_1_Alpha_Firmware_ATMEGA328
//
// AXR-1 Firmware for Linduino
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Thomas Sevilla
// 				Thomas Sevilla
//
// Date			7/1/16 1:23 PM
// Version		<#version#>
//
// Copyright	© Thomas Sevilla, 2016
// Licence		<#licence#>
//
// See         ReadMe.txt for references
//


// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
    #include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
    #include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
    #include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
    #include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
    #include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
    #include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
    #include "Arduino.h"
#elif defined(SPARK) || defined(PARTICLE) // Particle / Spark specific
    #include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
    #include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
    #include "Arduino.h"
#elif defined(ESP8266) // ESP8266 specific
    #include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
    #include "Arduino.h"
#else // error
    #error Platform not defined
#endif // end IDE

// Set parameters


// Include application, user and local libraries


// Prototypes


// Define variables and constants


// Add setup code
void setup()
{
    ;
}

// Add loop code
void loop()
{
    ;
}
