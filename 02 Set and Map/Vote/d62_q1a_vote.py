name2vote = {}
namecount = 0
N,K = [int(e) for e in input().split()]
for i in range(N):
    name = input()
    if(name not in name2vote):
        name2vote[name] = 1
        namecount += 1
    else:
        name2vote[name] += 1

scores = list(name2vote.values())
scores.sort(reverse = True)
if(len(scores) < K):
    print(scores[-1])
else:
    print(scores[K-1])