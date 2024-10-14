import java.util.*;

public class ds03_heap_order
{
    public static void main(String[] args)
    {
        Scanner Scanner = new Scanner(System.in);
        ArrayList<Student> students = new ArrayList<Student>();
        int N = Scanner.nextInt();
        int K = Scanner.nextInt();
        for(int i = 0; i < N; i++)
        {
            String name = Scanner.next();
            int score = Scanner.nextInt();
            students.add(new Student(name, score));
        }
        Scanner.close();
        Collections.sort(students);
        for(int i = 0; i < K; i++)
        {
            System.out.println(students.get(i));
        }
    }
}

class Student implements Comparable<Student>
{
    private String name;
    private int score;
    public Student(String name, int score)
    {
        this.name = name;
        this.score = score;
    }
    
    public int compareTo(Student other)
    {
        if(this.score < other.score) return 1;
        if(this.score > other.score) return -1;
        return this.name.compareTo(other.name);
    }
    
    public String toString() { return this.name + " " + this.score; }

    public String getName() { return this.name; }
    public int getScore() { return this.score; }

}