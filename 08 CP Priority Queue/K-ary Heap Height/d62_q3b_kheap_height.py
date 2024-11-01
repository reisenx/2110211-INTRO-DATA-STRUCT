import sys
nodes = 0
height = 0
n,K = map(int, sys.stdin.readline().split())
if(K == 1):
    sys.stdout.write(str(n-1))
else:
    while(True):
        nodes += K**height
        if(nodes >= n): break
        height += 1
    sys.stdout.write(str(height))