#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> NEW(v);
    int position = it - v.begin();
    int start, stop;
    start = max(0, position - k);
    stop = min(int(NEW.size()), position + k + 1);
    NEW.erase(NEW.begin() + start, NEW.begin() + stop);
    return NEW;
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
    vector<string> result = punch(v, v.begin() + j, k);
    for(auto &x : result)
    {
        cout << x << endl;
    }
}
