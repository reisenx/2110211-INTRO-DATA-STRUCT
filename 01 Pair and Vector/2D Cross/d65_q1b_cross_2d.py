import sys
row,col = map(int,sys.stdin.readline().strip().split())
r1,r2,c1,c2 = map(int,sys.stdin.readline().strip().split())
for r in range(row):
    data = sys.stdin.readline().strip().split()
    if(r1 <= r <= r2):
        continue
    print(" ".join(data[:c1] + data[c2+1:]))