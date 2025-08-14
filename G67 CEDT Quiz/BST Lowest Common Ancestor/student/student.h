
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"

/*  ---------- BST Lowest Common Ancestor ----------
    Using recursive function to find common ancestor
    - Start at mRoot
    - If p and q are less than mRoot, that means both p and q is in the left subtree
    - If p and q are more than mRoot, that means both p and q is in the right subtree
    - If it meets two condition above, jump to the left or right child and call the recursive function
    - Otherwise, p and q is in different subtree and the current node is the lowest common ancestor
*/
template <typename KeyT,
        typename MappedT,
        typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // Get key from node p and q (p and q is an iterator)
    // *it is ValueT which is std::pair<KeyT, MappedT>
    KeyT key01 = (*p).first, key02 = (*q).first;
    KeyT currentKey = (n->data).first;
    // If both p and q are in the left subtree, jump to the left child
    if(mLess(key01,currentKey) && mLess(key02,currentKey)) return recursive(n->left,p,q);
    // If both p and q are in the right subtree, jump to the right child
    if(mLess(currentKey,key01) && mLess(currentKey,key02)) return recursive(n->right,p,q);
    // If p and q is in different subtree, return the current node
    return iterator(n);
}


template <typename KeyT,
        typename MappedT,
        typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    return recursive(mRoot,p,q);
}

#endif
