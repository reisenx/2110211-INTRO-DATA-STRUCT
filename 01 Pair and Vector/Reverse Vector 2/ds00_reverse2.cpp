#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b)
{
    // Convert iterator variable into an integer
    int A = a - v.begin();
    int B = b - v.begin();
    // Copy vector 'v' to a new vector
    vector<int> NEW(v);
    // Get the value from index 0 to a-1
    NEW.resize(A);
    // push_back the value from index a to b-1 in reversed order
    for(int i = B-1; i >= A; i--) { NEW.push_back(v[i]); }
    // push_back the remaining value
    for(int i = B; i < v.size(); i++) { NEW.push_back(v[i]); }
    // Overwrite new value to vector 'v'
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
    return 0;
}