#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  /* It's more like vector distribute but in reverse order
  [13,12,11,10,9,8,7,6,5,4,3,2,1] --> [1,2,3] [4,5,6] [7,8,9] [10,11] [12,13]
  - Amount vector with size 3 (mSize/k + 1) is 3 (mSize mod k)
  - Amount vector with size 2 (mSize/k)     is 2 (k - (mSize mod k))
  */
  std::vector<std::vector<T>> stackDistribute;
  int i = mSize - 1;
  // push_back vector with size (mSize/k + 1), (mSize mod k) times
  for(int count = 0; count < mSize%k; count++)
  {
    std::vector<T> data;
    for(int amount = 0; amount < (mSize/k)+1; amount++) { data.push_back(mData[i]); i--; }
    stackDistribute.push_back(data);
  }
  // push_back vector with size (mSize/k), (k - (mSize mod k)) times
  for(int count = 0; count < k-(mSize%k); count++)
  {
    std::vector<T> data;
    for(int amount = 0; amount < mSize/k; amount++) { data.push_back(mData[i]); i--; }
    stackDistribute.push_back(data);
  }
  // Return a value
  return stackDistribute;
}
#endif
