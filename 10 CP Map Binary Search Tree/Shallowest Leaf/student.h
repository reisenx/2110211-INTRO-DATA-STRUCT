#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

/*  ---------- Shallowest Leaf ----------
    Recursive function
    Given Leaf node   = 0
    Given Unary node  = child + 1
    Given Binary node = min(left_child+1, right_child+1)
    NOTE: Unary node is a node that has one child
*/
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if(n->left == NULL && n->right == NULL) return 0;
  if(n->right == NULL) return shallowest_leaf(n->left) + 1;
  if(n->left == NULL) return shallowest_leaf(n->right) + 1;
  return std::min(shallowest_leaf(n->left)+1, shallowest_leaf(n->right)+1);

}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  // If it is empty tree, return -1
  if(mRoot == NULL) return -1;
  return shallowest_leaf(mRoot);
}


#endif
