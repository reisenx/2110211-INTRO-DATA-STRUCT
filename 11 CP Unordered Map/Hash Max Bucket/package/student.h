#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename KeyT,
        typename MappedT,
        typename HasherT,
        typename EqualT>
size_t CP::unordered_map<KeyT,MappedT,HasherT,EqualT>::max_bucket_length() {
    // Get size of the first bucket
    size_t maxSize = mBuckets[0].size();
    // Loop each bucket in mBuckets and find maximum length
    for(std::vector<ValueT> &bucket : mBuckets)
    {
        maxSize = std::max(maxSize, bucket.size());
    }
    return maxSize;
}

#endif
