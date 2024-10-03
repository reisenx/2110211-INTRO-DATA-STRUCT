#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  // Find index of the value
  size_t Position = it - &mData[0];
  // Check if the position doesn't exceed mSize
  return Position < mSize;
}

#endif
