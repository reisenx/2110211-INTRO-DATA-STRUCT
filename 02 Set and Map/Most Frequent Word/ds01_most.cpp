#include<iostream>
#include<map>
using namespace std;
int N, max_count = 0;
map<string, int> name2vote;
int main()
{
    cin >> N;
    while(N--)
    {
        string name;
        cin >> name;
        if(name2vote.find(name) == name2vote.end())
        {
            name2vote[name] = 1;
        }
        else
        {
            name2vote[name] += 1;
        }

        if(name2vote[name] > max_count)
        {
            max_count = name2vote[name];
        }
    }
    
    string max_name = "";
    for(auto it = name2vote.rbegin(); it != name2vote.rend(); it++)
    {
        if(it->second == max_count)
        {
            max_name = it->first;
            break;
        }
    }
    cout << max_name << " " << max_count;
}