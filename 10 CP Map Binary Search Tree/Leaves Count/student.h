#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

/*  ---------- Leaves Count Recursive Function ----------
    - Leaf is a node that node->right and node->left are NULL
    - If the current node is leaf, return 1
    - If the current node has only left child, call the function for left child only
    - If the current node has only right child, call the function for right child only
    - Otherwise, call the function for both children
*/
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count(node* n) {
  if(n->left == NULL && n->right == NULL) return 1;
  if(n->right == NULL) return leaves_count(n->left);
  if(n->left == NULL) return leaves_count(n->right);
  return leaves_count(n->left) + leaves_count(n->right);
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::leaves_count() {
  return leaves_count(mRoot);
}


#endif
