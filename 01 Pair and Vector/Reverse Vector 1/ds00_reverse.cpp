#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v,int a,int b)
{
    // Copy vector 'v' to vector 'NEW'
    vector<int> NEW(v);
    // Get value from index 0 to a-1
    NEW.resize(a);
    // push_back value from index a to b in reversed order
    for(int i = b ; i >= a; i--) { NEW.push_back(v[i]); }
    // push_back the remaining value
    for(int i = b+1 ; i < v.size(); i++) { NEW.push_back(v[i]); }
    // Overwrite new value to vector 'v'
    v = NEW;
}

int main() {
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;

    //call function
    reverse(v,a,b);

    //display content of the vector
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}