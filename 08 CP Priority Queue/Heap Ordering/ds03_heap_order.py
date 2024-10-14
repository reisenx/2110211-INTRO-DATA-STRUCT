import sys
class Student:
    def __init__(self, name:str, score:int) -> None:
        self.name = name
        self.score = score
    def __lt__(self, other) -> bool:
        if(self.score == other.score):
            return self.name < other.name
        return self.score > other.score
    def __str__(self) -> str:
        return self.name + " " + str(self.score) + "\n"
N,K = map(int, sys.stdin.readline().split())
students = []
for _ in range(N):
    name,score = sys.stdin.readline().strip().split()
    students.append(Student(name, int(score)))
students.sort()
for i in range(K):
    sys.stdout.write(str(students[i]))