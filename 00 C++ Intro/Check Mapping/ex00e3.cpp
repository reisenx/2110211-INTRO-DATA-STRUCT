#include<iostream>
#include<set>
using namespace std;
int n;
bool isPermutation = true;
set<int> S;
int main ()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input numbers
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        // If num < 1, so S is not a permutation
        if(num < 1) { isPermutation = false; break; }
        // If num > 1, so S is not permutation
        if(num > n) { isPermutation = false; break; }
        // Insertion to a set return a pair<iterator, bool>
        // boolean item is false if the insertion is not successful (Duplicate detected)
        auto data = S.insert(num);
        if(!data.second) { isPermutation = false; break; }
    }
    if(isPermutation) cout << "YES";
    else cout << "NO";
    return 0;
}