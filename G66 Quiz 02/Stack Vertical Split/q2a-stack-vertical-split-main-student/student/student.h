#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  /* Stack Vertical Split
  Example: [1,2,3,4,5,6,7,8,9,10,11,12,13] --> [[11,12,13], [8,9,10], [5,6,7], [3,4], [1,2]]
  - Amount stack with size 3 (mSize/k + 1) is 3 (mSize mod k)
  - Amount stack with size 2 (mSize/k)     is 2 (k - (mSize mod k))
  Process
  output = [[],[],[],[],[1,2]] --> output = [[],[],[],[3,4],[1,2]] and so on... */
  output.resize(k);
  int i = k-1;
  int j = 0;
  for(int count = 0; count < k-(mSize%k); count++)
  {
    for(int amount = 0; amount < mSize/k; amount++) { output[i].push(mData[j]); j++; }
    i--;
  }
  
  for(int count = 0; count < mSize%k; count++)
  {
    for(int amount = 0; amount < (mSize/k)+1; amount++) { output[i].push(mData[j]); j++; }
    i--;
  }
}

#endif
