#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b)
{
    int front = a - v.begin();
    int end = b - v.begin() - 1;
    vector<int> NEW;
    // Get data from vector v in index 0 to a-1
    for(int i = 0; i < front; i++)
    {
        NEW.push_back(v[i]);
    }
    // Get data from vector v in index a to b in reverse order
    for(int i = end; i >= front; i--)
    {
        NEW.push_back(v[i]);
    }
    // Get data from vector v in index b+1 to v.size()
    for(int i = end+1; i < v.size(); i++)
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
    for (int i = 0; i < n; i++) 
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    
    //call function
    reverse(v,v.begin()+a,v.begin()+b+1);
    
    //display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}