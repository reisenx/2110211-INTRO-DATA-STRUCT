#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  // Create new array with the initial size - pos.size()
  auto newData = new T[mSize - pos.size()];
  /* Pointers
  - Given 'i' is the pointer of mData (Always increase each loop)
  - Given 'j' is the pointer of pos (Increase when element in pos detected in mData)
  - Given 'k' is the pointer of newData (Increase when assign the element to newData)
  */
  size_t j = 0, k = 0;
  for(size_t i = 0; i < mSize; i++)
  {
    // Case 1: Pointer 'j' doesn't exceed size of vector 'pos'
    if(j < pos.size())
    {
      // If current index is in vector 'pos', don't assign mData[i] to newData[k]
      // Note that vector 'pos' is already sorted in ascending order
      if(i == pos[j]) j++;
      // Else, assign the data normally
      else { newData[k] = mData[i]; k++; }
    }
    // Case 2: Pointer 'j' is already exceed size of vector 'pos'
    // Assign the data normally
    else { newData[k] = mData[i]; k++; }
  }
  // Setup new value to mSize, mData and mCap
  mSize -= pos.size();
  delete[] mData;
  mData = newData;
  mCap = mSize;
}

#endif
