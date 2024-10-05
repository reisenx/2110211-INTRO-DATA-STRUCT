n = int(input())
for i in range(n):
    mFront, mSize, mCap, last, correction = map(int,input().split())
    if(mSize > mCap or last >= mCap or mFront >= mCap or last != (mFront+mSize) % mCap):
        if(correction == 0): print("WRONG")
        if(correction == 1): print("WRONG", (last + mCap - mSize) % mCap)
        if(correction == 2): print("WRONG", ((mCap + last) - mFront) % mCap)
        if(correction == 3):
            if(mFront < last): print("WRONG", last+1)
            else: print("WRONG", (mSize + mFront) - last)
        if(correction == 4): print("WRONG", (mFront + mSize) % mCap)
    else:
        print("OK")