#include<iostream>
#include<set>
using namespace std;
int N,M;
set<pair<string,string>> tickets;
int main()
{
    // Make std::cin and std:: cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input tickets
    cin >> N >> M;
    while(N--)
    {
        string flight, seat;
        cin >> flight >> seat;
        tickets.insert(make_pair(flight,seat));
    }

    while(M--)
    {
        // Input booking data of each customers in 'customer'
        int n;
        cin >> n;
        bool isSuccess = true;
        set<pair<string,string>> customer;
        while(n--)
        {
            string flight, seat;
            cin >> flight >> seat;
            // If the booking is not success, just skip the loop
            if(!isSuccess) continue;
            // Insert the booking ticket in set 'customer'
            customer.insert(make_pair(flight,seat));
            // Check if that ticket is still available (If not, set isSuccess to false)
            if(tickets.find(make_pair(flight,seat)) == tickets.end()) isSuccess = false;
        }

        // Output
        if(isSuccess)
        {
            cout << "YES\n";
            // Delete booked tickets
            for(auto &item : customer) { tickets.erase(item); }
        }
        else cout << "NO\n";
    }
    return 0;
}