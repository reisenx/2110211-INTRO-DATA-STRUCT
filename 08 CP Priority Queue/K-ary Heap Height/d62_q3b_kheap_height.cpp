#include<iostream>
#include<cmath>
using namespace std;
long long int n,K, nodes = 0, height = 0;
int main()
{
    // n is amount of nodes of K-ary heap
    // Given K-ary heap Height is 'h'
    // Nodes = k^0 + k^1 + k^2 + k^3 + ... + k^h
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> K;
    
    if(K == 1) cout << n-1;
    else
    {
        
        while(true)
        {
            nodes += pow(K,height);
            if(nodes >= n) break;
            height++;
        }
        cout << height;
    }
    return 0;
}