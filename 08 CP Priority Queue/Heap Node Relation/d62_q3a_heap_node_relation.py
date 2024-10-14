import sys
def checkDescendant(a:int, b:int) -> bool:
    if(a == 0):
        return True
    while(b > a):
        b = (b-1)//2
    if(a == b):
        return True
    return False

n,m = map(int, sys.stdin.readline().split())
for _ in range(m):
    a,b = map(int, sys.stdin.readline().split())
    if(a == b):
        sys.stdout.write("a and b are the same node\n")
    elif(a < b and checkDescendant(a,b)):
        sys.stdout.write("a is an ancestor of b\n")
    elif(b < a and checkDescendant(b,a)):
        sys.stdout.write("b is an ancestor of a\n")
    else:
        sys.stdout.write("a and b are not related\n")