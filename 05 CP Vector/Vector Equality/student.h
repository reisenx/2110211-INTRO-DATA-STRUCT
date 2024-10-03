#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  // Vector size is not equal, return false
  if(mSize != other.size()) return false;
  // Check if, there's at least 1 element that is not the same
  for(int i = 0; i < mSize; i++) { if(mData[i] != other.at(i)) return false; }
  // Else, return true
  return true;
}

#endif
