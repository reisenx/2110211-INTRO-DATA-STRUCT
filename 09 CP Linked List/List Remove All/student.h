#ifndef __STUDENT_H_
#define __STUDENT_H_

/*  ---------- List Remove All ----------
    [10, 20, 30, 10, 40, 50, 60, 10, 70] --> [20, 30, 40, 50, 60, 70]
    - Start at first node (Use begin() or iterator(mHeader->next))
    - Iterate until last node (Use end() or iterator(mHeader))
    - If found element to remove, remove them
*/

template <typename T>
void CP::list<T>::remove_all(const T& value) {
    // Iterate the list from first node to the last node
    for(auto it = begin(); it != end(); it++)
    {
        // Find an element the delete
        if(*it == value)
        
        {
            // Get position of previous and next of the current node
            auto nextIt(it.ptr->next);
            auto prevIt(it.ptr->prev);
            // Change the next pointer previous node to the it.ptr->next
            prevIt->next = nextIt;
            // Change the previous pointer next node to the it.ptr->prev
            nextIt->prev = prevIt;
            // Delete the current node pointer and decrease mSize by 1
            delete it.ptr;
            mSize--;
        }
    }
}

#endif
