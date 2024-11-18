#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  /* Queue Vertical Split
  [1,2,3,4,5,6,7,8,9,10,11,12,13] --> [1,2,3] [4,5,6] [7,8,9] [10,11] [12,13]
  - Amount queue with size 3 (mSize/k + 1) is 3 (mSize mod k)
  - Amount queue with size 2 (mSize/k)     is 2 (k - (mSize mod k))
  */
  
  // Create pointer of mData
  int i = 0;
  // push_back queue with size (mSize/k + 1), (mSize mod k) times
  for(int count = 0; count < mSize%k; count++)
  {
    std::queue<T> temp;
    for(int amount = 0; amount < (mSize/k)+1; amount++) { temp.push(mData[(mFront+i)%mCap]); i++; }
    output.push_back(temp);
  }
  // push_back queue with size (mSize/k), (k - (mSize mod k)) times
  for(int count = 0; count < k-(mSize%k); count++)
  {
    std::queue<T> temp;
    for(int amount = 0; amount < mSize/k; amount++) { temp.push(mData[(mFront+i)%mCap]); i++; }
    output.push_back(temp);
  }
}

#endif
