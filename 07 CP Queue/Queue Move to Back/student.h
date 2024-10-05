#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  /* Queue Move to Back
  Example: [8,<1,2,3,4,5>,6,7] | mCap = 8, mSize = 5, mFront = 1, pos = 2
  - Swap [8,<1,2,4,3,5>,6,7] | index (mFront+2)%mCap <--> (mFront+2+1)%mCap
  - Swap [8,<1,2,4,5,3>,6,7] | index (mFront+3)%mCap <--> (mFront+4+1)%mCap
  */
  for(size_t i = pos; i < mSize-1; i++) { std::swap(mData[(mFront+i)%mCap], mData[(mFront+i+1)%mCap]); }
}

#endif
