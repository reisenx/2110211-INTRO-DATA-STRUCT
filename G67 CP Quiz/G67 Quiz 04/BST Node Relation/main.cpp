#include <iostream>
#include "map_bst.h"
#include "student.h"

using std::cin;
using std::cout;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    CP::map_bst<int, int> m;
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x] = x;
    }

    int a, b;
    cin >> a >> b;

    auto result = m.node_relation(m.find(a), m.find(b));
    cout << result << std::endl;

    return 0;
}
