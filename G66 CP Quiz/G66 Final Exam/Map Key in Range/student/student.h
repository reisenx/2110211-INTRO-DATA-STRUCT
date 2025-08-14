#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "map_bst_lite.h"

/*  ---------- Map Key in Range ----------
    - To read all nodes of a tree, we use inorder traversal
    - Check key that more than or equal 'a' --> Use !mLess(n->data.first, a)
    - Check key that less than or equal 'b' --> Use !mLess(b, n->data.first)
    - Only push_back to result for the key in range [a,b]
    ---------- Inorder Traversal ----------
    void inorder(node *n)
    {
        if(n == NULL) return;
        inorder(n->left);
        cout << n->data;
        inorder(n->right);
    }
*/

template <typename KeyT,
        typename MappedT,
        typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, const KeyT &a, const KeyT &b, std::vector<MappedT> &result) const {
    if(n == NULL) return;
    // Jump to the left node, then call the recursive function
    // Only jump when a current node is more than or equal 'a'
    if(!mLess(n->data.first, a)) my_recur(n->left,a,b,result);
    // push_back only element that in range [a,b]
    // n->data is std::pair<KeyT, ValueT>
    if(!mLess(n->data.first, a) && !mLess(b, n->data.first))
    {
        result.push_back(n->data.second);
    }
    // Jump to the right node, then call the recursive function
    // Only jump when a current node is less than or equal 'b'
    if(!mLess(b, n->data.first)) my_recur(n->right,a,b,result);
}

template <typename KeyT,
        typename MappedT,
        typename CompareT>
std::vector<MappedT> CP::map_bst<KeyT, MappedT, CompareT>::value_in_key_range(const KeyT &a, const KeyT &b) const {
    std::vector<MappedT> result;
    my_recur(mRoot,a,b,result);
    return result;
}

#endif
