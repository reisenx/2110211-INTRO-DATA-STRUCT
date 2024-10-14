#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <cmath>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  /* Node Level
  Level 0: Node 0 to 0   | start = (2^0)-1 | end = (2^1)-2
  Level 1: Node 1 to 2   | start = (2^1)-1 | end = (2^2)-2
  Level 2: Node 3 to 6   | start = (2^2)-1 | end = (2^3)-2
  Level 3: Node 7 to 14  | start = (2^3)-1 | end = (2^4)-2
  Level 4: Node 15 to 30 | start = (2^4)-1 | end = (2^5)-2 */
  
  // Find start and end node of level k
  std::vector<T> levelData;
  size_t start = pow(2,k)-1;
  size_t end = pow(2,k+1)-2;

  // Return an empty vector immediately, if start exceed mSize-1
  if(start > mSize-1) return levelData;
  // If end exceed mSize-1, change the value of end to mSize-1
  if(end > mSize-1) end = mSize-1;

  // push_back all data in level k
  for(int i = start; i <= end; i++){ levelData.push_back(mData[i]); }
  // Sort levelData using mLess
  // If mLess is std::less(), the priority queue is in descending order
  // If mLess is std::greater(), the priority queue is in ascending order
  // So we need to use reverse iterator instead (rbegin() and rend())
  sort(levelData.rbegin(), levelData.rend(), mLess);
  return levelData;
}

#endif

