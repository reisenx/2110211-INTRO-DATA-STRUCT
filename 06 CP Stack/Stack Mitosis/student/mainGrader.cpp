#include <iostream>
#include <vector>
#include "student.h"

template <typename T>
void test()
{
    int n, t;
    std::cin >> n >> t;

    std::vector<CP::stack<T>> st(n);
    for (int i = 0; i < n; ++i)
    {
        int sz;
        T x;
        std::cin >> sz;
        for (int j = 0; j < sz; j++)
        {
            std::cin >> x;
            st[i].push(x);
        }
    }

    while (t--)
    {
        int op;
        std::cin >> op;
        int v;
        std::cin >> v;
        if (op == 0)
        {
            st[v].print();
        }

        if (op == 1)
        {
            int a, b;
            std::cin >> a >> b;

            st[v].mitosis(a, b);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int type;
    std::cin >> type;
    if (type == 0)
    {
        test<int>();
    }
    else
    {
        test<std::string>();
    }
    std::cout << "PASSWORD: q34p98lhkzjsxdbvkab.s,rjgnhb;sliedrhygp;9s83yeh4;tlksdf\n";
}
