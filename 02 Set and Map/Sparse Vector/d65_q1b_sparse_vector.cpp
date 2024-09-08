#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
    // Create a iterator at the end of the map which is v.rbegin()
    auto it = v.rbegin();
    // Loop until the index is less than pos or reached v.rend()
    while(it != v.rend() && it->first >= pos)
    {
        // Get the old key and value
        int key = it->first, val = it->second;
        // Create a new pair in map (now the iterator is pointing at a new item)
        v[key + 1] = val;
        // Move an iterator to the left
        it++;
        // We can't delete an item with reversed iterator (such as v.rbegin()), so we use base() to convert the iterator to normal iterator
        v.erase(next(it).base());
    }
    // Insert the new value
    v[pos] = value;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }
    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n";
    }
}