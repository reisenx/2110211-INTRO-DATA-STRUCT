#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include<cmath>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
  // Loop find 'k' in mData (Time Complexity O(n))
  for(int node = 0; node < mSize; node++)
  {
    if(mData[node] == k) return true;
  }
  return false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
  // Loop find 'k' in mData (Time Complexity O(n))
  // Loop from back to the front
  for(int node = mSize-1; node >= 0; node--)
  {
    // If found, returns node level
    if(mData[node] == k)
    {
      // Find node level
      // Parents of node 'n' is (n-1)/2
      int level = 0;
      while(node > 0) { node = (node-1)/2; level++; }
      return level;
    }
  }
  // If not found, returns -1
  return -1;
}

#endif

