#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> A, SUM;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
        if(i == 0) { SUM.push_back(A[i]); }
        else if(i == 1) { SUM.push_back(SUM[i-1] + A[i]); }
        else if(i == 2)
        {
            temp = max(SUM[i-2], SUM[i-1]) + A[i];
            SUM.push_back(temp);
        }
        else
        {
            temp = max( SUM[i-3], max(SUM[i-2], SUM[i-1]) ) + A[i];
            SUM.push_back(temp);
        }
    }
    cout << SUM[N-1];
}