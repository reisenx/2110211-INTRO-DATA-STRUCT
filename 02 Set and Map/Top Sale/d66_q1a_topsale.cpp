#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int M,N;
map<int,int> products;
map<int,set<int>> sales;
int main()
{
    // Make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> N >> M;
    // Input Products
    while(N--)
    {
        int num;
        cin >> num;
        products[num] = 0;
    }
    // Input Operations
    while(M--)
    {
        int command;
        cin >> command;
        // Operation 1: Buy
        if(command == 1)
        {
            // Input product code, amount
            int code, newAmount;
            cin >> code >> newAmount;
            // Skip loop, if product code is not in products
            if(products.find(code) == products.end()) continue;
            // Calculate newAmount of that product
            int currentAmount = products[code];
            newAmount += currentAmount;
            // Erase that product from sales
            if(currentAmount > 0)
            {
                sales[currentAmount].erase(code);
                if(sales[currentAmount].size() == 0) { sales.erase(currentAmount); }
            }
            // Update amount of that product
            products[code] = newAmount;
            // Add that product to sales
            sales[newAmount].insert(code);
        }
        // Operation 2: Top Sales
        if(command == 2)
        {
            // Input
            int K;
            cin >> K;

            // Case 1: No sales
            if(sales.size() == 0) cout << "NONE" << endl;
            else
            {
                auto it = sales.lower_bound(K);
                // Case 2: No Top sales (lower_bound and got sales.begin())
                if(it == sales.begin()) cout << "NONE" << endl;
                // Case 3: Has top sales
                else
                {
                    // Amount of sales that lower than K is at previous item
                    it = prev(it);
                    // Get last item of a set from a map
                    cout << *(it->second.rbegin()) << endl;
                }
            }
        }
    }
}