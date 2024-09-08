#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> ReceiveCard, MaxPower;
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    // Initialize
    cin >> n >> m;
    MaxPower.assign(m,1);
    ReceiveCard.resize(n);

    // Input Card Power
    for(int i = 0; i < n; i++) { cin >> ReceiveCard[i]; }
    
    for(int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if(ReceiveCard[i] > MaxPower[type]) MaxPower[type] = ReceiveCard[i];
        cout << *(min_element(MaxPower.begin(), MaxPower.end())) << " ";
    }
}
