#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v,int a,int b)
{
    vector<int> NEW;
    // Get data from vector v in index 0 to a-1
    for(int i = 0; i < a; i++)
    {
        NEW.push_back(v[i]);
    }
    // Get data from vector v in index a to b in reverse order
    for(int i = b; i >= a; i--)
    {
        NEW.push_back(v[i]);
    }
    // Get data from vector v in index b+1 to v.size()
    for(int i = b+1; i < v.size(); i++)
    {
        NEW.push_back(v[i]);
    }
    //Replace vector
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
}