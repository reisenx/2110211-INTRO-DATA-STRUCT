import java.util.Scanner;

public class d62_q1a_punch
{
    public static void main(String[] args)
    {
        // Input Value
        Scanner Scanner = new Scanner(System.in);
        int n = Scanner.nextInt();
        int it = Scanner.nextInt();
        int k = Scanner.nextInt();
        String[] items = new String[105];
        for(int i = 0; i < n; i++)
        {
            items[i] = Scanner.next();
        }
        Scanner.close();

        // Find erase range
        int start = Math.max(0, it-k);
        int stop = Math.min(n, it+k);

        // Output
        System.out.println("Result after punch");
        for(int i=0; i<n; i++)
        {
            if(i < start || i > stop)
            {
                System.out.println(items[i]);
            }
        }
    }
}
