import sys

class Student:
    def __init__ (self, name, score):
        self.name = name
        self.score = score
    def __lt__ (self, rhs):
        if(self.score == rhs.score):
            return self.name < rhs.name
        return self.score > rhs.score
    def __str__(self):
        return self.name + " " + str(self.score) + "\n"

N,K = map(int, sys.stdin.readline().split())
students = []
for _ in range(N):
    score = 0
    data = sys.stdin.readline().strip().split()
    for i in range(2, int(data[1])+2):
        score += int(data[i])
    students.append(Student(data[0], score))
students.sort()

for i in range(K):
    sys.stdout.write(str(students[i]))