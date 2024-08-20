#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> A,B,C;

int main()
{
    // Input vector
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
    
    // Check if element in vector A in vector B, then add to vector C
    // Beware of duplicate element
    for(int i = 0; i < N; i++)
    {
        if(find(B.begin(), B.end(), A[i]) != B.end() && find(C.begin(), C.end(), A[i]) == C.end())
        {
            C.push_back(A[i]);
        }
    }
    // Sort element in vector C
    sort(C.begin(), C.end());
    
    // Output
    for(auto &x: C)
    {
        cout << x << " ";
    }
}