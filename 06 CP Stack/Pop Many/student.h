#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  // To multi_pop() is just minus mSize with K (Beware of the case that K > mSize)
  mSize -= std::min(K, mSize);
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  // Find a size of a stack after multi_pop()
  size_t newSize = mSize - std::min(K, mSize);
  // Create a new stack;
  std::stack<T> removed;
  // Push the removed element into a stack
  for(size_t i = newSize; i < mSize; i++) { removed.push(mData[i]); }
  // Don't forget to actually multi_pop() the stack
  mSize = newSize;
  // Return a removed stack
  return removed;
}

#endif
