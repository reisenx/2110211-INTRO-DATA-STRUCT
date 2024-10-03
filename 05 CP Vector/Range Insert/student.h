#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  // Create new array with the inital size + inserted data size
  // Insert data size can be calculate by subtracting iterators
  auto newData = new T[mSize + last - first];
  // Given initial point 'i' which is the index of newData
  size_t i = 0;
  // Assign data from first element to position iterator to newData
  for(auto it = &mData[0]; it < position; it++) { newData[i] = *it; i++; }
  // Assign data from 'first' to 'last' iterator to newData
  for(auto it = first; it < last; it++) { newData[i] = *it; i++; }
  // Assign data from 'position' iterator to the last element
  for(auto it = position; it <= &mData[mSize-1]; it++) { newData[i] = *it; i++; }
  // Setup mData, mSize and mCap to the new value
  mSize = mSize + last - first;
  delete[] mData;
  mData = newData;
  mCap = mSize;
}

#endif
