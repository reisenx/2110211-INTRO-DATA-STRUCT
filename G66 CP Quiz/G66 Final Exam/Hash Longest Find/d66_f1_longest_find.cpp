#include<iostream>
#include<vector>
using namespace std;
int n,m;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    // Input n and m
    cin >> n >> m;
    // Create a vector with n element, each contains {value, status}
    // status = 0 is empty box
    // status = 1 is deleted box
    // status = 2 is unavailable box
    vector<pair<int,int>> mBuckets(n, {0,0});
    
    while(m--)
    {
        // Input
        int value, command;
        cin >> command >> value;
        // Calculate hash function
        int hash = value % n;
        int j = 0;

        // Command 1: Insertion
        if(command == 1)
        {
            // Probe until find empty box or delete box (status = 0,1)
            // It is guarantee that there are no duplicates
            while(mBuckets[(hash + (j*j)) % n].second == 2) { j++; }
            // Insert value
            mBuckets[(hash + (j*j)) % n] = make_pair(value,2);
        }
        // Command 2: Deletion
        if(command == 2)
        {
            // Probe on deleted box or unavailable box (status = 1,2)
            // It is guarantee that there are no empty box midway, if the input is valid
            while(mBuckets[(hash + (j*j)) % n].second > 0)
            {
                // Check current value
                if(mBuckets[(hash + (j*j)) % n].first == value) { break; }
                j++;
            }
            // Check current value again because value may not exist in the mBuckets at the first place
            if(mBuckets[(hash + (j*j)) % n].first == value)
            {
                // Delete value
                mBuckets[(hash + (j*j)) % n] = make_pair(0,1);
            }
        }
    }

    // Find maximum probing for insertion and deletion
    // Loop each element in vector to find
    int maxInsert = 1, maxDelete = 1;
    for(int hash = 0; hash < n; hash++)
    {
        // Count insertion
        int j = 0;
        while(mBuckets[(hash + (j*j)) % n].second == 2) { j++; }
        maxInsert = max(maxInsert, j+1);

        // Count Deletion
        j = 0;
        while(mBuckets[(hash + (j*j)) % n].second > 0) { j++; }
        maxDelete = max(maxDelete, j+1);
    }

    // Output
    cout << maxInsert << " " << maxDelete;
    return 0;
}