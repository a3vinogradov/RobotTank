#include "FlySkyReceiver.h"

FlySkyReceiver::FlySkyReceiver(int pinRX, int pinTX) 
  : _mySerial(pinRX, pinTX)
{
  _pinRX = pinRX;
  _pinTX = pinTX;      

  ibusIndex = 0;
}

void FlySkyReceiver::Setup()
{
  _mySerial.begin(115200);
};

void FlySkyReceiver::Exec()
{
  readRx();
};

void FlySkyReceiver::readRx()
{
  if (_mySerial.available())
  {
    uint8_t val = _mySerial.read();
    // Look for 0x2040 as start of packet
    if (ibusIndex == 0 && val != 0x20)
    {
      ibusIndex = 0;
      return;
    }
    if (ibusIndex == 1 && val != 0x40) 
    {
      ibusIndex = 0;
      return;
    }

    if (ibusIndex == IBUS_BUFFSIZE)
    {
      ibusIndex = 0;

      if (GetCheckSum() == CalcCheckSum())       
      {      
        int high=3;
        int low=2;
        for(int i=0;i<IBUS_MAXCHANNELS; i++)
        {
          //left shift away the first 8 bits of the first byte and add the whole value of the previous one
          rcValue[i] = (ibus[high] << 8) + ibus[low];
          high += 2;
          low += 2;
        }
        
        return;
      }
    }
    else
    {
      ibus[ibusIndex] = val;
      ibusIndex++;
    }
  }
}

uint_fast16_t FlySkyReceiver::CalcCheckSum()
{
  uint_fast16_t result = 0xFFFF;
  result -= 0x20;
  result -= 0x40;
  for (int i = 2; i< 30; i++)
  {
    result -= ibus[i];
  }    

  return result;     
}

uint_fast16_t FlySkyReceiver::GetCheckSum()
{
  uint_fast16_t datal = ibus[30];  
  uint_fast16_t datah = ibus[31];  
  uint_fast16_t checksum = (datah << 8) | datal;
  return checksum;
}

FlySkyData FlySkyReceiver::GetDefaultData()
{
  FlySkyData res;
  for(int i=0; i<IBUS_MAXCHANNELS; i++)
  {
    res.ch[i] = 1500;   
  }  
  
  return res;
}

FlySkyData FlySkyReceiver::GetCurData()
{
  FlySkyData result;
  for(int i=0; i<IBUS_MAXCHANNELS; i++)
  {
    result.ch[i] = rcValue[i];   
  }  
  
  return result;
}    

bool FlySkyReceiver::IsEqual(FlySkyData value)
{
  bool res = true;
  for(int i=0; i<IBUS_MAXCHANNELS; i++)
  {
    if (value.ch[i] != rcValue[i])
    {
      res = false;
      break;
    };   
  }  

  return res;
}   


