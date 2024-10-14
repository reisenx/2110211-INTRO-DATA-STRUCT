import sys
nodes, ancestor = map(int, sys.stdin.readline().split())
descendant = [ancestor]

current = 0
while(True):
    left_child = 2*descendant[current] + 1
    right_child = left_child + 1
    if(left_child >= nodes): break
    descendant.append(left_child)
    if(right_child >= nodes): break
    descendant.append(right_child)
    current += 1

sys.stdout.write(str(len(descendant)) + "\n")
sys.stdout.write(" ".join(map(str, descendant)))