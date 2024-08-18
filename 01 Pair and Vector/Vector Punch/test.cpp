#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> NEW(v);
    int position = it - v.begin();
    int start, stop;
    start = max(0, position - k);
    stop = min(int(v.size()), position + k);
    NEW.erase(v.begin() + start, v.begin() + stop);
    return NEW;
}
vector<int> punch2(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> NEW(v);
    int position = it - v.begin();
    int start, stop;
    start = max(0, position - k);
    stop = min(int(v.size()), position + k);
    NEW.erase(v.begin() + start, v.begin() + stop);
    return {start,stop};
}

int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    
    for(int i = 0; i < n; i++)
    {
    cin >> v[i];
    }
    
    cout << "Result after punch" << endl;
    vector<int> result2 = punch2(v, v.begin() + j, k);
    for(auto &x : result2)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for(auto &x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}
