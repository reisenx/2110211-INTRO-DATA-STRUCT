#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

namespace CP {

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::node_relation(iterator it1, iterator it2) {
    /*  Since tree_iterator class and node class are not friend class in this problem
        So we can't use it1.ptr->next because ptr is protected
        We need to use find_node() function instead */
    node* temp;
    node* node1 = find_node((*it1).first, mRoot, temp);
    node* node2 = find_node((*it2).first, mRoot, temp);
    
    /*  Parent-Child relationship
        - Node 1 is parent of node 2
        - Node 2 is parent of node 1    */
    if(node1 == node2->parent || node2 == node1->parent) { return 1; }
    
    /*  Ancestor-Descendant relationship
        - Same nodes are ancestor-descendant relationship (for this problem)
        - Root node are ancestor of all nodes in a tree
        - Jump node 1 to its parent until node 2 is found
        - Jump node 2 to its parent until node 1 is found   */
    if(node1 == node2) return 2;
    if(node1 == mRoot || node2 == mRoot) return 2;

    while(node1 != node2 && node1 != mRoot)
    {
        node1 = node1->parent;
        if(node1 == node2) return 2;
    }
    node1 = find_node((*it1).first, mRoot, temp);

    while(node1 != node2 && node2 != mRoot)
    {
        node2 = node2->parent;
        if(node1 == node2) return 2;
    }
    node2 = find_node((*it2).first, mRoot, temp);

    //  Node Height
    //  Count how many times needed to jump node to its parent until mRoot is found
    int depth1 = 0, depth2 = 0;
    while(node1 != mRoot)
    {
        node1 = node1->parent;
        depth1++;
    }
    while(node2 != mRoot)
    {
        node2 = node2->parent;
        depth2++;
    }

    //  Different depth
    if(depth1 != depth2) return 3;
    //  Same depth
    if(depth1 == depth2) return 4;
}

}

#endif