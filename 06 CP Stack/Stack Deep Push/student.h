#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  // Create new mData
  auto newData = new T[mSize+1];
  // Works like insert() in CP::vector but position to insert is mSize - pos
  for(size_t i = 0; i < mSize - pos; i++) { newData[i] = mData[i]; }
  newData[mSize - pos] = value;
  for(size_t i = mSize - pos; i < mSize; i++) { newData[i+1] = mData[i]; }
  // Assign new value to mData, mSize, mCap
  delete[] mData;
  mData = newData;
  mSize = mSize + 1;
  mCap = mSize;
}

#endif
