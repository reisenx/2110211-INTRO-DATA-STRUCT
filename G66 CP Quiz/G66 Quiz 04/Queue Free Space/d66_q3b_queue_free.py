mSize, mCap = 0,1
n = int(input())
for i in range(n):
    t,k = map(int,input().split())
    if(not t):
        mSize += k
    if(t):
        mSize -= k
    while(mCap < mSize):
        mCap *= 2
print(mCap - mSize)