#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<set>
using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
  // Create a set to contains unique elements
  set<T> unique;
  // Create a new CP vector
  CP::vector<T> newVector;
  // push_back all unique elements to newVector
  for(int i = 0; i < mSize; i++)
  {
    if(unique.find(mData[i]) == unique.end())
    {
      unique.insert(mData[i]);
      newVector.push_back(mData[i]);
    }
  }
  // Replace current vector with newVector
  *this = newVector;
}

#endif
