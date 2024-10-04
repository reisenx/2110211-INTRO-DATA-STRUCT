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
  // Return an element at the end of a vector
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

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  // Use insert() but the position is size - depth
  // Example: deep_push(4,3) to [0,1,2] is [4,0,1,2]
  // Example: deep_push(4,1000) to [0,1,2] is [4,0,1,2] 
  int pos = v.size() - depth;
  pos = std::max(0, pos);
  v.insert(v.begin() + pos, element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  // Use for loop in 'w' and push_back to vector v
  for(auto &x : w) { v.push_back(x); }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  // This function will pop the stack until top() == e or stack is empty
  while(top() != e && v.size() > 0) { pop(); }
}

#endif

