import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class d57_q2_heap_order2
{
    public static void main(String[] args)
    {
        Scanner Scanner = new Scanner(System.in);
        ArrayList<Student> students = new ArrayList<Student>();
        int N = Scanner.nextInt();
        int K = Scanner.nextInt();
        for(int i = 0; i < N; i++)
        {
            int score = 0;
            String name = Scanner.next();
            int n = Scanner.nextInt();
            for(int j = 0; j < n; j++)
            {
                int temp = Scanner.nextInt();
                score += temp;
            }
            students.add(new Student(name, score));
        }
        Collections.sort(students);
        Scanner.close();
        for(int i = 0; i < K; i++)
        {
            System.out.println(students.get(i));
        }
    }
}

class Student implements Comparable<Student>
{
    private int score;
    private String name;
    public Student(String name, int score)
    {
        this.name = name;
        this.score = score;
    }
    public int compareTo(Student other)
    {
        if(this.score > other.score) return -1;
        if(this.score < other.score) return 1;
        return this.name.compareTo(other.name);
    }
    public String toString()
    {
        return this.name + " " + this.score;
    }
}