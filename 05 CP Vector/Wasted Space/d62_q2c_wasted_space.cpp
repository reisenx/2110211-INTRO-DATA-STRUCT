#include<iostream>
#include<cmath>
using namespace std;
int n;
int main()
{
    // Input number of mSize
    cin >> n;
    /* Since ensureCapacity() in CP::vector double itself when mSize is going to exceed mCap
    So mCap can be only 1,2,4,8,16,32,... or 2^n
    To find the mCap by mSize we need to find smallest number n that makes 2^n >= mSize
    We can find it by 2^n = mSize and we got n = log2(mSize)
    But n is an integer so we need to use ceil function, therefore n = ceil(log2(mSize))
    So we got mCap = 2*ceil(log2(mSize))
    Finally, we got Wasted Space = mCap - mSize = 2*ceil(log2(mSize)) - mSize
    */
    long long int result = pow(2,ceil(log2(n))) - n;
    cout << result;
}