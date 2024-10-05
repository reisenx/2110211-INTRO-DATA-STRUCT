#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  /* Queue Back to Front
  Example: [8,<1,2,3,4>,5,6,7] | mCap = 8, mSize = 4, mFront = 1
  We can swap previous element with the back to a queue, then set mFront to its previous element
  - Swap to [4,<1,2,3,8>,5,6,7] and Change mFront = 0 and got [<4,1,2,3>,8,5,6,7]
  - Element at the back of a queue is at index (mFront + mSize-1)%mCap
  - Element before the front of a queue is at index (mFront + mCap-1)%mCap
  */
  std::swap(mData[(mFront+mSize-1)%mCap], mData[(mFront+mCap-1)%mCap]);
  mFront = (mFront+mCap-1)%mCap;
}

#endif
