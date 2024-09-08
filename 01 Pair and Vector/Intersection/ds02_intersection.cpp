#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> A,B,C;
int main()
{
    // Make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input vector A and B and sort them
    cin >> N >> M;
    A.resize(N);
    B.resize(M);
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    for(int i = 0; i < M; i++) { cin >> B[i]; }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    /* Two Pointer Technique
    Given pointer 'i' is a pointer of vector A (starts at the front)
    Given pointer 'j' is a pointer of vector B (starts at the front)
    */
    int i = 0, j = 0;
    // Loop until i and j exceed their vector size
    while(i < A.size() && j < B.size())
    {
        // Case 1: A[i] is to low, move the pointer 'i' to the right
        if(A[i] < B[j]) i++;
        // Case 2: B[j] is too low, move the pointer 'j' to the right 
        else if(A[i] > B[j]) j++;
        // Case 3: Found the intersection (A[i] is equal to B[j])
        else if(A[i] == B[j])
        {
            // Case 3.1: A[i] is not in vector C yet (push_back A[i], then move both pointer to the right)
            // Case 3.2: A[i] is already in vector C (only move both pointer to the right) 
            if(C.size() == 0) C.push_back(A[i]);
            else if(A[i] != *(C.rbegin())) C.push_back(A[i]);
            i++; j++;
        }
    }

    // Output all items in vector C
    for(auto &x : C) { cout << x << " "; }
}