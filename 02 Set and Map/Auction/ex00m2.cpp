#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int N,M,A;
vector<int> items;
vector<set<pair<int,int>>> products;
vector<map<int,int>> customers;
int main()
{
    // Make std::cin and std:: cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> N >> M >> A;

    // Input numbers of each items
    items.resize(N);
    products.resize(N);
    customers.resize(M);
    for(int i = 0; i < N; i++) { cin >> items[i]; }

    // BIDDING ACTIONS
    while(A--)
    {
        string action;
        cin >> action;

        /* Action: Bidding (B)
        - Insert (price, customer_num) in a set in vector 'products' at index products_num
        - Update price in a map in vector 'customers' at index customer_num
        */
        if(action == "B")
        {
            int c_num, p_num, price;
            cin >> c_num >> p_num >> price;
            // Case 1: That customer never bid that product yet
            if(customers[c_num-1].find(p_num-1) == customers[c_num-1].end())
            {
                products[p_num-1].insert(make_pair(price, c_num-1));
                customers[c_num-1][p_num-1] = price;
            }
            // Case 2: That customer is already bid that product (overwrite the old data)
            else
            {
                // Remove old bidding data
                products[p_num-1].erase(make_pair(customers[c_num-1][p_num-1], c_num-1));
                // Insert new bidding data
                products[p_num-1].insert(make_pair(price, c_num-1));
                customers[c_num-1][p_num-1] = price;
            }
        }

        /* Action: Withdraw (W)
        - Remove {price, customer_num} from a set in vector 'products' at index products_num
        - Remove product_num from vector 'customers' at index customer_num
        - Beware that the user might withdraw the item they never bid
        */
        else if(action == "W")
        {
            int c_num, p_num;
            cin >> c_num >> p_num;
            // Check if item that use is going to withdraw exists
            if(customers[c_num-1].find(p_num-1) != customers[c_num-1].end())
            {
                // Remove bidding data
                products[p_num-1].erase(make_pair(customers[c_num-1][p_num-1], c_num-1));
                customers[c_num-1].erase(p_num-1);
            }
        }
    }

    // OUTPUT
    for(int c_num = 0; c_num < M; c_num++)
    {
        // That user does bid something
        if(customers[c_num].size() > 0)
        {
            // Put the item that user gain in this vector
            vector<int> itemsGained;
            // Check each item that user bid
            for(auto &bidding: customers[c_num])
            {
                // Check from the end of a set to the front (set is sorted in ascending order)
                int p_num = bidding.first, price = bidding.second;
                int bids = products[p_num].size();
                auto itr = products[p_num].rbegin();
                for(int temp = 0; temp < min(items[p_num], bids); temp++)
                {
                    if(make_pair(price, c_num) == *itr) { itemsGained.push_back(p_num + 1); break; }
                    itr++;
                }
            }
            // Output
            if(itemsGained.size() > 0) { for(auto &x : itemsGained) cout << x << " "; }
            else cout << "NONE";
            cout << "\n";
        }
        // That user never bid anything
        else cout << "NONE\n";
    }
    return 0;

    /* DEBUG
    for(int p_num = 0; p_num < N; p_num++)
    {
        cout << "PRODUCT " << p_num+1 << endl;
        for(auto &x : products[p_num])
        {
            cout << "CUSTOMER " << x.second+1 << " - PRICE: " << x.first << endl;
        }
    }
    for(int c_num = 0; c_num < M; c_num++)
    {
        cout << "CUSTOMER " << c_num+1 << endl;
        for(auto &x: customers[c_num])
        {
            cout << "ITEM " <<  x.first+1 << " - PRICE: " << x.second << endl;
        }
    }
    */
}