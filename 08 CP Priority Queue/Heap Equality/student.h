#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  // Check size of both priority_queue
  if(mSize != other.size()) return false;
  // Copy both priority queue
  CP::priority_queue<T,Comp> pq1(*this);
  CP::priority_queue<T,Comp> pq2(other);
  // Pop each priority queue and compare
  for(int i = 0; i < mSize; i++)
  {
    if(pq1.top() != pq2.top()) return false;
    pq1.pop(); pq2.pop();
  }
  return true;
}

#endif
