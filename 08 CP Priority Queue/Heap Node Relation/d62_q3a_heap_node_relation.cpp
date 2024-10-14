#include<iostream>
using namespace std;

/* Node Ancestor-Descendant Relation
Node 0 is ancestor of all nodes
Ancestor of node n is node (n-1)/2 */
bool checkDescendant(int parent, int child)
{
    // Parent node is 0 (Always true)
    if(parent == 0) return true;
    
    // Loop jump child node until reach parent node
    while(child > parent) { child = (child-1)/2; }
    if(child == parent) return true;
    return false;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int n, m;
    cin >> n >> m;
    
    while(m--)
    {
        // Input node a and node b
        int a,b;
        cin >> a >> b;
        
        // Both are the same node
        if(a == b) cout << "a and b are the same node" << endl;
        // Both are the different node
        else if(a < b && checkDescendant(a,b)) cout << "a is an ancestor of b" << endl;
        else if(b < a && checkDescendant(b,a)) cout << "b is an ancestor of a" << endl;
        else cout << "a and b are not related" << endl;
    }
}