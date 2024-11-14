#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

/*  --------- My Recursive Function ---------
    1.) node n is the current node
    2.) level is desired level
    3.) tmp is current level in a tree
    4.) v is a vector to contains all nodes in that tree
    We need the data inside the vector to be in descending order
    So we need to traverse from the rightmost to the leftmost of a tree
*/
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,size_t level,size_t tmp,std::vector<KeyT> &v) {
  // If current node is NULL, stop the process
  if(n == NULL) return;
  // If current level is exceed level, stop the process
  if(tmp > level) return;
  // If current level is at the level we want, push_back the key to a vector
  if(tmp == level) v.push_back(n->data.first);
  // Traverse to the rightmost to the leftmost of a tree
  // Don't forget to update current level of the node (tmp+1)
  my_recur(n->right, level, tmp+1, v);
  my_recur(n->left, level, tmp+1, v);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT,MappedT,CompareT>::at_level(size_t level) {
  // Create a std::vector to store all keys
  std::vector<KeyT> keys;
  // Use recursive function above to find all keys at the level
  // Start at mRoot (Level = 0)
  my_recur(mRoot, level, 0, keys);
  return keys;
}


#endif
