#ifndef file_CAvgFilter
#define file_CAvgFilter

class CAvgFilter
{
  private:
    int _buf[10];
    int _bufSize;
    int _curIndex;

    int NextIndex();
  public:
    CAvgFilter(int count = 3);
    float GetValue(float value);
};

#endif