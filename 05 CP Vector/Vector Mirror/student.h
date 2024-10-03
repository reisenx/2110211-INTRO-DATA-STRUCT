#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  // Create new array twice bigger than the original size
  auto newData = new T[2*mSize];
  // Looping assign value to the new array
  for(size_t i = 0; i < mSize; i++) 
  { 
    newData[i] = mData[i];
    newData[2*mSize - i - 1] = mData[i];
  }
  // Delete old array
  delete[] mData;
  // Assign new value to the mData, mSize and mCap
  mData = newData;
  mSize *= 2;
  mCap = mSize;
}

#endif
