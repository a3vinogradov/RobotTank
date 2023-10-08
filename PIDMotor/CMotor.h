#ifndef file_CMotor
#define file_CMotor
class CMotor
{
  private:
    int _pinEnc;
    int _pinIN1;
    int _pinIN2;
  public:
  CMotor(int pinEnc, int pinIn1, int pinIn2);
  void Setup();
  void Exec();
};

#endif