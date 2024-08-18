#include <iostream>
#include <vector>
using namespace std;

void remove_even(vector<int> &v, int a, int b)
{
    vector<int> NEW;
    for(int i = 0; i < v.size(); i++)
    {
        if(i<a || i>b)
        {
            NEW.push_back(v[i]);
        }
        else if(i%2 == 1)
        {
            NEW.push_back(v[i]);
        }
    }
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
    remove_even(v,a,b);

    //display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}