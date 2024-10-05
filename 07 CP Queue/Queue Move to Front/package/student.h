#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    /* Queue Move to Front
    Example: [8,<1,2,3,4,5>,6,7] | mCap = 8, mSize = 5, mFront = 1, pos = 3
    - Swap [8,<1,2,4,3,5>,6,7] | index (mFront+3)%mCap <--> (mFront+3-1)%mCap
    - Swap [8,<1,4,2,3,5>,6,7] | index (mFront+2)%mCap <--> (mFront+2-1)%mCap
    - Swap [8,<4,1,2,3,5>,6,7] | index (mFront+1)%mCap <--> (mFront+1-1)%mCap
    */
    for(int i = pos; i > 0; i--) { std::swap(mData[(mFront+i)%mCap], mData[(mFront+i-1)%mCap]); }
}

#endif
