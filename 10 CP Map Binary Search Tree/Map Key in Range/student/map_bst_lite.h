#ifndef _CP_MAP_BST_INCLUDED_
#define _CP_MAP_BST_INCLUDED_

#include <iostream>
#include <vector>
//#pragma once

namespace CP {

template <typename KeyT,
          typename MappedT,
          typename CompareT = std::less<KeyT> >
class map_bst
{
  protected:

    typedef std::pair<KeyT,MappedT> ValueT;

    class node {
      friend class map_bst;
      protected:
        ValueT data;
        node  *left;
        node  *right;

        node() :
          data( ValueT() ), left( NULL ), right( NULL ) { }

        node(const ValueT& data, node* left, node* right) :
          data ( data ), left( left ), right( right ) { }
    };
  
  node     *mRoot;
  CompareT  mLess;
  size_t    mSize;

  protected:
    node* &child_link(node* parent, const KeyT& k) {
        if (parent == NULL) return mRoot;
        return mLess(k, parent->data.first) ?
               parent->left : parent->right;
    }
    int compare(const KeyT& k1, const KeyT& k2) {
      if (mLess(k1, k2)) return -1;
      if (mLess(k2, k1)) return +1;
      return 0;
    }
    node* find_node(const KeyT& k,node* r, node* &parent) {
      node *ptr = r;
      while (ptr != NULL) {
        int cmp = compare(k, ptr->data.first);
        if (cmp == 0) return ptr;
        parent = ptr;
        ptr = cmp < 0 ? ptr->left : ptr->right;
      }
      return NULL;
    }

    node* find_min_node(node* r) {
      //r must not be NULL
      node *min = r;
      while (min->left != NULL) {
        min = min->left;
      }
      return min;
    }

    node* find_max_node(node* r) {
      //r must not be NULL
      node *max = r;
      while (max->right != NULL) {
        max = max->right;
      }
      return max;
    }

    node* copy(node* src, node* parent) {
        if (src == NULL) return NULL;
        node* tmp   = new node();
        tmp->data   = src->data;
        tmp->left   = copy(src->left,  tmp);
        tmp->right  = copy(src->right, tmp);
        return tmp;
    }
    void delete_all_nodes(node *r) {
        if (r == NULL) return;
        delete_all_nodes(r->left);
        delete_all_nodes(r->right);
        delete r;
    }
    void my_recur(node* n, const KeyT &a, const KeyT &b, std::vector<MappedT> &result) const;

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    map_bst(const map_bst<KeyT,MappedT,CompareT> & other) :
      mLess(other.mLess) , mSize(other.mSize)
    {
        mRoot = copy(other.mRoot, NULL);
    }

    // default constructor
    map_bst(const CompareT& c = CompareT() ) :
      mRoot(NULL), mLess(c) , mSize(0)
    { }

    // copy assignment operator using copy-and-swap idiom
    map_bst<KeyT,MappedT,CompareT>& operator=(map_bst<KeyT,MappedT,CompareT> other)  {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be destructed
      using std::swap;
      swap(this->mRoot, other.mRoot);
      swap(this->mLess, other.mLess);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~map_bst() {
      clear();
    }

    //------------- capacity function -------------------
    bool empty() {
      return mSize == 0;
    }

    size_t size() {
      return mSize;
    }

    //----------------- modifier -------------
    void clear() {
      delete_all_nodes(mRoot);
      mRoot = NULL;
      mSize = 0;
    }

    MappedT& operator[](const KeyT& key) {
      node *parent = NULL;
      node *ptr = find_node(key, mRoot, parent);
      if (ptr == NULL) {
        ptr = new node(std::make_pair(key,MappedT()),NULL,NULL);
        child_link(parent, key) = ptr;
        mSize++;
      }
      return ptr->data.second;
    }

    bool insert(const ValueT& val) {
      node *parent = NULL;
      node *ptr = find_node(val.first,mRoot,parent);
      bool not_found = (ptr==NULL);
      if (not_found) {
        ptr = new node(val,NULL,NULL,parent);
        child_link(parent, val.first) = ptr;
        mSize++;
      }
      return not_found;
    }

    std::vector<MappedT> value_in_key_range(const KeyT &a, const KeyT &b) const;
};

}

#endif