#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  // Convert iterators to integers
  size_t frontA = a - &mData[0], endA = frontA + m - 1;
  size_t frontB = b - &mData[0], endB = frontB + m - 1;
  
  // Input Validation
  // Case 1: m <= 0
  if(m <= 0) return false;
  // Case 2: Invalid frontA, frontB, endA and endB
  if(frontA < 0 || frontB < 0 || endA < 0 || endB < 0) return false;
  if(frontA >= mSize || frontB >= mSize || endA >= mSize || endB >= mSize) return false;
  // Case 3: Overlapping Blocks
  if(frontA <= frontB && frontB <= endA) return false;
  if(frontB <= frontA && frontA <= endB) return false;

  // Block Swap Operation
  for(size_t i = 0; i < m ; i++) { std::swap(mData[frontA + i], mData[frontB + i]); }

  // Operation success
  return true;
}

#endif