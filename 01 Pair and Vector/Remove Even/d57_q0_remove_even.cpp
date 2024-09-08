#include <iostream>
#include <vector>
using namespace std;

void remove_even(vector<int> &v, int a, int b)
{
    // Copy vector 'v' to a new vector
    vector<int> NEW(v);
    // Get the value from index 0 to a
    NEW.resize(a);
    // Remove even value in even index in range [a,b]
    // it means push_back the value in odd index in range [a,b]
    for(int i = (a+1)-(a%2); i <= (b-1)+(b%2); i += 2) { NEW.push_back(v[i]); }
    // push_back the remaining index
    for(int i = b+1; i < v.size(); i++) { NEW.push_back(v[i]); }
    // Overwrite a new value to vector 'v'
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
    return 0;
}