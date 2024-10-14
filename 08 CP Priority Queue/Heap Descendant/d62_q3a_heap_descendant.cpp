#include<iostream>
#include<vector>
using namespace std;
int nodes, ancestorNode, current = 0;
vector<int> descendantNodes;
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> nodes >> ancestorNode;
    descendantNodes.push_back(ancestorNode);
    
    /* Node Ancestor-Descendant Relation
    Node 0 is ancestor of all nodes
    Descendant of node n is node 2n+1 and 2n+2 */
    // Find all descendantNodes
    while(descendantNodes[current]*2 + 1 < nodes)
    {
        // Add node 2n+1
        descendantNodes.push_back( descendantNodes[current]*2 + 1 );
        // Add node 2n+2
        if(descendantNodes[current]*2 + 2 < nodes)
        {
            descendantNodes.push_back( descendantNodes[current]*2 + 2 );
        }
        // Shift current node
        current++;
    }
    
    // Output
    cout << descendantNodes.size() << endl;
    for(auto &x : descendantNodes){ cout << x << " "; }
}