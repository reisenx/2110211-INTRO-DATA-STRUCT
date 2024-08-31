N = int(input())
A = [int(e) for e in input().split()]
if(min(A) < 0 or max(A) > N):
    print("NO")
elif(len(set(A)) != N):
    print("NO")
else:
    print("YES")