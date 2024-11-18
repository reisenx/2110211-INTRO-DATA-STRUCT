#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "queue.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int N, K;

  cin >> N >> K;

  CP::queue<int> q;
  
  std::vector<size_t> pos;
  for (int i = 1; i <= N; i++)
  {
    int x;

    cin >> x;
    q.push(x);
  }

  for (int i = 1; i <= K; ++i) {
    int x;

    cin >> x;
    pos.push_back(x);
  }

  q.remove_many(pos);
  q.print();
}
