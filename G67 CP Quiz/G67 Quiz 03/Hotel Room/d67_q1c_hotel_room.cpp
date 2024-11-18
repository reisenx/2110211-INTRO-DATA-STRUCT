#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N,M,totalCapacity = 0;
map<int, priority_queue<int>> capacityFloor;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> N >> M;

    // ----- CapacityFloor-----
    // capacityFloor contain {Capacity : [List of floor sorted in descending order]}
    // Example: capacityRooms = {10 : [5,3,2]} means Floor 2,3,5 has capacity = 10
    for(int floor = 1; floor <= N; floor++)
    {
        int capacity;
        cin >> capacity;
        capacityFloor[capacity].push(floor);
        totalCapacity += capacity;
    }

    while(M--)
    {
        int customers;
        vector<pair<int,int>> output;
        cin >> customers;
        // Check if, customers exceed totalCapacity
        if(customers > totalCapacity) cout << -1;
        else
        {
            // Update totalCapacity
            totalCapacity -= customers;

            // Loop the process until all customers has their room
            while(customers > 0)
            {
                // Find a smallest floor that greater or equal to customers
                auto it = capacityFloor.lower_bound(customers);
                int floor, booked, capacity;

                // If the largest floor can't fit all customers
                // - Put the customer to the largest floor first
                // - Find how many customer is booking their floor in each process
                if(it == capacityFloor.end()) it--;
                capacity = it->first;
                booked = min(capacity, customers);
                // Get floor number
                floor = it->second.top();
                // Put (floor, booked) data to output vector
                output.push_back(make_pair(floor, booked));
                // Add the floor new status to capacityFloor
                capacityFloor[capacity - booked].push(floor);
                it->second.pop();
                // Remove item in capacityFloor, if empty
                if(it->second.empty()) capacityFloor.erase(it);
                // Update customers
                customers -= booked;
            }

            // Output (Sorted by floor number in ascending order)
            sort(output.begin(), output.end());
            for(auto &[floor, booked] : output)
            {
                cout << floor << " " << booked << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}