#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int n,m;
set<pair<int,int>> MinOfMax;
int main()
{
    // Make std::cin and std::cout faster
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    // Initialize
    cin >> n >> m;
    vector<int> MaxPower(m,1);
    for(int i = 0; i < m; i++) MinOfMax.insert(make_pair(1,i));

    // Input Card Power
    vector<int> ReceiveCard(n);
    for(int i = 0; i < n; i++) { cin >> ReceiveCard[i]; }
    
    // Input Card Type
    for(int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        // Modify data when that card type has new max power
        if(ReceiveCard[i] > MaxPower[type])
        {
            MinOfMax.erase(make_pair(MaxPower[type], type));
            MaxPower[type] = ReceiveCard[i];
            MinOfMax.insert(make_pair(MaxPower[type], type));
        }
        // Find min of max
        cout << (MinOfMax.begin())->first << " ";
    }
    return 0;
}