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

if(namecount <= K):
    print(min(name2vote.values()))
else:
    vote2num = {}
    for name, vote in name2vote.items():
        if(vote not in vote2num):
            vote2num[vote] = 1
        else:
            vote2num[vote] += 1
    vote2num = sorted(vote2num.items())[::-1]
    
    total = 0
    for vote,num in vote2num:
        total += num
        if(total >= K):
            print(vote)
            break