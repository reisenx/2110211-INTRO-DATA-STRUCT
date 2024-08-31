#include<iostream>
#include<map>
using namespace std;

int main()
{
    int N;
    map<string, int> V;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        if(V.find(temp) == V.end())
        {
            V[temp] = 1;
        }
        else V[temp] += 1;
    }

    for(auto it = V.begin(); it != V.end(); it++)
    {
        if(it->second > 1)
        {
            cout << it->first  << " " << it->second << endl;
        }
    }
}