#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  // Find upper_bound in aux to get vector<int> index
  // *(i-1) is mCap value before expand a vector to insert that element
  // So index of that element in vector<int> is idx - *(i-1)
  auto it = upper_bound(aux.begin(), aux.end(), idx);
  return mData[it - aux.begin()][idx - *(it-1)];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  // aux is a vector<int> that contains mCap of each expand
  // Example: aux = [4,16,4]
  aux.push_back(mCap);
}

#endif
