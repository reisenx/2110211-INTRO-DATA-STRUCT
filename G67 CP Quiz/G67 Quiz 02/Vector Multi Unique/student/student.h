#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include<vector>
#include<set>
#include<algorithm>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  std::set<T> uniqueElements;
  std::vector<int> posErase;
  
  /* Instructions
  1.) For each iterator, try to insert its value to uniqueElement.
  2.) If the insertion failed (check.second = false), duplicate element is detected.
  3.) When Duplicate element detected, push_back that iterator to posErase */
  sort(itrs.begin(), itrs.end());
  for(CP::vector<T>::iterator &it : itrs)
  {
    auto check = uniqueElements.insert(*it);
    if(!check.second) posErase.push_back(it - begin());
  }
  sort(posErase.begin(), posErase.end());

  // Assign new mData
  /* Pointers
  Given 'i' is a pointer of mData (Always increase)
  Given 'j' is a pointer of newData (Increase when assign an element)
  Given 'k' is a pointer of posErase (Increase when that erase index found) */
  T* newData = new T[mSize];
  int j = 0, k = 0;
  for(int i = 0; i < mSize; i++)
  {
    // k is not exceed posErase.size()
    if(k < posErase.size())
    {
      if(i == posErase[k]) k++;
      else { newData[j] = mData[i]; j++; }
    }
    // k is exceed posErase.size(), always assign the value
    else { newData[j] = mData[i]; j++; }
  }
  // Assign new mData, mSize, mCap
  delete[] mData;
  mData = newData;
  mSize = std::max((size_t)0, mSize - posErase.size());
  mCap = mSize;
}

#endif
