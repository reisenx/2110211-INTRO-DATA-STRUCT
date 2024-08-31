#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k;
vector<int> A;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        auto lw = lower_bound(A.begin(), A.end(), p-k);
        auto up = upper_bound(A.begin(), A.end(), p+k);
        cout << up - lw << " ";
    }
}