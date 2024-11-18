#include<iostream>
#include<vector>
using namespace std;

/*  Descendant of k-ary tree
    1-Ary tree: Descendant of node n is node [n+1]
    2-ary tree: Descendant of node n is node [2n+1,2n+2]
    3-Ary tree: Descendant of node n is node [3n+1,3n+2,3n+3]
    4-Ary tree: Descendant of node n is node [4n+1,4n+2,4n+3,4n+4]
    K-Ary tree: Descendant of node n is node [Kn+1,Kn+2,...,Kn+k]  */

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input tests
    int tests;
    cin >> tests;
    while(tests--)
    {
        // Input array
        int nodes, K;
        cin >> nodes >> K;
        vector<int> data(nodes);
        for(int i = 0; i < nodes; i++) { cin >> data[i]; }

        // Check K-ary heap
        bool isHeap = true;
        bool isEnd = false;
        for(int n = 0; n < nodes; n++)
        {
            for(int i = 1; i <= K; i++)
            {
                // Access child node
                int child = K*n + i;
                // If child node does not exist, end the process
                if(child >= nodes) {isEnd = true; break;}
                // If Parent node is less than child node, this is not a K-ary heap
                if(data[n] < data[child]) { isHeap = false; break; }
            }
            if(!isHeap || isEnd) break;
        }

        // Output
        if(isHeap) cout << "true" << endl;
        else cout << "false" << endl;
    }
}