#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>
using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  // Create a stack
  stack<int> calculate;
  // Loop each pair in vector
  for(auto &x : v)
  {
    // Case 1: x.first = 1 (Put a x.second into a stack)
    if(x.first == 1) calculate.push(x.second);
    // Case 2: x.first = 0 (Pop 2 numbers from a stack and put the result back to a stack)
    if(x.first == 0)
    {
      // Get top 2 number
      int num2 = calculate.top();
      calculate.pop();
      int num1 = calculate.top();
      calculate.pop();
      // Calculate
      int result;
      if(x.second == 0) result = num1 + num2;
      if(x.second == 1) result = num1 - num2;
      if(x.second == 2) result = num1 * num2;
      if(x.second == 3) result = num1 / num2;
      // Put the result back at the top of the stack
      calculate.push(result);
    }
  }
  // Return the result
  int result = calculate.top();
  return result;
}

#endif
