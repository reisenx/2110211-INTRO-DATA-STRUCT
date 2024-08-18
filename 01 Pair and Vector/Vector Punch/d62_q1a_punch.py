n, it, k = [int(e) for e in input().split()]
items = []
for i in range(n):
    items.append(input())
print("Result after punch")
print( "\n".join(items[ : max(0,it-k)] + items[it+k+1 :]) )