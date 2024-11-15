#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

/*  ---------- Subtree Extract ----------
    1.) Find size of the left subtree by using recursive function process()
    2.) Set left and right mRoot to link the subtree
    3.) Update mSize of left and right subtree
    4.) Set all mRoot children to NULL (mSize = 1)
*/
template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  // If it is an empty tree, return 0
  if(n == NULL) return 0;
  // If it is leaf node
  if(n->left == NULL && n->right == NULL) return 1;
  // Unary node (Has one child)
  if(n->left == NULL) return process(n->right) + 1;
  if(n->right == NULL) return process(n->left) + 1;
  // Binary node (Has two children)
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  // If it is an empty tree, return empty pair
  if(mRoot == NULL) return std::pair<KeyT,MappedT>();
  // Count nodes on both subtree
  size_t leftSize = process(mRoot->left);
  size_t rightSize = mSize - (leftSize + 1); // Include root node
  // Link both subtree to new mRoot
  left.mRoot = mRoot->left;
  right.mRoot = mRoot->right;
  // Update mSize of both subtree
  left.mSize = leftSize;
  right.mSize = rightSize;
  // Update mRoot and mSize
  mRoot->left = NULL;
  mRoot->right = NULL;
  mSize = 1;
  // Return a value
  return mRoot->data;
}

#endif