#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
int CP::list<T>::data_iterator(CP::list<T>::iterator it) {
  // Check if the iterator is NULL
  if(it == NULL) return -2;
  // Check if mSize is 0 (begin() is also end() because the list has no elements)
  if(mSize == 0) return -1;
  // Check if the iterator points at begin() of a list
  if(it == begin() && *it == *begin()) return 0;
  // Check if the iterator points at end() of a list
  if(it == end()) return -1;
  // Check if the iterator points at any element inside a list
  iterator data(mHeader->next);
  for(size_t i = 1; i < mSize; i++)
  {
    data++;
    if(it == data && *it == *data) return i;
  }
  // The iterator points at neither list elements and end()
  return -2;
}

#endif