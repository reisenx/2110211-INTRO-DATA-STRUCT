#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
    size_t rank = 0;
    // Compare each mData[pos] to all data in mData by mLess
    // mLess is std::less() in default (priority_queue sorted in descending order)
    // If mLess is std::less(), rank 0 is greatest element (mData[pos] is not less than any element)
    // If mLess is std::greater(), rank 0 is smallest element (mData[pos] is not more than any element)
    for(size_t i = 0; i < mSize; i++)
    {
        if(mLess(mData[pos], mData[i])) rank++;
    }
    return rank;
}

#endif