import java.util.Scanner;

public class d57_q0_remove_even
{
    public static void main(String[] args)
    {
        // Input Array
        Scanner Scanner = new Scanner(System.in);
        int n = Scanner.nextInt();
        int[] items = new int[n+5];
        for(int i=0; i<n; i++)
        {
            items[i] = Scanner.nextInt();
        }
        int a = Scanner.nextInt();
        int b = Scanner.nextInt();
        Scanner.close();

        // Modify Array
        int[] new_items = new int[n+5];
        int index = 0;
        for(int i=0; i<n; i++)
        {
            if(i<a || i>b)
            {
                new_items[index] = items[i];
                index++;
            }
            else if(i%2 == 1)
            {
                new_items[index] = items[i];
                index++;
            }
        }

        // Output
        for(int i=0; i<index; i++)
        {
            System.out.printf("%d ", new_items[i]);
        }
    }
}
