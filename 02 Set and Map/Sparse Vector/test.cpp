#include<iostream>
#include<map>
using namespace std;
map<int,int> v;
int main()
{
    v[2] = 99;
    v[5] = 100;
    v[10] = 101;
    v[11] = 102;
    v[20] = 103;
    auto it = v.rbegin();
    // cout << it->first;
    while(it != v.rend() && it->first >= 5)
    {
        int key = it->first, val = it->second;
        v[key + 1] = val;
        cout << "(" << it->first << ", " << it->second << ") ";
        // v.erase(key);
        // cout << "(" << it->first << ", " << it->second << ") ";
        // it++;
        cout << "(" << it.base()->first << ", " << it.base()->second << ")" << endl;
    }
    v[5] = 999;
    cout << "RESULT" << endl;
    for(auto &x : v) { cout << "(" << x.first << ", " << x.second << ")" << endl;  }
}