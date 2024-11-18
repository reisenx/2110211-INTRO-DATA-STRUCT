#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
  int data;
  node *left_child;
  node *right_sibling;
  node() : data(0), left_child(nullptr), right_sibling(nullptr) {}
  node(int v, node *l, node *r) : data(v), left_child(l), right_sibling(r) {}
};

#include "student.h"

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  node *root = nullptr;
  while (true)
  {
    string cmd;
    cin >> cmd;
    if (cmd == "q")
      break;
    if (cmd == "d")
    {
      std::cout << "depth = " << depth(root) << "\n";
    }
    else if (cmd == "a")
    {
      int value, code;
      cin >> value;
      node *it = root;
      while (true)
      {
        std::cin >> code;
        if (code < 0)
        {
          if (root == nullptr)
          {
            root = new node(value, nullptr, nullptr);
            cout << "set root to " << root->data << endl;
          }
          else
          {
            if (code == -1)
            {
              if (it->left_child != nullptr)
              {
                cout << "OVERWRITE!!!" << endl;
                exit(1);
              }
              it->left_child = new node(value, nullptr, nullptr);
              cout << "add left child at " << it->data << endl;
            }
            else if (code == -2)
            {
              if (it->right_sibling != nullptr)
              {
                cout << "OVERWRITE!!!" << endl;
                exit(1);
              }
              it->right_sibling = new node(value, nullptr, nullptr);
              cout << "add right sibling at " << it->data << endl;
            }
          }
          break;
        }
        else
        {
          if (code == 0)
            it = it->left_child;
          if (code > 0)
          {
            for (int i = 0; i < code; i++)
              it = it->right_sibling;
          }
        }
      }
    }
  }
}
