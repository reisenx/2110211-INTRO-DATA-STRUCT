#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> a;
int main()
{
    // Make std::cin and std:: cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input vector and sort in ascending order
    cin >> N >> M;
    a.resize(N);
    for(int i = 0; i < N; i++) { cin >> a[i]; }
    sort(a.begin(), a.end());

    while(M--)
    {
        /* Two Pointers Technique
        Given pointer 'i' is at the front of the array
        Given pointer 'j' is at the end of the array
        */
        int i = 0, j = N-1;
        bool isFound = false;

        // Input sum
        int SUM;
        cin >> SUM;

        // Check if pair sum exists (until pointer i is equal to j)
        while(i < j)
        {
            // Case 1: The sum is too high, move the pointer 'j' to the left
            if(a[i] + a[j] > SUM) j--;
            // Case 2: The sum is too low, move the pointer 'i' to the right
            else if(a[i] + a[j] < SUM) i++;
            // Case 3: Pair sum exists
            else { isFound = true; break; }
        }

        // Output
        if(isFound) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}