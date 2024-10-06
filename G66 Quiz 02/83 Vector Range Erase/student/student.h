#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <vector>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Create a vector that contains 0
  // Example v = [1,2,3,4,5,6] --> indexErase = [0,0,0,0,0,0]
  std::vector indexErase(mSize,0);
  // Convert ranges to indexErase
  // Example: ranges [[v.begin()+2,v.begin()+4], [v.begin()+1,v.begin()+3]]
  // indexErase = [0,1,2,2,1,0]
  for(auto &[start, end] : ranges)
  {
    for(int i = start - begin(); i < end - begin(); i++) { indexErase[i] += 1; }
  }
  // Create a new mData
  auto newData = new T[mSize];
  int j = 0;
  // Assign data in index that value is 0 in indexErase
  // Example: indexErase [0,1,2,2,1,0] means keeps only mData[0] and mData[5]
  for(int i = 0; i < mSize; i++)
  {
    if(indexErase[i] == 0) { newData[j] = mData[i]; j++; }
  }
  // Setup new mData and mSize
  delete[] mData;
  mData = newData;
  mSize = j;
}

#endif
