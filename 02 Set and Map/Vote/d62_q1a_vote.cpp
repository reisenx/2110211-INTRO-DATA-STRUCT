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
    // Input
    cin >> N >> K;
    while(N--)
    {
        // Input name
        string name;
        cin >> name;
        // Increase vote by 1
        if(name2vote.find(name) == name2vote.end()) name2vote[name] = 1;
        else name2vote[name] += 1;
    }
    // Loop get score in each item in name2vote and push_back to scores 
    for(auto &x : name2vote) { scores.push_back(x.second); }
    // Sort the scores
    sort(scores.begin(), scores.end());

    // Case 1: Candidates is less than K
    if(scores.size() < K) cout << scores[0];
    // Case 2: Candidates is more than K
    else cout << scores[scores.size() - K];
}