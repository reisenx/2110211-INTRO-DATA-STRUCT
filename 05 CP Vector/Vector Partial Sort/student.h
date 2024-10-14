#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include<algorithm>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT comp) {
  // Sort iterator in ascending order
  sort(pos.begin(), pos.end());
  // Pick an element of each iterator in pos and put them in temporary vector
  std::vector<T> temp;
  for(auto &it : pos) { temp.push_back(*it); }
  // Sort elements in temp using comp
  sort(temp.begin(), temp.end(), comp);
  // Replace new data to each iterator in pos
  int i = 0;
  for(auto &it : pos) { mData[it - begin()] = temp[i]; i++; } 
}

#endif
