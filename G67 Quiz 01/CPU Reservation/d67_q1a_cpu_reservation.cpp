#include<bits/stdc++.h>
using namespace std;
int N;
set<int> End;
set<pair<int,int>> TimeRange;
map<int,int> BtoA;

// A function to insert data into variables
void InputData(int a, int b)
{
    BtoA[b] = a;
    End.insert(b);
    TimeRange.insert(make_pair(a,b));
}

int main()
{
    // Make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input number of people who wants to use a supercomputer
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        // Input start time (a) and end time (b)
        int a,b;
        cin >> a >> b;
        // Case 1: There are no reservations yet
        // Insert the time range immediately
        if(TimeRange.empty()) { InputData(a,b); cout << i << " "; }
        
        // Case 2: There are already a person who reserve a supercomputer
        else
        {
            // Find the lower_bound of the right time range
            auto RightItr = End.lower_bound(a);
            // Case 2.1: The input time range might be at the front of all
            if(RightItr == End.begin())
            {
                // If end time (b) is less than the start time of the first time range
                // This time range can be reserved
                if(b < BtoA[*RightItr]) { InputData(a,b); cout << i << " "; }
            }
            // Case 2.2: The input time range might be at the end of all
            else if(RightItr == End.end())
            {
                // If start time (a) is more than the end time of the last time range
                // This time range can be reserved 
                if(a > *(End.rbegin())) { InputData(a,b); cout << i << " "; }
            }
            // Case 2.3: The input time range might be between of 2 time ranges
            else
            {
                // Find iterator of the left time range
                auto LeftItr = RightItr;
                LeftItr--;
                // If start time (a) is more than the end time of a time range at the left
                // And if end time (b) is less than the start time of a time range at the right
                if(a > *LeftItr && b < BtoA[*RightItr]) { InputData(a,b); cout << i << " "; }
            }
        }
    }
    return 0;
}