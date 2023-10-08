#include "CAvgFilter.h"
    CAvgFilter::CAvgFilter(int count)
    {
      _bufSize = count;
      for (int i =0; i<_bufSize ; i++)
      {
        _buf[i] = 0;
      }
      _curIndex = 0;

    };

    float CAvgFilter::GetValue(float value)
    {
      _curIndex = NextIndex();
      _buf[_curIndex] = value;

      float summ = 0;
      for (int i =0; i<_bufSize ; i++)
      {
        summ += _buf[i];
      }
      return summ/_bufSize;
    };

    int CAvgFilter::NextIndex()
    {
      if (_bufSize - _curIndex == 1 )
      {
        return 0;
      }
      else
      {
        return _curIndex +1;
      }
    }