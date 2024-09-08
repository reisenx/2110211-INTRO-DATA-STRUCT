#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Q;
vector<int> v;
int main()
{
    // Make std::cin and std::cout faster
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    // Input number of operations
    cin >> Q;
    while(Q--)
    {
        // Get command
        string command;
        cin >> command;
        // Command: pb x (push_back the value x to a vector)
        if(command == "pb") { int x; cin >> x; v.push_back(x); }
        // Command: sa (sort the vector in ascending order)
        else if(command == "sa") sort(v.begin(), v.end());
        // Command: sd (sort the vector in descending order)
        else if(command == "sd")
        {
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
        }
        // Command: r (reverse the vector)
        else if(command == "r") reverse(v.begin(), v.end());
        // Command: d i (erase the item in index i from a vector)
        else if(command == "d") { int i; cin >> i; v.erase(v.begin()+i); }
    }
    // Output all items in vector
    for(auto &x : v) { cout << x << " "; }
    return 0;
}