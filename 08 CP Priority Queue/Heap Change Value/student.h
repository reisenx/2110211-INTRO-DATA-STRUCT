#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  // Change mData[pos] to value
  mData[pos] = value;
  // Fix the binary heap to maintain binary heap rule
  fixDown(pos);
  fixUp(pos);
}

#endif
