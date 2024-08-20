N = int(input())
subject2score = {}
prof2score = {}
for i in range(N):
    subject, prof, score = input().strip().split()
    score = int(score)
    
    if(subject not in subject2score):
        subject2score[subject] = [score]
    else:
        subject2score[subject].append(score)
    
    if(prof not in prof2score):
        prof2score[prof] = [score]
    else:
        prof2score[prof].append(score)

subject2avg = {}
prof2avg = {}
for subject, scores in subject2score.items():
    subject2avg[subject] = sum(scores)/len(scores)
for prof, scores in prof2score.items():
    prof2avg[prof] = sum(scores)/len(scores)

subject2avg = sorted(subject2avg.items())
prof2avg = sorted(prof2avg.items())
for subject, score in subject2avg:
    print(subject, "{:.2f}".format(round(score, 2)))
for prof, score in prof2avg:
    print(prof, "{:.2f}".format(round(score, 2)))