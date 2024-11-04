import sys
N,K = map(int, sys.stdin.readline().split())
p,q = map(int, sys.stdin.readline().split())
while(p != q):
    while(p > q):
        p = (p-1)//K
    while(q > p):
        q = (q-1)//K
sys.stdout.write(str(p))