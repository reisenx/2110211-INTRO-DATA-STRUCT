#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    // Copy vector 'v'
    vector<string> NEW(v);
    // Find start and stop erase index
    int start = max(0, int(it-v.begin()-k));
    int stop = min(int(v.size()), int(it-v.begin()+k+1));
    // Erase vector 'NEW'
    NEW.erase(NEW.begin() + start, NEW.begin() + stop);
    // Return new vector
    return NEW;
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for(auto &x : result) {
        cout << x << endl;
    }
}
