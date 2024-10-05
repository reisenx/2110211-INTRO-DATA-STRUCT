#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  // This use circular queue model
  // for positive index (index = 0,1,2,3,...)
  if(idx >= 0) return mData[(mFront + idx)%mCap];
  // For negative index (index = -1,-2,-3,..)
  // -1 means the back element in the queue, which is index mSize - 1 
  return mData[(mFront + mSize + idx)%mCap];
}

#endif