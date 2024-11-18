#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int n,m,initial;
map<int,int> timeBreak, timeSpeed, speedTime;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    cin >> n >> m >> initial;
    // Input car break info
    // Example: [[3,3], [5,1], [6,4]]
    while(n--)
    {
        int time, Break;
        cin >> time >> Break;
        timeBreak[time] = Break;
    }
    // Convert timeBreak to speedTime and timeSpeed
    // Example: initial is 15 and TimeBreak is [[3,3], [5,1], [6,4]]
    // timeSpeed = [[0,15], [3,12], [5,11], [6,7], [10,0]]
    // speedTime = [[0,10], [7,6], [11,5], [12,3], [15,0]]
    timeSpeed[0] = initial;
    speedTime[initial] = 0;
    int speed = initial;
    for(auto &[time, Break] : timeBreak)
    {
        speed = max(speed-Break, 0);
        timeSpeed[time] = speed;
        speedTime[speed] = time;
        // When speed = 0, break the loop
        if(speed == 0) break;
    }

    // Input questions
    while(m--)
    {
        // Input
        int command, data;
        cin >> command >> data;
        
        // Command 1: Ask speed of a input time
        // timeSpeed = [[0,15], [3,12], [5,11], [6,7], [10,0]]
        // If time = 0, we must use [0,15]
        // If time = 6, we must use [6,7]
        // If time = 15, we must use [10,0]
        if(command == 1)
        {
            // Find item that is smaller or equal to the input time
            auto it = prev(timeSpeed.upper_bound(data));
            cout << it->second << endl;
        }
        // Command 2: Find duration of time that has at least that speed
        // speedTime = [[0,10], [7,6], [11,5], [12,3], [15,0]]
        // If speed = 0, we must use [0,10]
        // If speed = 7, we must use [0,10]
        // If speed = 8, we must use [7,6]
        // If speed = 20, we must use [15,0]
        if(command == 2)
        {
            // Find item that is smaller to the input speed
            auto it = speedTime.lower_bound(data);
            if(it != speedTime.begin()) it = prev(it);
            cout << it->second << endl;
        }
    }
}