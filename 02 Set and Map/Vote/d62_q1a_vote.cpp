#include<iostream>
#include<map>
using namespace std;
int N,K,uniqueName = 0;
map<string,int> name2vote;
map<int,int> vote2count;
int main()
{
    // Input
    cin >> N >> K;
    while(N--)
    {
        // Input name
        string name;
        cin >> name;

        // Manage data in vote2name, uniqueName and vote2count
        if(name2vote.find(name) == name2vote.end())
        {
            // Add name in name2vote
            name2vote[name] = 1;
            // Increase uniqueName by 1
            uniqueName++;
            // Manage vote2count[1]
            if(vote2count.size() == 0) vote2count[1] = 1;
            else vote2count[1]++;
        }
        else
        {
            // Add vote in name2vote
            name2vote[name]++;
            // Decrease vote2count[score] by 1 ('score' is an old vote)
            int score = name2vote[name];
            vote2count[score]--;
            // Increase vote2count[score+1] by 1
            if(vote2count.find(score+1) == vote2count.end()) vote2count[score+1] = 1;
            else vote2count[score+1]++;
        }
    }

    // Output
    // Case 1: uniqueName <= K (Output the lowest score)
    if(uniqueName <= K) cout << (vote2count.begin())->first;
    // Case 2: uniqueName > K
    else
    {
        // Loop find the score until sumCount >= K
        int sumCount = 0;
        for(auto it = vote2count.rbegin(); it != vote2count.rend(); it++)
        {
            sumCount += it->second;
            if(sumCount >= K) { cout << it->first; break; }
        }
    }
    return 0;
}