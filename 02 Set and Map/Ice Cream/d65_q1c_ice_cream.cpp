#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,start;
vector<int> collectMoney(100000);
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input n,m,start
    cin >> n >> m >> start;
    // Input collectMoney details
    // Example: [3,0,0,0,2,0,5,0,0,...]
    collectMoney[0] = start;
    while(n--)
    {
        int a,s;
        cin >> a >> s;
        collectMoney[a] = s;
    }
    // Modify collectMoney
    // Example: [3,0,0,0,2,0,5,0,0,...] --> [3,6,9,12,14,16,21,26,31,...]
    int ADD = start, money = start;
    for(int i = 1; i <= 100000; i++)
    {
        // If current element is not 0, change ADD value
        if(collectMoney[i] != 0) ADD = collectMoney[i];
        // Add money
        money += ADD;
        // Update collectMoney
        collectMoney[i] = money;
    }

    // Input Questions
    while(m--)
    {
        // Input price of an ice-cream and day
        int price, day;
        cin >> price >> day;
        // Case 1: He has enough money to buy an ice-cream
        if(collectMoney[day] > price)
        {
            // Find smallest days that he has enough money to buy an ice-cream
            day = lower_bound(collectMoney.begin(), collectMoney.begin()+day, price) - collectMoney.begin();
        }
        // Case 2: He has not enough money and got scam
        else if(collectMoney[day] < price)
        {
            // We need to increase price by the money he got scammed (collectMoney[day])
            price += collectMoney[day];
            // Find smallest days that he has enough money to buy an ice-cream
            day = lower_bound(collectMoney.begin(), collectMoney.end(), price) - collectMoney.begin();
        }
        // Output
        cout << day << " ";
    }
}