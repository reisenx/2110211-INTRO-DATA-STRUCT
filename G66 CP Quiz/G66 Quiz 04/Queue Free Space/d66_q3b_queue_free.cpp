#include<iostream>
using namespace std;
int n;
long long int mCap = 1, mSize = 0;

int main()
{
    // this will make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input amount of Operations
    cin >> n;
    while(n--)
    {
        // Input type of operation (t), amount of data (k)
        int t,k;
        cin >> t >> k;
        // Operation Type 0: push 'k' elements into a queue
        if(!t) mSize += k;
        // Operation Type 1: pop 'k' elements out of a queue
        if(t) mSize -= k;
        // Double mCap until mCap > mSize
        while(mCap < mSize) { mCap *= 2; }
    }
    // Output the queue's free space
    cout << mCap - mSize;
}