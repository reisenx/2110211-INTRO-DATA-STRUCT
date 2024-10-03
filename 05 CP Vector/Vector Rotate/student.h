#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<queue>
using namespace std;

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  // Create queue for shifted elements
  queue<T> shifted;
  // Convert iterator into an integer
  size_t front = first - &mData[0], end = last - &mData[0];
  
  // Push element in range first to first + k into a queue
  // Example: shifted = [0,1,2]
  for(size_t i = front; i < front + k; i++) { shifted.push(mData[i]); }
  
  // Shift element in range first to last - k
  // Example: [0,1,2,3,4,5,6,7] --> [3,4,5,6,7,5,6,7]
  for(size_t i = front; i < end - k; i++) { mData[i] = mData[i+k]; }

  // Replace element in range last - k to last
  // Example: [3,4,5,6,7,5,6,7] --> [3,4,5,6,7,0,1,2]
  for(size_t i = end - k; i < end; i++)
  {
    mData[i] = shifted.front();
    shifted.pop();
  }
}

#endif
