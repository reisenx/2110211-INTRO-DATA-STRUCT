#include<iostream>
using namespace std;

/* Create a function that validate the input
1.) Check mSize <= mCap
2.) Check last, mFront < mCap
3.) Check last = (mFront + mSize) % mCap
NOTE: If mSize = mCap, last = mFront */
bool queueValid(const int &mFront, const int &mSize, const int &mCap, const int &last)
{
    if(mFront < 0 || mSize < 0 || mCap < 0 || last < 0) return false;
    if(mSize > mCap) return false;
    if(last >= mCap || mFront >= mCap) return false;
    return last == (mFront+mSize) % mCap;
}

int main()
{
    // This will make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input amount of inputs
    int n;
    cin >> n;
    while(n--)
    {
        // Input values
        int mFront, mSize, mCap, last, correction, result;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        // In case of the input is not valid
        if(!queueValid(mFront, mSize, mCap, last))
        {
            if(correction == 0) cout << "WRONG" << endl;

            /* mFront correction
            mFront is to jump backwards from last mSize times */
            if(correction == 1)
            {
                result = (last + mCap - mSize) % mCap;
                cout << "WRONG " << result << endl;
            }

            /* mSize correction
            Case 1: mFront == last
            > mSize = 0 (smallest as possible)
            Case 2: mFront < last --> [0,1,2,3,--]
            > mSize = last - mFront
            Case 3: mFront > last --> [2,3,--,--,0,1]
            > last = (mCap + last) % mCap
            > mSize = (mCap + last) - mFront */
            if(correction == 2)
            {
                if(mFront == last) result = 0;
                else if(mFront < last) result = last - mFront;
                else result = (mCap + last) - mFront;
                cout << "WRONG " << result << endl;
            }

            /* mCap correction
            Case 1: mFront == last --> [0,1,2,3]
            > mCap = mSize
            Case 2: mFront < last --> [0,1,2,3,--]
            > mCap = last+1
            Case 3: mFront > last --> [2,3,--,--,0,1]
            > last = (mCap + last) % mCap
            > mSize = (mCap + last) - mFront
            > mCap = (mSize + mFront) - last */
            if(correction == 3)
            {
                if(mFront == last) result = mSize;
                else if(mFront < last) result = last+1;
                else result = (mSize + mFront) - last;
                cout << "WRONG " << result << endl;
            }

            /* last correction
            last is to jump forwards from mFront mSize times */
            if(correction == 4)
            {
                result = (mFront + mSize) % mCap;
                cout << "WRONG " << result << endl;
            }
        }
        // In case of the input is valid
        else cout << "OK" << endl;
    }
}