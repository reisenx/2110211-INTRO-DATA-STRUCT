#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  // Return size of std::vector
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  // Return element at the end of the vector
  return *(v.rbegin());
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  // Use push_back()
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  // Use pop_back()
  v.pop_back();
}

#endif
