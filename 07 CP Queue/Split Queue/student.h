#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    /* Split Queue
    Example: q = [3,9,8,6,7,2,1,3,8,4] | k = 3
    qs[0] = [3,6,1,4] | index = 0,3,6,9 | index mod 3 = 0
    qs[1] = [9,7,3]   | index = 1,4,7   | index mod 3 = 1
    qs[2] = [8,2,8]   | index = 8,2,8   | index mod 3 = 2
    */
    std::vector<CP::queue<T>> qs(k);
    int queueSize = size();
    for(int i = 0; i < queueSize; i++) { qs[i%k].push(front()); pop(); }
    return qs;
}

#endif

