#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

/* Concept of Double Stack
Given that the rightmost element is the top of a stack
- stack_a is used to store element that added by push() method
- stack_b is used to store element that added by push_bottom() method
Example: stack = [1,2,3] | stack_a = [1,2,3] | stack_b = []
push(4)        | stack = [1,2,3,4]     | stack_a = [1,2,3,4]   | stack_b = []
push(5)        | stack = [1,2,3,4,5]   | stack_a = [1,2,3,4,5] | stack_b = []
push_bottom(6) | stack = [6,1,2,3,4]   | stack_a = [1,2,3,4,5] | stack_b = [6]
push_bottom(7) | stack = [7,6,1,2,3,4] | stack_a = [1,2,3,4,5] | stack_b = [6,7]
You can see the pattern that
- stack_a.top() is top() of a stack (pop() is stack_a.pop())
- stack_b.top() is bottom() of a stack (pop_bottom() is stack_b.pop()) */

/* Balancing Stacks
The problem occurs when stack_a or stack_b is empty
pop_bottom() | stack = [1,2,3,4,5] | stack_a = [1,2,3,4,5] | stack_b = []
pop()        | stack = [1,2,3,4,5] | stack_a = []          | stack_b = [5,4,3,2,1]
And this, you can't easily using top(), pop(), bottom() or pop_bottom() for multiple times
The solution is to balance the stack so both stacks is not empty
{ stack_a = [1,2,3,4,5] temp = [] } --> { stack_a = [1,2,3] temp = [5,4] }
{ stack_a = [1,2,3] stack_b = [] }  --> { stack_a = [] stack_b = [3,2,1]}
{ stack_a = [] temp = [5,4] }       --> { stack_a = [4,5] temp = [] }
So we will get stack_a = [4,5] and stack_b = [3,2,1]
And now we can using top(), pop(), bottom() or pop_bottom() for multiple times */

// Create Balancing stack Method (Move stack_a to stack_b)
// Example: stack = [1,2,3,4,5] | stack_a = [1,2,3,4,5] | stack_b = []
// After balanceStack() got stack_a = [4,5] and stack_b = [3,2,1]
template <typename T>
void balanceStack(std::stack<T> &stack_a, std::stack<T> &stack_b) {
	std::stack<T> temp;
	if(stack_b.empty())
	{
		for(int i = 0; i < stack_a.size()/2; i++)
		{
			temp.push(stack_a.top()); stack_a.pop();
		}
		while(!stack_a.empty())
		{
			stack_b.push(stack_a.top()); stack_a.pop();
		}
		while(!temp.empty())
		{
			stack_a.push(temp.top()); temp.pop();
		}
	}
}

template <typename T>
void CP::stack<T>::pop() {
	balanceStack(stack_b, stack_a);
	stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
	balanceStack(stack_b, stack_a);
	return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
	balanceStack(stack_a, stack_b);
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
	balanceStack(stack_a, stack_b);
	stack_b.pop();
}
#endif