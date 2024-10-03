import java.util.Scanner;

public class d62_q2c_wasted_space
{
    public static void main(String args[])
    {
        Scanner Scanner = new Scanner(System.in);
        double n = Scanner.nextDouble();
        Scanner.close();
        System.out.println(Math.round(Math.pow(2, Math.ceil(Math.log(n)/Math.log(2))) - n));
    }
}