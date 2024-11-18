import sys;
nodes, currentNode = map(int, sys.stdin.readline().split())
current = 0
descendants = [currentNode]
while(True):
    left_child = 2*descendants[current] + 1
    right_child = 2*descendants[current] + 2
    
    if(left_child >= nodes): break
    descendants.append(left_child)
    if(right_child >= nodes): break
    descendants.append(right_child)
    
    current += 1

sys.stdout.write(str(nodes - len(descendants)) + "\n")
i = 0
for node in range(nodes):
    if(i < len(descendants)):
        if(node != descendants[i]): sys.stdout.write(str(node) + " ")
        else: i += 1
    else:
        sys.stdout.write(str(node) + " ")