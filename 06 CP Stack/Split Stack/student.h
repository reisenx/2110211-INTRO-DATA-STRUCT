#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  /* How to split a stack
  Example: split_stack(4) when mData = [0,1,2,3,4,5,6,7,8,9], mSize = 10
  vec[0] is [1,5,9] (end at 10-0-1 = 9) (start at 9%4 = 1)
  vec[1] is [0,4,8] (end at 10-1-1 = 8) (start at 8%4 = 0)
  vec[2] is [3,7]   (end at 10-2-1 = 7) (start at 7%4 = 3)
  vec[3] is [2,6]   (end at 10-3-1 = 6) (start at 6%4 = 2)
  */
  std::vector<std::vector<T>> splitStack;
  for(int vec = 0; vec < k; vec++)
  {
    std::vector<T> data;
    // Find start and end point of mData
    int end = mSize - vec - 1;
    int start = end % k;
    // If start exceed mSize, push_back an empty vector and skip the loop
    if(start >= mSize) {splitStack.push_back(data); continue;}
    // push_back data into a vector
    for(int i = start; i <= end; i += k) { data.push_back(mData[i]); }
    splitStack.push_back(data);
  }
  return splitStack;
}

#endif

