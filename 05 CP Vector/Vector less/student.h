#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  // Compare Items
  for(int i = 0 ; i < std::min(mSize, other.size()); i++)
  {
    if(mData[i] < other[i]) return true;
    if(mData[i] > other[i]) return false;
  }
  // Compare Size
  if(mSize < other.size()) return true;
  return false;
}

#endif
