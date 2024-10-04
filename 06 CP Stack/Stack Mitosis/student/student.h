#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    /* Stack Mitosis (mitosis(a,b))
    Example: mitosis(2,5) to [10,20,30,40,50,60,70,80] (duplicate 30,40,50,60)
    Phase 1 (Do nothing): [10,20]       | index 0 to mSize-b-2
    Phase 2 (Mitosis):    [30,40,50,60] | index mSize-b-1 to mSize-a-1
    Phase 3 (Throw back): [70,80]       | index mSize-a to mSize-1
    - Expand Array Size to mSize + (b-a+1)
    - [10,20,30,40,50,60,70,80,--,--,--,--]
    - [10,20,30,40,50,60,70,80,--,--,70,80] throws 70,80 by 4 blocks (b-a+1)
    - [10,20,30,40,50,60,70,80,60,60,70,80] throw 60 by 4 and 3 blocks
    - [10,20,30,40,50,60,50,50,60,60,70,80] throw 50 by 3 and 2 blocks
    - [10,20,30,40,40,40,50,50,60,60,70,80] throw 40 by 2 and 1 blocks
    - [10,20,30,30,40,40,50,50,60,60,70,80] throw 30 by 1 and 0 blocks
    */
    size_t newSize = mSize + (b-a+1);
    // Expand mSize to newSize
    if(newSize > mCap) expand(std::max(2*mCap, newSize));
    // Manage elements in Phase 3
    int before = mSize-1, after = newSize-1;
    while(before >= (int)mSize-a)
    { 
        mData[after--] = mData[before--];
    }
    // Manage elements in Phase 2
    while(before >= (int)mSize-b-1)
    {
        mData[after--] = mData[before];
        mData[after--] = mData[before--];
    }
    mSize = newSize;
}

#endif