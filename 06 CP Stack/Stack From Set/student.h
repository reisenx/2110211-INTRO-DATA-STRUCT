#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  // Since this is another constructor method, we need to setup our mSize, mCap and mData
  mSize = 0;
  mCap = 1;
  mData = new T[1]();
  // Traverse from last iterator to first iterator, and put the element to a stack
  // last iterator is excluded, so we set the condition using std::prev(last)
  // first iterator is included, so we set the condition using std::prev(first)
  for(auto it = std::prev(last); it != std::prev(first); it--) { push(*it); }
}

#endif
