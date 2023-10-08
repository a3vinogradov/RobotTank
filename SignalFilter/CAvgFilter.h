#ifndef file_CAvgFilter
#define file_CAvgFilter

class CAvgFilter
{
  private:

    int _bufSize;
    int _curIndex;

    int NextIndex();
  public:
    int _buf[10];

    CAvgFilter(int count = 3);
    float GetValue(float value);
};

#endif