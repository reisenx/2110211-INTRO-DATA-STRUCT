#include <bits/stdc++.h>
#include "map_bst.h"
#include "student.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  CP::map_bst<int, int> m;
  int N, x;

  std::cin >> N;

  while (N--) {
    std::cin >> x;
    m[x] = 0;
  }

  std::cout << m.sum_leaves_depth() << std::endl;
}