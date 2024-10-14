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
  // Given start point = 1 and end point = -1
  // Example: ranges [[v.begin()+2, v.begin()+7], [v.begin()+1, v.begin()+4], [v.begin()+1, v.begin()+9]]
  // indexErase = [0,2,1,0,-1,0,0,-1,0,-1,0,0]
  for(auto &[start, end] : ranges)
  {
    indexErase[start - begin()] += 1;
    indexErase[end - begin()] -= 1;
  }
  // Now given indexErase[n] = sum of indexErase[0] to indexErase[n]
  // Example: [0,2,1,0,-1,0,0,-1,0,-1,0,0] --> [0,2,3,3,2,2,2,1,1,0,0,0]
  // Number in indexErase will indicate how many ranges that overlap at that index
  int sum = 0;
  for(int i = 0; i < mSize; i++)
  {
    sum += indexErase[i];
    indexErase[i] = sum;
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
