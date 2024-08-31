#include<iostream>
#include<map>
using namespace std;
int N,K, namecount = 0;
map<string,int> name2vote;
map<int,int> vote2num;
int main()
{
    cin >> N >> K;
    while(N--)
    {
        string name;
        if(name2vote.find(name) == name2vote.end())
        {
            name2vote[name] = 1;
            namecount += 1;
        }
        else
        {
            name2vote[name] += 1;
        }
    }

    for(auto it = name2vote.begin(); it != name2vote.end(); it++)
    {
        int vote = *it->second;
        if(name2vote.find(vote) != name2vote.end())
        {
            vote2num[vote] = 1;
        }
        else
        {
            vote2num[vote]++;
        }
    }
}