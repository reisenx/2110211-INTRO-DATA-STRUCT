Q = int(input())
vector = []
for i in range(Q):
    command = input().split()
    if(command[0] == "pb"):
        vector.append(int(command[1]))
    elif(command[0] == "sa"):
        vector.sort()
    elif(command[0] == "sd"):
        vector.sort(reverse=True)
    elif(command[0] == "r"):
        vector.reverse()
    elif(command[0] == "d"):
        vector.pop(int(command[1]))
vector = [str(item) for item in vector]
print(" ".join(vector))
