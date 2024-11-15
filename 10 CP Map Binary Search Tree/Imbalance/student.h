/*  ---------- Imbalance ----------
    1.) children() function
    This function return maximum children height of each node
    - Given NULL        = -1
    - Given leaf node   = 0
    - Given Unary node  = children(child) + 1
    - Given Binary node = max(children(left)+1, children(right)+1)

    2.) getImbalance() function
    - Imbalance = |children(left) - children(right)|
    - If imbalance > maxImbalance, change value
    - If imbalance == maxImbalance, use mLess(newValue, value) before change
    - Call the function to its children
*/

KeyT getValueOfMostImbalanceNode() {
    KeyT value;
    int maxImbalance = -1;
    getImbalance(mRoot, value, maxImbalance);
    return value;
}

int children(node *n) 
{
    if(n == NULL) return -1;
    if(n->left == NULL && n->right == NULL) return 0;
    if(n->right == NULL) return children(n->left) + 1;
    if(n->left == NULL) return children(n->right) + 1;
    return std::max(children(n->left)+1, children(n->right)+1);
}

void getImbalance(node *n, KeyT &value, int &maxImbalance)
{
    // If node is NULL, do nothing
    if(n == NULL) return;
    
    int left, right, imbalance;
    left = children(n->left);
    right = children(n->right);
    imbalance = std::abs(left - right);
    if(imbalance > maxImbalance)
    {
        maxImbalance = imbalance;
        value = n->data.first;
    }
    if(imbalance == maxImbalance && mLess(n->data.first, value)) { value = n->data.first; }

    getImbalance(n->left, value, maxImbalance);
    getImbalance(n->right, value, maxImbalance);
}