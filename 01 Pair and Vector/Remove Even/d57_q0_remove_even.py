n = int(input())
items = input().strip().split()
a,b = [int(e) for e in input().strip().split()]
edit = []
for i in range(a,b+1):
    if(i%2 == 1):
        edit.append(items[i])
print(" ".join(items[:a] + edit + items[b+1:]))