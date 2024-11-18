/*  ---------- Left Child Right Sibling ----------
    - Given "leaf" is a node that left child and right sibling are NULL
    - Given NULL node = -1
    - Given leaf node = 0
    - A node that has sibling, call a function to its sibling
    - A node that has left child, call a function to its child and plus 1
    - Otherwise, use std::max() between two cases
*/

int depth(node *n)
{
  if(n == NULL) return -1;
  if(n->left_child == NULL && n->right_sibling == NULL) return 0;
  if(n->left_child == NULL) return depth(n->right_sibling);
  if(n->right_sibling == NULL) return depth(n->left_child) + 1;
  return std::max(depth(n->left_child) + 1, depth(n->right_sibling));
}