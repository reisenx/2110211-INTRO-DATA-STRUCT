N = int(input())
name2count = {}
max_count = 0
for i in range(N):
    name = input()
    if(name not in name2count):
        name2count[name] = 1
    else:
        name2count[name] += 1
    
    if(name2count[name] > max_count):
        max_count = name2count[name]

max_names = []
for name,count in name2count.items():
    if(count == max_count):
        max_names.append(name)
max_names.sort()
print(max_names[-1], max_count)