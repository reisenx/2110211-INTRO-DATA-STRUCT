import java.util.Scanner;

public class ds00_reverse
{
    public static void main(String[] args)
    {
        // Input nums array
        Scanner Scanner = new Scanner(System.in);
        int n = Scanner.nextInt();
        int[] nums = new int[n+5];
        for(int i=0; i<n; i++)
        {
            nums[i] = Scanner.nextInt();
        }
        int a = Scanner.nextInt();
        int b = Scanner.nextInt();
        Scanner.close();

        // Find reversed array
        int[] NEW = new int[n+5];
        System.arraycopy(nums, 0, NEW, 0, a);
        int index = b;
        for(int i=a; i<=b; i++)
        {
            NEW[i] = nums[index];
            index--;
        }
        System.arraycopy(nums, b+1, NEW, b+1, n - (b+1));
        
        // Output
        for(int i=0; i<n; i++)
        {
            System.out.printf("%d ", NEW[i]);
        }
    }
}
