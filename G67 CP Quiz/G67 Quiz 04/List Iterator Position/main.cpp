#include <iostream>
#include "list.h"
#include "student.h"
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    CP::list<int> l1, l2;
    int n1, p1, n2, p2;
    cin >> n1 >> p1 >> n2 >> p2;

    for (int i = 0; i < n1; i++) l1.push_back(69420);
    for (int i = 0; i < n2; i++) l2.push_back(69420);

    CP::list<int>::iterator it1a = l1.begin(), it1b = l1.begin(), it1c = l1.end();
    if (n1 == p1) it1b = l1.end();
    else if (p1 > n1 * 3 / 2) it1b = NULL;
    else {
        if (n1 < p1) while (l1.size() <= p1) l1.push_back(69420);
        for (int i = 0; i < p1; i++) it1b++;
        while (l1.size() > n1) l1.pop_back();
    }

    CP::list<int>::iterator it2a = l2.begin(), it2b = l2.begin(), it2c = l2.end();
    if (n2 == p2) it2b = l2.end();
    else if (p2 > n2 * 3 / 2) it2b = NULL;
    else {
        if (n2 < p2) while (l2.size() <= p2) l2.push_back(69420);
        for (int i = 0; i < p2; i++) it2b++;
        while (l2.size() > n2) l2.pop_back();
    }

    cout << "l1 with begin() of l1 : " << l1.data_iterator(it1a) << '\n';
    cout << "l1 with p1 of l1 : " << l1.data_iterator(it1b) << '\n';
    cout << "l1 with end() of l1 : " << l1.data_iterator(it1c) << '\n';
    cout << "l1 with begin() of l2 : " << l1.data_iterator(it2a) << '\n';
    cout << "l1 with p2 of l2 : " << l1.data_iterator(it2b) << '\n';
    cout << "l1 with end() of l2 : " << l1.data_iterator(it2c) << '\n';
    cout << "l2 with begin() of l1 : " << l2.data_iterator(it1a) << '\n';
    cout << "l2 with p1 of l1 : " << l2.data_iterator(it1b) << '\n';
    cout << "l2 with end() of l1 : " << l2.data_iterator(it1c) << '\n';
    cout << "l2 with begin() of l2 : " << l2.data_iterator(it2a) << '\n';
    cout << "l2 with p2 of l2 : " << l2.data_iterator(it2b) << '\n';
    cout << "l2 with end() of l2 : " << l2.data_iterator(it2c) << '\n';
    return 0;
}
