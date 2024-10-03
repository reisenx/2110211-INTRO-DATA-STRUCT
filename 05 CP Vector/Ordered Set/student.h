#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    // Create a vector as a union vector
    vector<T> v;
    // Create a set to check if the element is duplicate or not
    set<T> check;
    // Adding element from vector A
    for(auto &x : A)
    {
        // check.insert(x) return pair<iterator, boolean>
        // iterator is an iterator pointing at x in the set
        // boolean is true if the insertion is success
        // So if check.insert(x).second is true, it is not a duplicate element 
        if(check.insert(x).second) v.push_back(x);
    }
    // Adding element from vector B
    for(auto &x : B) { if(check.insert(x).second) v.push_back(x); }
    // Returns a union vector
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    // Create a vector as a intersection vector
    vector<T> v;
    // Convert vector B to a set
    set<T> setB = set(B.begin(), B.end());
    // Find intersection vector
    for(auto &x : A)
    {
        // If an element exist in setB, push_back it to intersection vector
        if(setB.find(x) != setB.end()) v.push_back(x);
    }
    // Returns a intersection vector
    return v;
}
