N,M,K = map(int,input().split())
A,SUM = [],[]
for row in range(N):
    A.append( list(map(int, input().split())) )
    temp = []
    for col in range(M):
        if(row == 0 and col == 0):
            temp.append(A[0][0])
        elif(row == 0):
            temp.append(temp[col-1] + A[0][col])
        elif(col == 0):
            temp.append(SUM[row-1][0] + A[row][0])
        else:
            temp.append(SUM[row-1][col] + temp[col-1] - SUM[row-1][col-1] + A[row][col])
    SUM.append(temp)

for i in range(K):
    r1,c1,r2,c2 = map(int,input().split())
    if(r1 == 0 and c1 == 0):
        print(SUM[r2][c2])
    elif(r1 == 0):
        print(SUM[r2][c2] - SUM[r2][c1-1])
    elif(c1 == 0):
        print(SUM[r2][c2] - SUM[r1-1][c2])
    else:
        print(SUM[r2][c2] - SUM[r1-1][c2] - SUM[r2][c1-1] + SUM[r1-1][c1-1])