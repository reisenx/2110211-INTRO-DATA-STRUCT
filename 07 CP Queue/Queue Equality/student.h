#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  // Condition 1: Check size of both queue
  if(size() != other.size()) return false;
  // Condition 2: Check mData of both queue
  for(int i = 0; i < size(); i++)
  {
    T thisElement = mData[(mFront+i) % mCap];
    T otherElement = other.mData[(other.mFront+i) % other.mCap];
    if(thisElement != otherElement) return false;
  }
  return true;
}

#endif
