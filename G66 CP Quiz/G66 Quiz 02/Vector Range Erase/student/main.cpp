#include <iostream>
#include <vector>
#include "vector.h"
#include "student.h"

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    CP::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }

    vector<pair<CP::vector<int>::iterator, CP::vector<int>::iterator>> pos;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        pos.push_back({ v.begin() + a, v.begin() + b });
    }

    v.range_erase(pos);
    for (auto &i: v) {
        cout << i << "\n";
    }
}