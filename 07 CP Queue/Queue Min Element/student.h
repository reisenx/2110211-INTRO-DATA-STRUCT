#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  T minElement;
  bool hasInitial = false;
  for(auto &index: pos)
  {
    // Find initial value to compare
    if(!hasInitial && index >= 0 && index < mSize) 
    { 
      minElement = mData[(mFront+index)%mCap];
      hasInitial = true;
    }
    // Compare, if we have initial value to compare
    if(hasInitial && index >= 0 && index < mSize)
    {
      T element = mData[(mFront+index)%mCap];
      if(comp(element, minElement)) minElement = element;
    }
  }
  return minElement;
}

#endif
