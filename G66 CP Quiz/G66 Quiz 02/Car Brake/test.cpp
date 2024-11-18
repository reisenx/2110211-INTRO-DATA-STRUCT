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
    }

    for(auto &[speed, time] : speedTime)
    {
        cout << "(" << speed << ", " << time << ")" << endl;
    }
}