#include <stdexcept>
#include <iostream>
#include "unordered_map.h"
#include "student.h"
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);

  CP::unordered_map<int,int> m;
  int n;
  std::cin >> n;
  for (int i = 0;i < n;i++) {
    int x;
    std::cin >> x;
    m[x] = x;
    std::cout << "max bucket length = " << m.max_bucket_length() << std::endl;
  }
}

