#include <iostream>
#include "stack.h"
#include "student.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  CP::stack<int> a;

  for (int i = 1; i <= n; i++) {
    a.push(i);
  }

  std::vector<std::stack<int>> output;
  a.v_split(output, k);

  for (int i = 0; i < output.size(); i++) {
    std::stack<int> temp;
    while (!output[i].empty()) {
      temp.push(output[i].top());
      output[i].pop();
    }

    std::cout << "Output[" << i << "] =  ";
    while (!temp.empty()) {
      std::cout << temp.top() << " ";
      temp.pop();
    }
    std::cout << "\n";
  }
}
