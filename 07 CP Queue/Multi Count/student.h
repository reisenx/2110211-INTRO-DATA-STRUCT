#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    // Create a map to count data in mData
    std::map<T,size_t> dataCount;
    std::vector<std::pair<T,size_t>> result;
    // Traverse through mData and count
    for(int i = 0; i < size(); i++)
    {
        if(dataCount.find(mData[i]) == dataCount.end()) dataCount[mData[i]] = 1;
        else dataCount[mData[i]] += 1;
    }
    // Convert dataCount to result
    for(auto &x : k)
    {
        if(dataCount.find(x) == dataCount.end()) result.push_back(std::make_pair(x,0));
        else result.push_back(std::make_pair(x, dataCount[x]));
    }
    // Return a result;
    return result;
}

#endif
