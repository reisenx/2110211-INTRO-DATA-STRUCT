#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

/*  ---------- List Extract ----------
    list = [<9, -1, 11, -1, 40>, -1] | value = -1 | a = begin(), b = begin()+5
    list = [<9, 11, 40>, -1]
    output = [69,99] --> output = [<-1,-1>,69,99]
    
    Update list links
    Before:
    - (-1)->prev = 9              | 9->next = -1
    - (-1)->next = 11             | 11->prev = -1
    - (69)->prev = output.mHeader | (output.mHeader)->next = 69
    - (99)->next = 99             | 99->prev = 69
    After:
    - (-1)->prev = output.mHeader | 9->next = 11
    - (-1)->next = 69             | 11->prev = 9
    - (69)->prev = -1             | (output.mHeader)->next = -1
    - (99)->next = 99             | 99->prev = 69
*/

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  // If a and b are the same node, do nothing
  if(a == b) return;

  // iterate node until node b
  auto node = a;
  while(node != b)
  {
    iterator nextNode(node.ptr->next);
    if(*node == value)
    {
      // Erase node from this list
      (node.ptr->prev)->next = node.ptr->next;
      (node.ptr->next)->prev = node.ptr->prev;
      // Update list links of the first node of output
      ((output.mHeader)->next)->prev = node.ptr;
      (node.ptr)->next = (output.mHeader)->next;
      // Update list links of mHeader of output
      (output.mHeader)->next = node.ptr;
      (node.ptr)->prev = (output.mHeader);
      // Update mSize
      mSize--;
      output.mSize++;  
    }
    // Jump to next node
    node = nextNode;
  }
}

#endif
