#include<iostream>
using namespace std;

/*  Node Ancestor-Descendant Relation
    Node 0 is ancestor of all nodes
    Parent of node n is node (n-1)/K  */
bool isChild(long long int parent, long long int child, long long int K)
{
    // Return false, if it's the same node
    if(parent == child) return false;
    return (child-1)/K == parent;
}
bool isDescendant(long long int parent, long long int child, long long int K)
{
    // Return false, if it's the same node
    if(parent == child) return false;
    // Node 0 is ancestor of all nodes
    if(parent == 0) return true;
    // Loop jump child node until reach parent node
    while(child > parent) { child = (child-1)/K; }
    return child == parent;
}

/*  Heap Height
    Given 'h' is K-ary heap height
    From parent of node n is node (n-1)/K
    So we need to jump 'h' times from node n to reach node 0   */
bool isSameHeight(long long int node1, long long int node2, long long int K)
{
    long long int h1 = 0, h2 = 0;
    while(node1 > 0)
    {
        node1 = (node1-1)/K;
        h1++;
    }
    while(node2 > 0)
    {
        node2 = (node2-1)/K;
        h2++;
    }
    return h1 == h2;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input
    int n;
    cin >> n;
    while(n--)
    {
        // Input K, node a and node b
        long long int K,a,b;
        cin >> K >> a >> b;
        /*  Relations of node a and b
            1: Parent-Child Relation
            2: Ancestor-Descendant Relation
            3: Different Heap Height
            4: Same Heap Height */
        if(isChild(a,b,K) || isChild(b,a,K)) cout << "1 ";
        else if(isDescendant(a,b,K) || isDescendant(b,a,K)) cout << "2 ";
        else if(!isSameHeight(a,b,K)) cout << "3 ";
        else cout << "4 ";
    }
    return 0;
}