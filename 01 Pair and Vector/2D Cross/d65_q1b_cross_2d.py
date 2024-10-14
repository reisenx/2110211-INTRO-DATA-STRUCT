import sys
row,col = map(int,sys.stdin.readline().split())
r1,r2,c1,c2 = map(int,sys.stdin.readline().split())
for r in range(row):
    data = sys.stdin.readline().split()
    if(r1 <= r <= r2):
        continue
    sys.stdout.write(" ".join(data[:c1] + data[c2+1:]) + "\n")