#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int n,w;
queue<pair<int, multiset<int>::iterator>> tempErase;
multiset<int> S;

int main()
{
    // This makes std::cin and std::cout faster
    std:ios_base::sync_with_stdio(false); std::cin.tie(0);

    // Input n (amount of inputs) and w (size of each subset - 1)
    cin >> n >> w;
    for(int i = 0; i < n; i++)
    {
        // Input number
        int num;
        cin >> num;
        // Insert num to multiset S;
        multiset<int>::iterator it = S.insert(num);
        // Push new element to a queue
        tempErase.push(make_pair(num, it));
        
        // If subset has a size of w+1
        if(S.size() == w+1)
        {
            // Find median iterator
            multiset<int>::iterator median = next(S.begin(), w/2);
            // Output a median value
            cout << *median << " ";
            // Remove element by using iterator
            S.erase(tempErase.front().second);
            // Remove front element of a queue
            tempErase.pop();
        }
    }
    return 0;
}