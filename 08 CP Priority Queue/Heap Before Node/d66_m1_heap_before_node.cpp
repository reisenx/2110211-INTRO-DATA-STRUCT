#include<iostream>
#include<vector>
using namespace std;
int nodes, currentNode;
vector<int> descendants;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input nodes and current node
    cin >> nodes >> currentNode;
    
    /* Heap Before Node
    All nodes that is not descendants of currentNode have a chance to have greater value than currentNode
    So this problem, just output all non-descendants of currentNode */

    // Find all descendant of currentNode
    int current = 0;
    descendants.push_back(currentNode);
    while(true)
    {
        // Find left_child and right_child
        int left_child = 2*descendants[current] + 1;
        int right_child = 2*descendants[current] + 2;
        
        // push_back left_child and right_child to the vector until in exceed nodes
        if(left_child >= nodes) break;
        descendants.push_back(left_child);
        if(right_child >= nodes) break;
        descendants.push_back(right_child);
        
        // Shift currentNode by 1
        current++;
    }

    // Output
    cout << nodes - descendants.size() << endl;
    // Given 'i' is a pointer in descendants vector
    int i = 0;
    for(int node = 0; node < nodes; node++)
    {
        if(i < descendants.size())
        {
            if(node != descendants[i]) cout << node << " ";
            else i++;
        }
        else cout << node << " ";
    }
    return 0;
}