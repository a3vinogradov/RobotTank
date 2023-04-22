#ifndef file_CMotorEncoder
#define file_CMotorEncoder

class CMotorEncoder {
private:
  int _signalPin;
  unsigned long _tmr;
  unsigned long _tmrSet;
  unsigned int _count;
  bool _state;
public:
  CMotorEncoder(int signalPin);
  void Setup();
  void Exec();
  unsigned int GetCount();
};

#endif