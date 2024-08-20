M,N = [int(e) for e in input().split()]
A = set([int(e) for e in input().split()])
B = set([int(e) for e in input().split()])
C = sorted(list(A.intersection(B)))
C = [str(item) for item in C]
print(" ".join(C))