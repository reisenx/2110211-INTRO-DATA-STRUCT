import java.util.Scanner;

public class d62_q3a_heap_node_relation
{
    public static boolean checkDescendant(int a, int b)
    {
        if(a == 0) return true;
        while(b > a)
        {
            b--;
            b /= 2;
        }
        if(a == b) return true;
        return false;
    }
    public static void main(String[] args)
    {
        Scanner Scanner = new Scanner(System.in);
        int n = Scanner.nextInt();
        int m = Scanner.nextInt();
        for(int i = 0; i < m; i++)
        {
            int a = Scanner.nextInt();
            int b = Scanner.nextInt();
            if(a == b)
            {
                System.out.println("a and b are the same node");
            }
            else if(a < b && checkDescendant(a,b))
            {
                System.out.println("a is an ancestor of b");
            }
            else if(b < a && checkDescendant(b,a))
            {
                System.out.println("b is an ancestor of a");
            }
            else
            {
                System.out.println("a and b are not related");
            }
        }
        Scanner.close();
    }
}