#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator, int>> &multiply) {
    sort(multiply.begin(), multiply.end());
    vector<int> NEW;
    int INDEX = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(INDEX < multiply.size())
        {
            int VALUE = *(multiply[INDEX].first);
            int COUNT = multiply[INDEX].second + 1;
            if(v[i] == VALUE)
            {
                NEW.insert(NEW.end(), COUNT, VALUE);
                INDEX += 1;
            }
            else NEW.push_back(v[i]);
        }
        else NEW.push_back(v[i]);
    }
    v = NEW;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }
    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}