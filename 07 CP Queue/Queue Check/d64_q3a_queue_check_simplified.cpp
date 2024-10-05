#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    while(n--)
    {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        if(mSize > mCap || last >= mCap || mFront >= mCap || last != (mFront+mSize) % mCap)
        {
            if(correction == 0) cout << "WRONG" << endl;
            if(correction == 1) cout << "WRONG " << (last + mCap - mSize) % mCap << endl;
            if(correction == 2) cout << "WRONG " << ((mCap + last) - mFront) % mCap << endl;
            if(correction == 3)
            {
                if(mFront < last) cout << "WRONG " << last + 1 << endl;
                else cout << "WRONG " << (mSize + mFront) - last << endl;
            }
            if(correction == 4) cout << "WRONG " << (mFront + mSize) % mCap << endl;
        }
        else cout << "OK" << endl;
    }
}