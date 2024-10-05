#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  /* Queue Total Reverse
  We can reverse entire queue without changing mData
  - Normal (aux = 0)   | Use circular queue by rotate in clockwise direction
  - Reversed (aux = 1) | Use circular queue by rotate in counter-clockwise direction */
  /* Change mFront
  - Normal (aux = 0)   | jump forward by mSize - 1
  - Reversed (aux = 1) | jump backward by mSize - 1 */
  if(!aux) mFront = (mFront + mSize - 1) % mCap;
  else mFront = (mFront + mCap - (mSize - 1)) % mCap;
  // Change aux value (0 <--> 1)
  if(!aux) aux = 1;
  else aux = 0;
}

template <typename T>
const T& CP::queue<T>::front() const {
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  /* Access back element in a queue
  - Normal (aux = 0)   | jump forward by mSize - 1
  - Reversed (aux = 1) | jump backward by mSize - 1 */
  if(!aux) return mData[(mFront + mSize - 1) % mCap];
  return mData[(mFront + mCap - (mSize - 1)) % mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // Expand a queue, if necessary
  ensureCapacity(mSize + 1);
  /* Add an element at the back
  - Normal (aux = 0)   | jump forward by mSize
  - Reversed (aux = 1) | jump backward by mSize */
  if(!aux) mData[(mFront + mSize) % mCap] = element;
  else mData[(mFront + mCap - mSize) % mCap] = element;
  // Increase mSize by 1
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  /* Remove an element at the front
  - Normal (aux = 0)   | jump forward by 1
  - Reversed (aux = 1) | jump backward by 1 */
  if(!aux) mFront = (mFront + 1) % mCap;
  else mFront = (mFront + mCap - 1) % mCap;
  // Decrease mSize by 1
  mSize--;
}

#endif