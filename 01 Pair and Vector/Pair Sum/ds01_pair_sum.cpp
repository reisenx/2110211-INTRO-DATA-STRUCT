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
    // Sort vector A
    sort(A.begin(), A.end());

    // Check if the vector A has 2 value that A[i] + A[j] = sum
    // Using Two Pointer Technique
    while(M--)
    {
        int i = 0, j = A.size()-1;
        int sum;
        bool found = false;
        cin >> sum;
        while(i < j)
        {
            if(A[i] + A[j] == sum)
            {
                found = true;
                break;
            }
            else if(A[i] + A[j] > sum)
            {
                j--;
            }
            else if(A[i] + A[j] < sum)
            {
                i++;
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