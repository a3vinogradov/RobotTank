#ifndef file_FlySkyReceiver
#define file_FlySkyReceiver

#include <Arduino.h>
#include <SoftwareSerial.h>

#define IBUS_BUFFSIZE 32    // Max iBus packet size (2 byte header, 14 channels x 2 bytes, 2 byte checksum)
#define IBUS_MAXCHANNELS 6 // My TX only has 10 channels, no point in polling the rest

struct FlySkyData
{
  uint16_t ch[IBUS_MAXCHANNELS] = {0};
};
 
class FlySkyReceiver
{
  private:
    int _pinRX;
    int _pinTX;
    SoftwareSerial _mySerial;

    uint8_t ibusIndex = 0;
    uint8_t ibus[IBUS_BUFFSIZE] = {0};
    uint16_t rcValue[IBUS_MAXCHANNELS]={1500};
    
    void readRx();
    uint_fast16_t CalcCheckSum();
    uint_fast16_t GetCheckSum();     

  public:
    FlySkyReceiver(int pinRX, int pinTX);
    void Setup();
    void Exec();

    FlySkyData GetDefaultData();
    FlySkyData GetCurData(); 
    bool IsEqual(FlySkyData value);   
};

#endif