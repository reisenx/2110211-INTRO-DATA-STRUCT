#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> A;

int main()
{
    // Input vector A
    cin >> N >> M;
    while(N--)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    // Check if the vector A has 2 value that A[i] + A[j] = sum
    // Find sum - A[i] in vector A from index A.begin()+i+1 to A.end()
    while(M--)
    {
        int sum;
        bool found = false;
        cin >> sum;
        for(int i = 0; i < A.size(); i++)
        {
            if( find(A.begin()+i+1, A.end(), sum - A[i]) != A.end() )
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}