#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N,K;
map<string,int> name2vote;
vector<int> scores;
int main()
{
    cin >> N >> K;
    while(N--)
    {
        string name;
        cin >> name;
        if(name2vote.find(name) == name2vote.end()) name2vote[name] = 1;
        else name2vote[name] += 1;
    }
    for(auto it = name2vote.begin(); it != name2vote.end(); it++)
    {
        scores.push_back(it->second);
    }
    sort(scores.begin(), scores.end());
    reverse(scores.begin(), scores.end());
    if(scores.size() < K) cout << scores[scores.size()-1];
    else cout << scores[K-1];
}