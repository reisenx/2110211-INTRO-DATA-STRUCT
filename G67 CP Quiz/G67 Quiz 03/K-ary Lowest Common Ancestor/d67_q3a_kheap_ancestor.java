import java.util.Scanner;

public class d67_q3a_kheap_ancestor
{
    public static void main(String[] args)
    {
        Scanner Scanner = new Scanner(System.in);
        int N = Scanner.nextInt();
        int K = Scanner.nextInt();
        int p = Scanner.nextInt();
        int q = Scanner.nextInt();

        while(p != q)
        {
            while(p > q) { p = (p-1)/K; }
            while(q > p) { q = (q-1)/K; }
        }
        System.out.println(p);
    }
}