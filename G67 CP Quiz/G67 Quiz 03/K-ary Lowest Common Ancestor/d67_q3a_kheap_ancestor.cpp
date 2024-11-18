#include<iostream>
using namespace std;
int N,K,p,q;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> N >> K >> p >> q;
    
    // ----- K-ary heap -----
    // parent of node n is (n-1)/K
    // Loop jump to their parent until node p is q is equal
    while(p != q)
    {
        // If p > q, jump node p to its parent until less than or equal q
        while(p > q) { p = (p-1)/K; }
        // If q > p, jump node q to its parent until less than or equal p
        while(q > p) { q = (q-1)/K; }
    }
    // Return common ancestor node
    cout << p;
    return 0;
}