#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  /* Stack Move Insert
  - Create CP::stack temp1 to contains first k element of this stack
  - Create CP::stack temp2 to contains first m element of s2 stack
  - Put element from temp2, then temp1 to this stack
  Example: this = [1,2,3,4,5], s2 = [10,20,30] and use moveInsert(2,s2,2)
  - Move k elements from this to temp1: this = [1,2,3] and temp1 = [5,4]
  - Move m elements from s2 to temp2:   s2 = [10] and temp2 = [30,20]
  - Move temp2 to this: this = [1,2,3,20,30] and temp2 = []
  - Move temp1 to this: this = [1,2,3,20,30,4,5] and temp1 = []
  */
  CP::stack<T> temp1, temp2;
  // Beware of cases that m > s2.size()
  m = std::min((int)s2.size(), m);
  for(int i = 0; i < k; i++) { temp1.push(top()); pop(); }
  for(int i = 0; i < m; i++) { temp2.push(s2.top()); s2.pop(); }
  for(int i = 0; i < m; i++) { push(temp2.top()); temp2.pop(); }
  for(int i = 0; i < k; i++) { push(temp1.top()); temp1.pop(); }
}
#endif
