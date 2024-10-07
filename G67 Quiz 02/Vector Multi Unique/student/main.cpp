#include <iostream>
#include "vector.h"
#include "student.h"
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    CP::vector <int> vec;
    while (true) {
        char opr;
        cin >> opr;

        if (opr == 'p') {
            cout << vec.size() << '\n';
            for (auto v : vec) cout << v << ' ';
            cout << '\n';
        }
        else if (opr == 'a') {
            int X, Y;
            cin >> X >> Y;

            vec.insert(vec.begin() + X, Y);
        }
        else if (opr == 'u') {
            int n;
            cin >> n;

            vector<CP::vector <int>::iterator> itrs;
            for (int i = 0; i < n; i++) {
                int X;
                cin >> X;

                itrs.push_back(vec.begin() + X);
            }
            vec.uniq(itrs);
        }
        else { // opr == 'q'
            break;
        }
    }
    return 0;
}
