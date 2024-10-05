#include "stack.h"
#include "queue.h"

namespace CP {
    /* appendStack() | top() is the rightmost element
    Example: S1 = [1,2,3,4,5] and S2 = [11,12]
    S1.append(S2) --> S1 = [11,12,1,2,3,4,5]
    */
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        CP::stack<T> temp;
        // Move item from S1 to temp
        // S1 = [1,2,3,4,5] --> temp = [5,4,3,2,1]
        while(!empty()) { temp.push(top()); pop(); }
        // Move item from temp to S2
        // temp = [5,4,3,2,1] --> S2 = [11,12,1,2,3,4,5]
        while(!temp.empty()) { s.push(temp.top()); temp.pop(); }
        // Assign S2 to S1
        *this = s;
    }

    /* appendQueue() | front() = leftmost | top() = rightmost
    Example: S1 = [1,2,3,4,5] and Q1 = [6,7,8,9]
    S1.append(Q1) --> S1 = [9,8,7,6,1,2,3,4,5]
    */
    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        CP::stack<T> tempQ, tempS;
        // Move item from Q1 to tempQ
        // Q1 = [6,7,8,9] --> tempQ = [6,7,8,9]
        while(!q.empty()) { tempQ.push(q.front()); q.pop(); }
        // Move item from S1 to tempS
        // S1 = [1,2,3,4,5] --> tempS = [5,4,3,2,1]
        while(!empty()) { tempS.push(top()); pop(); }
        // Move item from tempQ to S1
        // tempQ = [6,7,8,9] --> S1 = [9,8,7,6]
        while(!tempQ.empty()) { push(tempQ.top()); tempQ.pop(); }
        // Move item from tempS to S1
        // tempS = [5,4,3,2,1] --> S1 = [9,8,7,6,1,2,3,4,5]
        while(!tempS.empty()) { push(tempS.top()); tempS.pop(); }
    }

    /* appendStack() | front() = leftmost | top() = rightmost
    Example: S1 = [1,2,3,4,5] and Q1 = [6,7,8,9]
    Q1.append(S1) --> Q1 = [6,7,8,9,5,4,3,2,1]
    */
    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        // pop() S1 to push() Q1
        while(!s.empty()) { push(s.top()); s.pop(); }
    }

    /* appendQueue() | front() is the leftmost element
    Example: Q1 = [6,7,8,9] and Q2 = [16,17]
    Q1.appendQueue(Q2) --> Q1 = [6,7,8,9,16,17]
    */
    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        // pop() Q2 and push() to Q1
        while(!q.empty()) { push(q.front()); q.pop(); }
    }
}
