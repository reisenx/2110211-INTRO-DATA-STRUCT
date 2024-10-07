#include "stack.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	CP::stack<int> stk;
	CP::stack<std::string> stk2;
	int M;
	std::string MStr;

	int dataType;
	int query = 0;
	cin >> dataType;
	std::string type;
	while(true) {
		query++;
		cin >> type;
		if(type=="s") {
			if(dataType==1)
				cout << stk.size() << '\n';
			else if(dataType==2)
				cout << stk2.size() << '\n';
		}
		else if(type=="tp") {
			if(dataType == 1) {
				cin >> M;
				stk.push(M);
			}
			else if(dataType == 2) {
				cin >> MStr;
				stk2.push(MStr);
			}
		}
		else if(type=="to") {
			if(dataType==1) {
				stk.pop();
			}
			else if(dataType==2)
				stk2.pop();
		}
		else if(type=="tt") {
			if(dataType == 1) {
				cout << stk.top() << '\n';
			}
			else if(dataType == 2) {
				cout << stk2.top() << '\n';
			}
		}
		else if(type=="bp") {
			if(dataType == 1) {
				cin >> M;
				stk.push_bottom(M);
			}
			else if(dataType == 2) {
				cin >> MStr;
				stk2.push_bottom(MStr);
			}
		}
		else if(type=="bo") {
			if(dataType==1)
				stk.pop_bottom();
			else if(dataType==2)
				stk2.pop_bottom();
		}
		else if(type=="bt") {
			if(dataType == 1) {
				cout << stk.bottom() << '\n';
			}
			else if(dataType == 2) {
				cout << stk2.bottom() << '\n';
			} 
		}
		else if(type=="q") {
			break;
		}
	}
}