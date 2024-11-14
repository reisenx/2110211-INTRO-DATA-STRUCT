#ifndef __STUDENT_H__
#define __STUDENT_H__

/*  ---------- Unary Count Recursive Function ----------
    - Unary is a node that has only 1 child
    - Leaf is a node that node->right and node->left are NULL
    - If the current node is NULL, return 0
    - If the current node is leaf, return 0
    - If the current node is unary, call the function to its child and plus 1
    - Otherwise, call the function to both children
*/
template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(ptr == NULL) return 0;
  if(ptr->left == NULL && ptr->right == NULL) return 0;
  if(ptr->left != NULL && ptr->right == NULL) return process(ptr->left) + 1;
  if(ptr->left == NULL && ptr->right != NULL) return process(ptr->right) + 1;
  return process(ptr->left) + process(ptr->right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  return process(mRoot);
}

#endif
