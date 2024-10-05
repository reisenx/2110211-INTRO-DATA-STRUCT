#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  /* Queue Reverse
  Example: [A,B,C,D,E,F,G,H,I] | a = 1, b = 5
  - Swap index 1,5 [A,F,C,D,E,B,G,H,I] | a+0 <--> b-0
  - Swap index 2,4 [A,F,E,D,C,B,G,H,I] | a+1 <--> b-1
  - Times to swap = (b-a+1)/2
  - To access element at index i, we need to use (mFront+i)%mCap
  */
  for(int i = 0; i < (b-a+1)/2; i++)
  { 
    std::swap(mData[(mFront+a+i)%mCap], mData[(mFront+b-i)%mCap]);
  }
}

#endif
