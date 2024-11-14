#ifndef __STUDENT_H__
#define __STUDENT_H__

/*  ---------- List Check ----------
    1.) Check mHeader is not NULL
    2.) Check first element that is not NULL
*/
template <typename T>
bool CP::list<T>::check() {
  // Check mHeader
  if(mHeader == NULL) return false;
  // Check first element of the linked list
  auto node = mHeader->next;
  if(node == NULL) return false;
  if(node->prev != mHeader) return false;
  // Check the rest of them
  for(int i = 0; i < mSize; i++)
  {
    // Check that the current node is not NULL
    if(node == NULL) return false;
    // Check that the next node is not NULL
    if(node->next == NULL) return false;
    // Check that the current node is not at mHeader (Actual size less than mSize)
    if(node == mHeader) return false;
    // Check that the next node's prev is not NULL
    if((node->next)->prev == NULL) return false;
    // Check that the next node's prev is the current node
    if((node->next)->prev != node) return false;
    // Jump to the next node
    node = node->next;
  }
  // If jump for mSize times, the node must be at mHeader
  return node == mHeader;
}


#endif
