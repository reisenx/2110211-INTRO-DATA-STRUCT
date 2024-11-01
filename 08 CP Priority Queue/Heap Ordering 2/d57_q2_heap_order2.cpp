#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Student
{
    public:
        // Class Properties
        int score;
        string name;
        // Constructor methods
        Student(string name, int score) : name(name), score(score) {}
        // Operator '<' Overloading
        // - Priority queue sorted by score in descending order
        // - Priority queue sorted by name in ascending order 
        bool operator<(const Student &other) const
        {
            if(this->score == other.score) return this->name > other.name;
            return this->score < other.score;
        }
};


int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input number of students (N) and number of output (K)
    int N,K;
    cin >> N >> K;
    priority_queue<Student> students;
    // Input student details
    while(N--)
    {
        string name;
        int n, score = 0;
        // Input name
        cin >> name >> n;
        // Find a sum of a score
        while(n--)
        {
            int temp;
            cin >> temp;
            score += temp;
        }
        // Create an object
        students.push(Student(name, score));
    }
    // Output
    while(K--)
    {
        cout << students.top().name << " " << students.top().score << endl;
        students.pop();
    }
    return 0;
}