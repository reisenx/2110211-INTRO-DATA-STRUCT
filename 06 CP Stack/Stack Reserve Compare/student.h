#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    // Find remaining space of dynamic array of both stack
    size_t spaceA = mCap - mSize, spaceB = other.mCap - other.mSize;
    // Compare and return a value
    if(spaceA > spaceB) return 1;
    if(spaceA == spaceB) return 0;
    if(spaceA < spaceB) return -1;
}

#endif
