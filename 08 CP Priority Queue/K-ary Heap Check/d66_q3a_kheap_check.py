import sys
tests = int(sys.stdin.readline())
for t in range(tests):
    nodes, K = map(int, sys.stdin.readline().split())
    data = sys.stdin.readline().split()
    isHeap = True
    isEnd = False
    for n in range(nodes):
        for i in range(1,K+1):
            child = K*n + i
            if(child >= nodes):
                isEnd = True
                break
            if(int(data[n]) < int(data[child])):
                isHeap = False
                break
        if((not isHeap) or isEnd):
            break
    if(isHeap):
        sys.stdout.write("true\n")
    else:
        sys.stdout.write("false\n")