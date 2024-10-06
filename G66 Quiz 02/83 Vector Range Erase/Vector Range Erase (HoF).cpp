#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  std::vector<int> cnt(mSize,0);
  for (auto [f,b] : ranges) {
    cnt[f - begin()] += 1;
    if (b - begin() < mSize) cnt[b - begin()] -= 1;
  }
  int i=0,j=0,k=0;
  while (i < mSize) {
    k += cnt[i];
    if (k == 0) {
      mData[j] = mData[i];
      j++;
    }
    i++;
  }
  mSize = j;
}

#endif

