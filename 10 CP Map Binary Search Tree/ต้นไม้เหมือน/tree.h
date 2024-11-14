#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    /*  ---------- Same Binary Tree ----------
        Create methods isSameNode() to check that the current node
        - If the both are NULL (tree ends) then return true
        - If one is NULL (tree ends) but one is not NULL (tree not ends) the return false
        - Check data inside a node
        - Recursive by calling it to check both left and right child of a node
    */
    bool isSameBinaryTree(Tree& t) {
        return isSameNode(mRoot, t.mRoot);
    }
    bool isSameNode(Node *a, Node *b)
    {
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        if(a->data != b->data) return false;
        return isSameNode(a->left, b->left) && isSameNode(a->right, b->right);
    }

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
            r = new Node(x, NULL, NULL);
            mSize++;
            return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
