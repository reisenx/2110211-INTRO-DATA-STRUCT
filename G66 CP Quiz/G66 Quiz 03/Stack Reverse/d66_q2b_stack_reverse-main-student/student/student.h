#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// Validate first and last (Value exceed mSize - 1)
	if(first >= mSize) first = mSize - 1;
	if(last >= mSize) last = mSize - 1;
	
	// Reverse only if first < last
	if(first < last)
	{
		// Example: reverse(1,5) to [1,2,3,4,5,6,7] (mSize = 7)
		// [1,6,3,4,5,2,7] | Swap mData[(7-1)-(1+0)], mData[(7-1)-(5-0)]
		// [1,6,5,4,3,2,7] | Swap mData[(7-1)-(1+1)], mData[(7-1)-(5-1)]
		for(int i = 0; i < (last-first+1)/2; i++)
		{
			std::swap(mData[(mSize-1)-(first+i)], mData[(mSize-1)-(last-i)]);
		}
	}
}

#endif
