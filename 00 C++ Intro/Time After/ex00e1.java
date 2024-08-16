import java.util.Scanner;

public class ex00e1
{
    public static void main(String[] args)
    {
        Scanner Scanner = new Scanner(System.in);
        int h = Scanner.nextInt();
        int m = Scanner.nextInt();
        int x = Scanner.nextInt();
        Scanner.close();

        m += x;
        h = (h + m/60) % 24;
        m %= 60;
        System.out.printf("%02d %02d",h,m);
    }
}