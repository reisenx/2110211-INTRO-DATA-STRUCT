#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int M,N;
set<int> A,B,C;
int main()
{
    // Make std::cin and std:: cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input vector A and B
    cin >> N >> M;
    for(int i = 0; i < N; i++) { int temp; cin >> temp; A.insert(temp); }
    for(int i = 0; i < M; i++) { int temp; cin >> temp; B.insert(temp); }

    // Find intersection of vector A and B and put the value in vector C
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));

    // Output all items in vector C
    for(auto &x : C) { cout << x << " "; }
    return 0;
}