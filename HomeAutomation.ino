#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp0;

char auth[] = "Blynk authentication code";
char ssid[] = "Wifi name";
char pass[] = "Password";
// Pin Configs:
int stairs = 1;
int HallL1 = 2;
int HallL2 = 3;
int HallF1 = 4;
int HallF2 = 5;
int HallBedL = 6;
int MasterBedRoomL = 7;
int MasterBedRoomF = 8;
int ChildBedRoomL = 9;
int ChildBedRoomF = 10;
int woofer = 11;
int tv = 12;

void setup () 
{
    // Initialize the MCP23017
    mcp0.begin (0);
    Serial.begin (9600);
    pinMode (A0, INPUT);
    // Define GPA0 (physical pin 21) as output pin
    mcp0.pinMode (stairs, OUTPUT);
    mcp0.pinMode (HallL1, OUTPUT);
    mcp0.pinMode (HallL2, OUTPUT);
    mcp0.pinMode (HallF1, OUTPUT);
    mcp0.pinMode (HallF2, OUTPUT);
    mcp0.pinMode (MasterBedRoomL, OUTPUT);
    mcp0.pinMode (MasterBedRoomF, OUTPUT);
    mcp0.pinMode (ChildBedRoomL, OUTPUT);
    mcp0.pinMode (ChildBedRoomF, OUTPUT);
    mcp0.pinMode (HallBedL, OUTPUT);
    Blynk.begin (auth, ssid, pass);
} 
void mcp () 
{
    byte error, address;
    int nDevices;
    Serial.println ("Scanning...");
    nDevices = 0;
    for (address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of
      // the Write.endTransmisstion to see if
      // a device did acknowledge to the address.
      Wire.beginTransmission (address);
      error = Wire.endTransmission ();
      if (error == 0)
      {
          Serial.print ("I2C device found at address 0x");
          if (address < 16)
          Serial.print ("0");
          Serial.print (address, HEX);
          Serial.println ("  !");
          nDevices++;
          
      }
      else if (error == 4)
      {
          Serial.print ("Unknown error at address 0x");
          if (address < 16)
              Serial.print ("0");
          Serial.println (address, HEX);
          
      }
        
    }
    if (nDevices == 0)
        Serial.println ("No I2C devices found\n");
    else
        Serial.println ("done\n");
        // wait 5 seconds for next scan
    delay (100);
    
}

void loop () 
{
    mcp ();
    stairs ();
    blynk ();
    
} 
 
void blynk () 
{
    Blynk.run ();
    
} 
void stairs () 
{
    int l = analogRead (A0);
    Serial.print ("Light=");
    Serial.println (l);
    if (l > 73)
        mcp0.digitalWrite (stairs, HIGH);
    else if (l < 65)
    {
        mcp0.digitalWrite (stairs, LOW);
        
    }
    
}

BLYNK_WRITE (V1)  //Stairs
{
    int value = param.asInt ();
    mcp0.digitalWrite (stairs, value);
} 
 
BLYNK_WRITE (V2)  //Hall L1
{
    int value = param.asInt ();
    mcp0.digitalWrite (HallL1, value);
    
} 
 
BLYNK_WRITE (V3)  //HallL2
{
    int value = param.asInt ();
    mcp0.digitalWrite (HallL2, value);
    
} 
 
BLYNK_WRITE (V4)  //HallF1
{
    int value = param.asInt ();
    mcp0.digitalWrite (HallF1, value);
} 
 
BLYNK_WRITE (V5)  //HallF2
{
    int value = param.asInt ();
    mcp0.digitalWrite (HallF2, value);
} 
 
BLYNK_WRITE (V6)  //HallBedL
{
    int value = param.asInt ();
    mcp0.digitalWrite (god, value);
} 
 
BLYNK_WRITE (V7)  //MasterBedRoomL
{
    int value = param.asInt ();
    mcp0.digitalWrite (MasterBedRoomL, value);
} 
 
BLYNK_WRITE (V8)  //MasterBedRoomF
{
    int value = param.asInt ();
    mcp0.digitalWrite (MasterBedRoomF, value);
} 
 
BLYNK_WRITE (V9)  //ChildBedRoomL
{
    int value = param.asInt ();
    mcp0.digitalWrite (ChildBedRoomL, value);
} 
BLYNK_WRITE (V10) //ChildBedRoomF
{
    int value = param.asInt ();
    mcp0.digitalWrite (ChildBedRoomF, value);
} 
BLYNK_WRITE (V13) //All off
{
    int value = 0;
    mcp0.digitalWrite (HallF1, value);
    mcp0.digitalWrite (HallF2, value);
    mcp0.digitalWrite (HallL1, value);
    mcp0.digitalWrite (HallL2, value);
    mcp0.digitalWrite (MasterBedRoomF, value);
    mcp0.digitalWrite (MasterBedRoomL, value);
    mcp0.digitalWrite (ChildBedRoomF, value);
    mcp0.digitalWrite (ChildBedRoomL, value);
    
} 
 
BLYNK_WRITE (V14) //woofer
{
    int value = param.asInt ();
    mcp0.digitalWrite (woofer, value);
    
} 
 
BLYNK_WRITE (V15) //tv
{
    int value = param.asInt ();
    mcp0.digitalWrite (tv, value);
} 
 
