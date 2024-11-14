#ifndef __STUDENT_H_
#define __STUDENT_H_

/*  ---------- List Split ----------
    Example: a = [1,2,3,4,5,6]
    a.split(it,2) --> a = [1,2] | result = [3,4,5,6]
    Steps
    1.) Initial list links
    - mHeader->next = 1          | mHeader->prev = 6
    - (result.mHeader)->next = (result.mHeader)->prev = result.mHeader
    - it = 3                     | it->prev = 2
    - (2)->next = 3              | (6)->next = mHeader
    - mSize = 6
    2.) Change list links
    - mHeader->next = 1          | mHeader->prev = 2
    - (result.mHeader)->next = 3 | (result.mHeader)->prev = 6
    - it = 3                     | it->prev = result.mHeader
    - (2)->next = mHeader        | (6)->next = result.Header
    3.) Change mSize
    - result.mSize = 6-2
    - mSize = 2
*/

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  // Create new CP::list
  CP::list<T> result;
  // If pos = mSize - 1, do nothing
  if(pos >= mSize - 1) return result;
  
  // Change link links
  (result.mHeader)->next = it.ptr;
  (result.mHeader)->prev = mHeader->prev;
  (mHeader->prev)->next = result.mHeader;
  mHeader->prev = it.ptr->prev;
  (it.ptr->prev)->next = mHeader;
  it.ptr->prev = result.mHeader;
  // Change mSize
  result.mSize = mSize - pos;
  mSize = pos;
  // Return a new list
  return result;
}

#endif
