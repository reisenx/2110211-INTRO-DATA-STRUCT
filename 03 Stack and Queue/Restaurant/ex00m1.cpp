#include<iostream>
using namespace std;
int N,M,Time = 0;
int main()
{
    // Make std::cin and std:: cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input N,M
    cin >> N >> M;
    // Input time used when eating food of each chef
    int ChefTime[N + 10];
    for(int i = 0; i < N; i++) { cin >> ChefTime[i]; }

    // Loop until customer (M) reached 0 (0 means false)
    while(M)
    {
        // If time is divisible by ChefTime[i], output it and decreases customers (M) by 1
        for(int i = 0; i < N; i++)
        {
            if(M == 0) break;
            if(Time == 0 || Time % ChefTime[i] == 0) { cout << Time << endl; M--; } 
        }
        // Increase time by 1 each loop
        Time++;
    }
    return 0;
}