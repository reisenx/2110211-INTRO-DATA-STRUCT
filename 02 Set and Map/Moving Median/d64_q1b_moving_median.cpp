#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int n,w;
queue<int> tempErase;
multiset<int> S;
multiset<int>::iterator mid;

int main()
{
    std:ios_base::sync_with_stdio(false); std::cin.tie(0);

    cin >> n >> w;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(i < w)
        {
            S.insert(num);
            tempErase.push(num);
        }
        if(i == w) mid = next(S.begin(), w/2);
        if(i >= w)
        {
            S.insert(num);
            tempErase.push(num);
            cout << *mid << " ";
            S.erase(tempErase.front());
            tempErase.pop();
        }
    }
    return 0;
}