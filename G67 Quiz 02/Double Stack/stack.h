#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_

#include <stdexcept>
#include <iostream>
#include <stack>
//#pragma once

namespace CP { 

template <typename T>
class stack
{
  protected:
    // Addition stack
    std::stack<T> stack_a, stack_b;

  public:
    //-------------- constructor ----------

    // copy constructor
    stack(const stack<T>& a) {
      this->stack_a = a.stack_a;
      this->stack_b = a.stack_b;
    }

    // default constructor
    stack() {
    }

    ~stack() {
    }

    //------------- capacity function -------------------
    bool empty() const {
      return stack_a.empty() && stack_b.empty();
    }

    size_t size() const {
      return stack_a.size() + stack_b.size();
    }

    //----------------- modifier -------------
    void push(const T& element) {
      stack_a.push(element);
    }
    void pop();

    void push_bottom(const T& element);

    void pop_bottom();
    
    //----------------- access -----------------
    const T& top();

    const T& bottom();

};

}

#endif


