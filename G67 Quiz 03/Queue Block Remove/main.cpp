#include "queue.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    std::string s;
    CP::queue<int>q;
    int qy=0;
    while(true) {
        qy++;
        cin >> s;
        if(s[0] == 's') {
            cout << q.size() << '\n';
        }
        else if(s[0] == 'u') {
            int X;
            cin >> X;
            q.push(X);
        }
        else if(s[0] == 'o') {
            q.pop();
        }
        else if(s[0] == 'f') {
            cout << q.front() << '\n';
        }
        else if(s[0] == 'B') {
            int X, Y;
            cin >> X >> Y;
            q.block_remove(X, Y);
        }
        else if(s[0] == 'q') {
            break;
        }
        else if(s[0] == 'b') {
            cout << q.back() << '\n';
        }
    }
}