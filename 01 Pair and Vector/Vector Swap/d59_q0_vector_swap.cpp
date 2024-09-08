#include <iostream>
#include <vector>
using namespace std;
void vector_swap(vector<int> &v1, vector<int> &v2, int start1, int end1, int start2, int end2) 
{
    // Copy vector 'v1' and 'v2' to new vectors
    vector<int> NEW1(v1), NEW2(v2);
    
    // Get the item from index 0 to end1
    NEW1.resize(start1);
    // push_back the item from index start2 to end2
    for(int i = start2; i < end2; i++) { NEW1.push_back(v2[i]); }
    // push_back the item from index end1 to v1.size()
    for(int i = end1; i < v1.size(); i++) { NEW1.push_back(v1[i]); }

    // Get the item from index 0 to end2
    NEW2.resize(start2);
    // push_back the item from index start1 to end1
    for(int i = start1; i < end1; i++) { NEW2.push_back(v1[i]); }
    // push_back the item from index end2 to v2.size()
    for(int i = end2; i < v2.size(); i++) {NEW2.push_back(v2[i]); }

    // Overwrite vector 'v1' and 'v2' to new value
    v1 = NEW1;
    v2 = NEW2;
}

int main()
{
    //read input
    int n,c;
    vector<int> v1,v2;
    cin >> n; //number of v1
    for (int i = 0;i < n;i++) {
        cin >> c;
        v1.push_back(c);
    }
    cin >> n; //number of v2
    
    for (int i = 0;i < n;i++) {
        cin >> c;
        v2.push_back(c);
    }

    int s1,e1,s2,e2; //position
    cin >> s1 >> e1 >> s2 >> e2;

    //call the function
    vector_swap(v1,v2,s1,e1,s2,e2);

    //display content of the stack
    cout << "v1 has " << v1.size() << endl;
    for (auto &x : v1) { cout << x << " "; }
    cout << endl;

    //display content of the stack
    cout << "v2 has " << v2.size() << endl;
    for (auto &x : v2) { cout << x << " "; }
    cout << endl;
}