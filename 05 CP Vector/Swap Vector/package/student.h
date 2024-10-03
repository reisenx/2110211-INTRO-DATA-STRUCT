#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
  // Just use std::swap
  std::swap(mData, other.mData);
  std::swap(mCap, other.mCap);
  std::swap(mSize, other.mSize);
}

#endif
