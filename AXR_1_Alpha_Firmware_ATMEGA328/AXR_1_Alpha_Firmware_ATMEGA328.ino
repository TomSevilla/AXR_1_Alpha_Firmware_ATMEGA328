//
// AXR_1_Alpha_Firmware
//
// New AOML MK-21
//
// Author 		Thomas Sevilla
// 				Thomas Sevilla
//
// Date			6/28/16 5:48 PM
// Version		1.0
//
// Copyright	© Thomas Sevilla, 2016
//
// See         ReadMe.txt for references
//
#include "Wire.h"
#include <SPI.h>
#include "Adafruit_SI5351.h"

#define AD1 6

double volt;
double v_ref=5.001;

long int ltw=0;
unsigned long timer;

byte b0;
byte sig;

Adafruit_SI5351 clockGen = Adafruit_SI5351();

int get_user_input(){
    while(Serial.available()==0){
    }
    int selection = Serial.parseInt();
    return selection;
}

void SetUpClock(){
//Should add a check to make sure that the clock is there... This will be added later

clockGen.setupPLL(SI5351_PLL_A, 27, 15117, 15625);
clockGen.setupMultisynth(0, SI5351_PLL_A, 4, 1134, 1);
clockGen.setupRdiv(0, SI5351_R_DIV_2);
clockGen.enableOutputs(true);
    
}

double meassure(int cs) {
    
    digitalWrite(cs, LOW);
    
    if (!(PINB & (1 << 4))) {   //use !bit_is_set(PINB, PB3) if using MEGA2560
        ltw = 0;
        sig = 0;
        
        b0 = SPI.transfer(0x00);            // read 4 bytes adc raw data with SPI
        if ((b0 & 0x20) == 0) sig = 1; // is input negative ?
        b0 &= 0x1F;                  // discard bit 25..31
        ltw |= b0;
        ltw <<= 8;
        b0 = SPI.transfer(0x00);
        ltw |= b0;
        ltw <<= 8;
        b0 = SPI.transfer(0x00);
        ltw |= b0;
        ltw <<= 8;
        b0 = SPI.transfer(0x00);
        ltw |= b0;
        
        digitalWrite(cs, LOW);
        
        if (sig) ltw |= 0xf0000000;
        ltw = ltw / 16;
        volt = ltw * v_ref / 16777216;
        
    }
    
    digitalWrite(cs, HIGH);
    return (volt);
    
}

double check_res(){
   
}

double calc_res(double voltage){
    double resistance = voltage/0.0001;
    return resistance;
}

double calibrate(){

}

double correct(){
}

double run(int chip){
    double output;
    output = calc_res(meassure(chip));
    return output;
}

void diagnostics(){
    int wait =1;
    while(wait!=999){
        Serial.println("IN DIAGNOSTIC MODE!");
        Serial.println("1:Check ....");
        Serial.println("2:Check ....");
        Serial.println("3:Check ....");
        Serial.println("4:Check ....");
        Serial.println("9:EXIT");
        
        int inByte = get_user_input();
        
            switch (inByte) {
                case 1:
                    Serial.println("Test A");

                    break;
                case 2:
                    Serial.println("Test B");

                    break;
                case 3:
                    Serial.println("Test C");

                    break;
                case 4:
                    Serial.println("Test D");

                    break;
                case 9:
                    wait=999;
                    
                    break;
                default:
                    Serial.println("Test Default");

            }
        }
}


void setup()
{
    SetUpClock();
}

void loop()
{
    Serial.println(run(AD1));
}
