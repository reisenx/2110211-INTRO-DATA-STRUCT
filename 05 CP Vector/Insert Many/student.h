#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  // Create new array with the initial size + data.size()
  auto newData = new T[mSize + data.size()];
  // Need to sort the data by index (the value in data.first)
  sort(data.begin(), data.end());
  /* Pointers
  - Given 'i' is the pointer of mData (Increase when assign the element to newData)
  - Given 'j' is the pointer of data (Increase when element in pos detected in mData)
  - Given 'k' is the pointer of newData (Always increase each loop)
  */
  size_t i = 0, j = 0, k = 0;
  while(k < mSize + data.size())
  {
    // Case 1: Pointer 'j' doesn't exceed size of vector 'pos'
    if(j < data.size())
    {
      // If current index is in vector 'data', assign value the pair and mData[i] to newData[k] 
      if(i == data[j].first)
      {
        newData[k] = data[j].second; j++; k++;
        newData[k] = mData[i]; i++; k++;
      }
      // Else, assign the data normally
      else { newData[k] = mData[i]; i++; k++; }
    }
    // Case 2: Pointer 'j' is already exceed size of vector 'data'
    // Assign the data normally
    else { newData[k] = mData[i]; i++; k++; }
  }
  // Setup new value to mSize, mData and mCap
  mSize += data.size();
  delete[] mData;
  mData = newData;
  mCap = mSize;
}

#endif
