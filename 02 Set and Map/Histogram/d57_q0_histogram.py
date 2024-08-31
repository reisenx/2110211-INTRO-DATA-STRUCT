count = {}
N = int(input())
for i in range(N):
    temp = input().strip()
    if(temp not in count):
        count[temp] = 1
    else:
        count[temp] += 1
count = sorted(count.items())

for name, cnt in count:
    if(cnt > 1):
        print(name, cnt)