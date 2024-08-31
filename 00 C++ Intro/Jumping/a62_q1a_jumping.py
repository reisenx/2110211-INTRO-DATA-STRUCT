N = int(input())
A = [int(e) for e in input().split()]
SUM = []
for i in range(N):
    if(i == 0):
        SUM.append(A[i])
    elif(i == 1):
        SUM.append(SUM[i-1] + A[i])
    elif(i == 2):
        SUM.append(max(SUM[i-2], SUM[i-1]) + A[i]) 
    else:
        SUM.append(max(SUM[i-3], SUM[i-2], SUM[i-1]) + A[i])
print(SUM[-1])