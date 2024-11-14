#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

/*  ---------- List Reverse ----------
    - No need to fix the nodes links, just fix the value
    - Use std::swap to swap value inside the node
    - Each loop iterate a forward and iterate b backward

    Case 1: Loop until a and b is the same node
    [10, <60, 50, 40, 30, 20>, 70] | node a = 50, b = 30
    a++ is 40 and b-- is 40 (Same node)
    
    Case 2: Loop until a++ is node b
    [10, 20, <60, 50, 40, 30>, 70] | node a = 50, b = 40
    a++ is 40 and b is 40 (Same node)
*/

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  // If a and b is the same node or size = 0, just do nothing
  if(a == b) return a;
  // This function does not include value at node b
  b--;
  // This function must return iterator of node a (before reverse)
  auto it(a);
  // Reverse operation
  while(a != b)
  { 
    std::swap(*a,*b);
    a++;
    if(a == b) break;
    b--;
  }
  return it;
}

#endif
