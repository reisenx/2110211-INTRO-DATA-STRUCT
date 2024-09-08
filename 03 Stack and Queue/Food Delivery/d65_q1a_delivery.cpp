#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
vector<int> TotalMoney;
queue<int> FoodOrders[5];
int main()
{
    // Make std::cin and std::cout faster
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    // Input SalesTarget
    cin >> n >> m;
    vector<int> SalesTarget(m);
    for(int i = 0; i < m; i++) { cin >> SalesTarget[i]; }

    // Input Actions
    for(int i = 0; i < n; i++)
    {
        int command;
        cin >> command;
        // Command: 1 (Input Order)
        if(command == 1)
        {
            // Push new order to FoodOrders
            int app,price;
            cin >> app >> price;
            FoodOrders[app].push(price);
        }
        // Command: 2 (Cooking)
        if(command == 2)
        {
            int price;
            // Get price of the lowest price order
            if(FoodOrders[1].empty()) price = FoodOrders[2].front();
            else if(FoodOrders[2].empty()) price = FoodOrders[1].front();
            else price = min(FoodOrders[1].front(), FoodOrders[2].front());
            // Find total money of the current order and push_back to TotalMoney
            if(TotalMoney.size() == 0) TotalMoney.push_back(price);
            else
            {
                int total = price + *(TotalMoney.rbegin());
                TotalMoney.push_back(total);
            }
            // Remove the current order (We're done cooking)
            if(FoodOrders[1].empty()) FoodOrders[2].pop();
            else if(FoodOrders[2].empty()) FoodOrders[1].pop();
            else if(FoodOrders[1].front() < FoodOrders[2].front()) FoodOrders[1].pop();
            else if(FoodOrders[2].front() < FoodOrders[1].front()) FoodOrders[2].pop();
            else FoodOrders[1].pop();
        }
    }

    // Output
    for(int i = 0; i < m; i++)
    {
        // Find the first total money the is greater or equal to the sales target
        auto it = lower_bound(TotalMoney.begin(), TotalMoney.end(), SalesTarget[i]);
        // If not found, output -1 instead
        if(it == TotalMoney.end()) cout << -1 << " ";
        else cout << it - TotalMoney.begin() + 1 << " ";
    }
    return 0;
}