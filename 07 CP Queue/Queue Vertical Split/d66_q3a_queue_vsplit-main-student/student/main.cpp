#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "queue.h"
#include "student.h"

using std::cin;
using std::cout;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;

  cin >> n >> k;
  CP::queue<int> q;
  std::vector<std::queue<int>> v;
  for (int i = 1; i <= n; i++)
  {
    q.push(i);
  }

  q.v_split(v, k);

  for (int i = 0; i < v.size(); i++)
  {
    cout << "[";
    while (!v[i].empty())
    {
      cout << v[i].front() << ", ";
      v[i].pop();
    }
    cout << "]\n";
  }
}
