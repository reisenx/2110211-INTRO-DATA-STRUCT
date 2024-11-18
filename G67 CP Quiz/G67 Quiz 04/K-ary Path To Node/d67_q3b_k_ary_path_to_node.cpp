#include<iostream>
#include<stack>
using namespace std;
/*  --------- K-ary Heap ---------
    Children nodes of 'n' are [Kn+1, Kn+2, ... Kn+K]
    Parent node of 'n' is (n-1)/K
    - Path 0: Node Kn+1 to n   | ((Kn+1)-1) mod K = 0
    - Path 1: Node Kn+2 to n   | ((Kn+2)-1) mod K = 1
    - ...
    - Path K-1: Node Kn+K to n | ((Kn+K)-1) mod K = K-1
*/

long long int N,K,node;
stack<long long int> paths;
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input number of nodes and K
    cin >> N >> K >> node;
    // Loop jump from node to node 0 (Jump from child to parent is easier)
    while(node > 0)
    {
        paths.push((node-1) % K);
        node = (node-1)/K;
    }
    // Output
    cout << paths.size() << "\n";
    while(!paths.empty())
    {
        cout << paths.top() << " ";
        paths.pop();
    }
    return 0;
}