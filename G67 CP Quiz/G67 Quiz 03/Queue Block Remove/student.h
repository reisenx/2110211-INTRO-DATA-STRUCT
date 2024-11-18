#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>

/*  ----- Block Remove -----
    Case 1: Remove block is near back() of a queue
    mData = [1,2,3,4,5,{6,7,8},9,10]
    - Throw 9 to replace 6      | jump = 3
    - Throw 10 to replace 7     | jump = 3
    - Resize the mSize to mSize - jump
    - We got [1,2,3,4,5,{9,10],8},9,10 (Ignore 8,9,10 at the back)

    Case 2: Remove block is near front() of a queue
    mData = [1,2,{3,4,5},6,7,8,9,10]
    - Throw 2 to replace 5      | jump = 3
    - Throw 1 to replace 4      | jump = 3
    - Resize the mSize to mSize - jump
    - Add mFront by jump
    - We got 1,2,{3,[1,2},6,7,8,9,10] (Ignore 1,2,3 at the front)
*/
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Jump is amount element needed to remove
    size_t jump = to - from + 1;

    // Case 1: Remove block is near back() of a queue
    if(mSize - to <= from)
    {
        // Throw element at the back
        for(size_t i = to+1; i < mSize; i++)
        {
            mData[(mFront + i - jump + mCap)%mCap] = mData[(mFront + i)%mCap];
        }
    }

    // Case 2: Remove block is near back() of a queue
    else
    {
        // Throw element at the front
        for(int i = from-1; i >= 0; i--)
        {
            i = (size_t) i;
            mData[(mFront + i + jump)%mCap] = mData[(mFront + i)%mCap];
        }
        // Change mFront
        mFront = (mFront + jump)%mCap;
    }
    // Change mSize
    mSize -= jump;
    return;
}
#endif