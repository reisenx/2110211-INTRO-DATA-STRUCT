#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    // Create new array (not vector)
    auto newData = new T[mSize];
    // Assign a new value to the new data
    for(int i = 0; i < mSize; i++) { newData[i] = mData[i]; }
    // Delete the old value
    delete[] mData;
    // Assign the new data to mData and change mCap value to mSize
    mData = newData;
    mCap = mSize;
}

#endif
