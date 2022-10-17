#ifndef file_CTimer
#define file_CTimer
#include <Arduino.h>

class CTimer
{
  private:
  uint32_t _Period;
  uint32_t _LastTime;
  bool _Active;

  public:
	CTimer();
	void SetDelay(uint32_t value);
  void Start();
  void ReStart();
	bool IsActive();
};

#endif
