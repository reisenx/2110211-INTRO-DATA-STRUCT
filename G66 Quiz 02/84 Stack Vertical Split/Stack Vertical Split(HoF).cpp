#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  output.resize(k);
  int m = mSize%k;
  int n = mSize/k;
  int now = 0;
  for (int i = k-1; i >= 0; i--) {
        if(now==mSize) break;
      for(int j=0;j<n;j++) output[i].push(mData[now++]);
      if(i<m) output[i].push(mData[now++]);
    }

}

#endif

