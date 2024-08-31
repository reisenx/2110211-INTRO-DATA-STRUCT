#include<iostream>
#include<set>
using namespace std;
int n, MIN, MAX;
set<int> A;
int main ()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        if(i == 0)
        {
            MIN = temp;
            MAX = temp;
        }
        if(temp > MAX) MAX = temp;
        else if(temp < MIN) MIN = temp;
        A.insert(temp);
    }
    if(MIN < 1 || MAX > n) cout << "NO";
    else if(A.size() != n) cout << "NO";
    else cout << "YES";
}