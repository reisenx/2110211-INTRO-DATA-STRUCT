#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  // mSize is amount of nodes of binary heap
  // Given Binary Heap Height is 'h'
  // Nodes = 2^0 + 2^1 + 2^2 + 2^3 + ... + 2^h
  if(mSize == 0) return -1;
  int nodes = 0, height = 0;
  while(true)
  {
    nodes += pow(2,height);
    if(nodes >= mSize) break;
    height++;
  }
  return height;
}

#endif

