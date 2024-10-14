#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Descendant of node n is node 2n+1 and 2n+2
  for(int node = 0; node < mSize; node++)
  {
    // Find left child and right child of a current
    int left_child = (2*node) + 1;
    int right_child = (2*node) + 2;
    // Compare to both child using mLess
    if(left_child < mSize)
    {
      // If mLess(left_child, node) is false, return false
      if(!mLess(mData[left_child], mData[node])) return false;
    }
    if(right_child < mSize)
    {
      // If mLess(right_child, node) is false, return false
      if(!mLess(mData[right_child], mData[node])) return false;
    }
  }
  return true;
}

#endif