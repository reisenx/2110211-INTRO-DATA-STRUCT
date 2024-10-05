#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  // Create a vector that contains first k element of a queue
  std::vector<T> res;
  // Traverse through mData from index 0 to k
  for(int i = 0; i < std::min((int)mSize, k); i++) { res.push_back(mData[(mFront+i)%mCap]); }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  // Since this is another constructor, we need to setup our mFront, mSize, mCap and mData
  mFront = 0;
  mCap = 1;
  mSize = 0;
  mData = new T[1]();
  
  // Traverse through vector iterator and push the element into a queue
  for(auto it = from; it < to; it++) { push(*it); }
}

#endif
