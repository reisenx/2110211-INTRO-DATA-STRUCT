#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int M,N;
set<int> A,B,C;

int main()
{
    cin >> M >> N;
    while(M--)
    {
        int temp;
        cin >> temp;
        A.insert(temp);
    }
    while(N--)
    {
        int temp;
        cin >> temp;
        B.insert(temp);
    }
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
    for(auto it = C.begin(); it != C.end(); it++)
    {
        cout << *it << " ";
    }
}