#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N,M;
vector<int> shoes;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    while(N--)
    {
        int temp;
        cin >> temp;
        shoes.push_back(temp);
    }
    sort(shoes.begin(), shoes.end());

    while(M--)
    {
        int foot;
        cin >> foot;
        vector<int>::iterator it = lower_bound(shoes.begin(), shoes.end(), foot);
        if(it == shoes.end())
        {
            cout << *(it - 1) << " "; 
        }
        else if(it == shoes.begin())
        {
            cout << *it <<  " ";
        }
        else if( abs(foot - *it) <= abs(foot - *(it - 1)) )
        {
            cout << *it << " ";
        }
        else
        {
            cout << *(it - 1) << " ";
        }
    }
}
