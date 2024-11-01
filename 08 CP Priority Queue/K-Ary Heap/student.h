#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>

/* 4-ary Heap Concept
Node 'n' has children at node [4n+1, 4n+2, 4n+3, 4n+4]
Node 'n' has parent at node (n-1)/4 */

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    // Get data at idx
    T temp = mData[idx];
    // Loop until node = 0
    while(idx > 0)
    {
        // Go to parent node
        size_t parent = (idx-1)/4;
        // Compare temp and parent node with mLess
        // Stop the process, if correct by value rule
        if(mLess(temp, mData[parent])) break;
        // Replace child node to parent node
        mData[idx] = mData[parent];
        // Jump to parent node
        idx = parent;
    }
    // Put temp to appropriate index
    mData[idx] = temp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    // Get data at idx
    T temp = mData[idx];

    /* Find best child
    - The best child is the smallest node (mLess is std::less)
    - The best child is the largest node (mLess is std::greater)
    NOTE: We need to swap with the bestChild on each level */
    size_t bestChild;
    while((bestChild = (4*idx)+1) < mSize)
    {
        if(bestChild >= mSize) break;
        for(int i = 2; i <= 4; i++)
        {
            size_t child = (4*idx)+i;
            if(child < mSize && mLess(mData[bestChild], mData[child]))
            {
                bestChild = child;
            }
        }
        // If bestChild is not swappable, end the process
        if(mLess(mData[bestChild], temp)) break;
        // Replace parent node to child node
        mData[idx] = mData[bestChild];
        // Jump to the best child
        idx = bestChild;
    }
    // Put temp to appropriate index
    mData[idx] = temp;
}

#endif