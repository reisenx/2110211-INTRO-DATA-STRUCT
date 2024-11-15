#ifndef __STUDENT_H_
#define __STUDENT_H_
/*  ---------- A Wise Man Once Said: ----------
    If you cry on seeing the question, it is an insult.
    If your teacher cries upon seeing your answer submission,
    it is your achievement.
    Good luck with final and see you in Algorithm Design.
    -------------------------------------------  */
#include "map_bst.h"
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,int level,int tmp) {
    // If current node is NULL, do nothing
    if(n == NULL) return;
    // Call recursive function to traverse through the tree
    // We need to reach a leaf before deleting a node
    my_recur(n->left, level, tmp+1);
    my_recur(n->right, level, tmp+1);
    // If current level exceed depth, delete that node
    if(tmp > level) { erase(n->data.first); }
}

template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::trim(int depth) {
    // If depth = -1, delete entire tree by erase the mRoot
    if(depth == -1) { erase(mRoot->data.first); }
    // Otherwise, call the recursive function
    my_recur(mRoot, depth, 0);
}

#endif
