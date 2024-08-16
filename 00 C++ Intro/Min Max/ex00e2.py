N,M = [int(e) for e in input().strip().split()]
R = int(input())
mat = []
for row in range(N):
    data = [int(e) for e in input().strip().split()]
    mat.append(data)
for i in range(R):
    r1,c1,r2,c2 = [int(e) for e in input().strip().split()]
    if(r1 > r2 or c1 > c2):
        print("INVALID")
    elif((r1 < 1 and r2 < 1) or (r1 > N and r2 > N)):
        print("OUTSIDE")
    elif((c1 < 1 and c2 < 1) or (c1 > M and c1 > M)):
        print("OUTSIDE")
    else:
        r1 = max(1, r1)
        c1 = max(1, c1)
        r2 = min(N, r2)
        c2 = min(M, c2)
        mx = mat[r1-1][c1-1]
        for row in range(r1-1, r2):
            for col in range(c1-1, c2):
                if(mat[row][col] > mx):
                    mx = mat[row][col]
        print(mx)