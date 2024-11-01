#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

/* Get k-th element of priority queue (1 <= k <= 3)
  First element to pop is on level 0 (mData[0])
  Second element are on level 1
  - mLess(mData[2], mData[1]) is true, mData[1] is second element
  - mLess(mData[1], mData[2]) is true, mData[2] is second element
  Third element are on level 1 or level 2 of second element
  - mData[1] is second element --> Compare mData[2], mData[3], mData[4]
  - mData[2] is second element --> Compare mData[1], mData[5], mData[6] */
template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  // First Node
  if(k == 1) return mData[0];

  if(mLess(mData[2], mData[1]))
  {
    // Second Node
    if(k == 2) return mData[1];

    // Third Node
    if(mLess(mData[4], mData[3]))
    {
      if(mLess(mData[3], mData[2])) return mData[2];
      return mData[3];
    }
    if(mLess(mData[4], mData[2])) return mData[2];
    return mData[4];
  }
  // Second Node
  if(k == 2) return mData[2];

  // Third Node
  if(mLess(mData[6], mData[5]))
  {
    if(mLess(mData[5], mData[1])) return mData[1];
    return mData[5];
  }
  if(mLess(mData[6], mData[1])) return mData[1];
  return mData[6];
}

#endif