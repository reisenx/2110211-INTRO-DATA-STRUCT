#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // Create new mData
  auto newData = new T[mSize - pos.size()];
  /* Pointers
  - Given 'i' is a pointer in mData (always increase)
  - Given 'j' is a pointer in newData (increase when i not in pos)
  - Given 'k' is a pointer in pos (increase when i is in pos)
  NOTE: All items in pos do not have duplicates
  */
  int j = 0, k = 0;
  // Sort pos in ascending order
  std::sort(pos.begin(),pos.end());
  for(int i = 0; i < mSize; i++)
  {
    if(k < pos.size())
    {
      // If the index is not in pos, then put the data in newData and increase pointer j
      // To access element in index i, we need to use mData[(mFront+i)%mCap]
      if(i != pos[k]) { newData[j] = mData[(mFront+i)%mCap]; j++; }
      // If the index is in pos, then do not put the data in newData and increase pointer k
      else k++;
    }
    // if k is exceed pos.size(), just put every element to newData
    else { newData[j] = mData[(mFront+i)%mCap]; j++; }
  }
  // Assign new mData, mSize and mCap
  delete[] mData;
  mFront = 0;
  mData = newData;
  mSize -= pos.size();
  mCap = mSize;
}

#endif
