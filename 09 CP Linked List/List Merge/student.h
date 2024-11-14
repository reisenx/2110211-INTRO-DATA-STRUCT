#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  // Iterate each list in ls;
  for(auto &sublist : ls)
  {
    if(sublist.size() > 0)
    {
      // Calculate new mSize
      mSize += sublist.size();

      // Link last element of a list to the first element of sublist
      // - Last element of a list is mHeader->prev
      // - First element of sublist is (sublist.mHeader)->next
      (mHeader->prev)->next = (sublist.mHeader)->next;
      ((sublist.mHeader)->next)->prev = mHeader->prev;
      
      // Link last element of a sublist to mHeader
      // - Last element of sublist is (sublist.mHeader)->prev
      ((sublist.mHeader)->prev)->next = mHeader;
      mHeader->prev = (sublist.mHeader)->prev;
      
      // Set a sublist to an empty list
      (sublist.mHeader)->next = sublist.mHeader;
      (sublist.mHeader)->prev = sublist.mHeader;
      sublist.mSize = 0;
    }
  }
}

#endif
