#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void VectorSort(vector<int> &v)
{
    sort(v.begin(), v.end());
}
void ReversedVector(vector<int> &v)
{
    vector<int> NEW;
    for(int i = v.size()-1; i>=0; i--)
    {
        NEW.push_back(v[i]);
    }
    v = NEW;
}
void ReversedVectorSort(vector<int> &v)
{
    VectorSort(v);
    ReversedVector(v);
}
void RemoveData(vector<int> &v, int index)
{
    v.erase(v.begin() + index);
}

int main()
{
    string command;
    int value, Q;
    vector<int> v;

    cin >> Q;
    while(Q--)
    {
        cin >> command;
        if(command == "pb")
        {
            cin >> value;
            v.push_back(value);
        }
        else if(command == "sa")
        {
            VectorSort(v);
        }
        else if(command == "sd")
        {
            ReversedVectorSort(v);
        }
        else if(command == "r")
        {
            ReversedVector(v);
        }
        else if(command == "d")
        {
            cin >> value;
            RemoveData(v, value);
        }
    }

    // Output
    for(auto &x : v)
    {
        cout << x << " ";
    }
}