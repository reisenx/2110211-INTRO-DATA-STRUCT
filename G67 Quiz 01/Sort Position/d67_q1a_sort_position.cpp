#include<bits/stdc++.h>
using namespace std;
int N, Index[1000005];
// Using std::greater will make the priority_queue sort in ascending order
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> SortedNums;
int main()
{
    // Make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input amount of number
    cin >> N;
    // Loop push pair of (number, index) to a priority_queue (automatically sorted in ascending order)
    for(int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        SortedNums.push(make_pair(num,i));
    }

    // Initialize Position to 1
    int Position = 1;
    // Get index data after sorted
    for(int i = 0; i < N; i++)
    {
        // Get initial index of each number
        int data = SortedNums.top().second - 1;
        // Put postion data into an array
        Index[data] = Position;
        // Remove used data
        SortedNums.pop();
        // Increase position by 1
        Position++;
    }

    // Output
    for(int i = 0; i < N; i++) { cout << Index[i] << " "; }
    return 0;
}